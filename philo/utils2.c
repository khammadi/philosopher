/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammadi <khammadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:01:41 by khammadi          #+#    #+#             */
/*   Updated: 2023/08/12 17:01:43 by khammadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>
#include <stdint.h>

int	error(void)
{
	write(1, "Error", 5);
	return (0);
}

void	printmessage(uint64_t tm, t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->data->print);
	printf("%lu %d %s", tm, philo->id, s);
	pthread_mutex_unlock(&philo->data->print);
}

int	check_eat(t_data *data, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&philo->data->nbeat);
		if (philo->data->num_philo_eat == philo[i].counteat && !philo[i].nb)
		{
			philo->var++;
			philo[i].nb = 1;
		}
		pthread_mutex_unlock(&philo->data->nbeat);
		if (philo->var == philo->data->num_philo)
			return (1);
		i++;
	}
	return (0);
}

int	check_die(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&philo->data->die);
		if (getime() - data->tm - philo->last_meal > data->time_die)
		{
			pthread_mutex_unlock(&philo->data->die);
			pthread_mutex_lock(&philo->data->print);
			printf("%lu %d %s\n", getime() - philo->data->tm,
				philo[i].id, "is die");
			return (1);
		}
		pthread_mutex_unlock(&philo->data->die);
		i++;
	}
	return (0);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		usleep(1000);
	while (1)
	{
		pthread_mutex_lock(philo->left_fork);
		printmessage(getime() - philo->data->tm, philo, "take left fork\n");
		pthread_mutex_lock(philo->right_fork);
		eat_take(philo);
		pthread_mutex_lock(&philo->data->nbeat);
		philo->counteat++;
		pthread_mutex_unlock(&philo->data->nbeat);
		pthread_mutex_lock(&philo->data->die);
		philo->last_meal = getime() - philo->data->tm;
		pthread_mutex_unlock(&philo->data->die);
		ft_usleep(philo->data->time_eat);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		printmessage(getime() - philo->data->tm, philo, "sleeping\n");
		ft_usleep(philo->data->time_sleep);
		printmessage(getime() - philo->data->tm, philo, "thinking\n");
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammadi <khammadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:58:19 by khammadi          #+#    #+#             */
/*   Updated: 2023/08/12 17:00:21 by khammadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

int	init_data(char **av, t_data *k, t_philo *philo, int ac)
{
	int	i;

	philo->last_meal = 0;
	if (k->num_philo <= 0)
		return (1);
	k->time_die = ft_atoi(av[2]);
	k->time_eat = ft_atoi(av[3]);
	k->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		k->num_philo_eat = ft_atoi(av[5]);
		if (k->num_philo_eat <= 0)
			return (1);
	}
	else
		k->num_philo_eat = -1;
	k->fork = malloc(sizeof(pthread_mutex_t) * k->num_philo);
	i = -1;
	while (++i < k->num_philo)
		pthread_mutex_init(&k->fork[i], NULL);
	pthread_mutex_init(&k->nbeat, NULL);
	pthread_mutex_init(&k->print, NULL);
	pthread_mutex_init(&k->die, NULL);
	return (0);
}

void	init_data2(t_philo *philo, t_data *k)
{
	int	i;

	i = -1;
	while (++i < k->num_philo)
	{
		philo[i].id = i;
		philo[i].left_fork = &(k->fork[i]);
		philo[i].right_fork = &(k->fork[(i + 1) % k->num_philo]);
		philo[i].data = k;
		philo[i].counteat = 0;
		philo[i].nb = 0;
	}
	philo->var = 0;
}

uint64_t	getime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((uint64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

void	ft_usleep(uint64_t time)
{
	uint64_t	curentime;

	curentime = getime();
	while (getime() - curentime < time)
		usleep(1000);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;
	int		i;

	if ((ac != 5 && ac != 6) || ft_check_args(av) == 0)
		return (error());
	data = malloc(sizeof(t_data));
	data->num_philo = ft_atoi(av[1]);
	philo = malloc(sizeof(t_philo) * data->num_philo);
	if (init_data(av, data, philo, ac) == 1)
		return (1);
	init_data2(philo, data);
	data->tm = getime();
	i = -1;
	while (++i < data->num_philo)
		pthread_create(&philo[i].thread, NULL, &routine, &philo[i]);
	while (1)
	{
		if (check_die(philo, data))
			return (1);
		if (check_eat(data, philo))
			return (1);
	}
}

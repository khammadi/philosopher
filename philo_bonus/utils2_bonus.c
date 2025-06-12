/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammadi <khammadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:03:51 by khammadi          #+#    #+#             */
/*   Updated: 2023/08/12 17:35:45 by khammadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

int	init_data(char **av, t_data *k, t_philo *philo, int ac)
{
	(void)philo;
	if (k->num_philo <= 0)
		return (1);
	k->time_die = ft_atoi(av[2]);
	k->time_eat = ft_atoi(av[3]);
	k->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
	{
		k->num_philo_eat = ft_atoi(av[5]);
		if (k->num_philo <= 0)
			return (1);
	}
	else
		k->num_philo_eat = -1;
	return (0);
}

void	init_datat(t_philo *philo, t_data *k)
{
	int		i;
	sem_t	*print;

	sem_unlink("print");
	print = sem_open("print", O_CREAT, 0644, 1);
	i = -1;
	while (++i < k->num_philo)
	{
		philo[i].id = i;
		philo[i].data = k;
		philo[i].counteat = 0;
		philo[i].print = print;
	}
	sem_unlink("forks");
	philo->data->fork = sem_open("forks", O_CREAT, 0644, k->num_philo);
}

void	printmessage(uint64_t tm, t_philo *philo, char *s)
{
	sem_wait(philo->print);
	printf("%lu %d %s", tm, philo->id, s);
	sem_post(philo->print);
}

uint64_t	getime(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((uint64_t)(tv.tv_sec * 1000 + tv.tv_usec / 1000));
}

uint64_t	test(struct timeval test)
{
	return ((uint64_t)(test.tv_sec * 1000 + test.tv_usec / 1000));
}

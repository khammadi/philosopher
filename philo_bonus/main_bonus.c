/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammadi <khammadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:03:05 by khammadi          #+#    #+#             */
/*   Updated: 2023/08/12 17:24:15 by khammadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	ft_usleep(uint64_t time)
{
	uint64_t	curentime;

	curentime = getime();
	while (getime() - curentime < time)
		usleep(810);
}

void	*check_die(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		if (getime() - test(philo->last_meal) > philo->data->time_die)
		{
			sem_wait(philo->print);
			printf("%lu %d %s\n", getime() - philo->data->tm,
				philo->id, "is die");
			exit(1);
		}
		usleep(1000);
	}
	return (NULL);
}

void	routine_func(t_data *data, t_philo *philo)
{
	pthread_create(&philo->thread, NULL, check_die, philo);
	while (1)
	{
		sem_wait(data->fork);
		printmessage(getime() - philo->data->tm, philo, "take fork\n");
		sem_wait(data->fork);
		printmessage(getime() - philo->data->tm, philo, "take fork\n");
		printmessage(getime() - philo->data->tm, philo, "is eating\n");
		gettimeofday(&philo->last_meal, NULL);
		ft_usleep(philo->data->time_eat);
		sem_post(data->fork);
		sem_post(data->fork);
		philo->counteat++;
		if (philo->counteat == philo->data->num_philo_eat)
			exit(0);
		printmessage(getime() - philo->data->tm, philo, "sleeping\n");
		ft_usleep(philo->data->time_sleep);
		printmessage(getime() - philo->data->tm, philo, "thinking\n");
	}
}

void	ft_kill(t_data *data, t_philo *philo)
{
	int	i;
	int	status;

	i = 0;
	while (i < data->num_philo)
	{
		waitpid(-1, &status, 0);
		if (status != 0)
		{
			i = -1;
			while (++i < data->num_philo)
				kill(philo[i].pid, SIGTERM);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		i;
	t_data	*data;
	t_philo	*philo;

	if ((ac != 5 && ac != 6) || ft_check_args(av) == 0)
		return (funerror());
	data = malloc(sizeof(t_data));
	data->num_philo = ft_atoi(av[1]);
	philo = malloc(sizeof(t_philo) * data->num_philo);
	data->tm = getime();
	if (init_data(av, data, philo, ac))
		return (1);
	init_datat(philo, data);
	i = 0;
	while (i < data->num_philo)
	{
		philo[i].pid = fork();
		if (philo[i].pid == 0)
		{
			gettimeofday(&philo[i].last_meal, NULL);
			routine_func(data, philo + i);
		}
		i++;
	}
	ft_kill(data, philo);
}

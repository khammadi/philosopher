/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammadi <khammadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:03:27 by khammadi          #+#    #+#             */
/*   Updated: 2023/08/12 17:10:28 by khammadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include<stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include<semaphore.h>
# include <stdint.h>
# include<pthread.h>
# include<signal.h>
# include<fcntl.h>
# include<sys/wait.h>

typedef struct data_s
{
	int			num_philo;
	uint64_t	time_die;
	uint64_t	time_eat;
	uint64_t	time_sleep;
	int			num_philo_eat;
	uint64_t	tm;
	sem_t		*fork;
}	t_data;

typedef struct philo_s
{
	pthread_t		thread;
	struct timeval	last_meal;
	int				id;
	int				counteat;
	int				nb;
	int				var;
	int				finish;
	sem_t			*last;
	sem_t			*die;
	int				pid;
	t_data			*data;
	sem_t			*print;
	sem_t			*lasmeal;
	sem_t			*idd;
}	t_philo;

int			ft_atoi(const char *str);
void		ft_kill(t_data *data, t_philo *philo);
int			init_data(char **av, t_data *k, t_philo *philo, int ac);
void		init_datat(t_philo *philo, t_data *k);
int			funerror(void);
void		printmessage(uint64_t tm, t_philo *philo, char *s);
uint64_t	getime(void);
uint64_t	test(struct timeval test);
void		ft_usleep(uint64_t time);
void		*check_die(void *arg);
void		routine_func(t_data *data, t_philo *philo);
int			ft_check_args(char **argv);
#endif
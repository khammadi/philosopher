/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammadi <khammadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:00:49 by khammadi          #+#    #+#             */
/*   Updated: 2023/08/12 17:00:57 by khammadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include "philo.h"
# include <unistd.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>
# include <stdint.h>
# include<fcntl.h>
# include<sys/wait.h>

typedef struct data_s
{
	int						num_philo;
	uint64_t				time_die;
	uint64_t				time_eat;
	uint64_t				time_sleep;
	int						num_philo_eat;
	uint64_t				tm;
	pthread_mutex_t			*fork;
	pthread_mutex_t			die;
	pthread_mutex_t			nbeat;
	pthread_mutex_t			print;
}	t_data;

typedef struct philo_s
{
	pthread_t		thread;
	uint64_t		last_meal;
	int				id;
	int				counteat;
	int				nb;
	int				var;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	int				finish;
	t_data			*data;
}	t_philo;

int			ft_atoi(const char *str);
void		*routine(void *arg);
int			check_die(t_philo *philo, t_data *data);
int			check_eat(t_data *data, t_philo *philo);
void		init_data2(t_philo *philo, t_data *k);
int			init_data(char **av, t_data *k, t_philo *philo, int ac);
uint64_t	getime(void);
void		ft_usleep(uint64_t time);
int			error(void);
void		eat_take(t_philo *philo);
void		printmessage(uint64_t tm, t_philo *philo, char *s);
int			ft_check_args(char **argv);
#endif
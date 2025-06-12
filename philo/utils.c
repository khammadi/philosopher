/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khammadi <khammadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 17:01:17 by khammadi          #+#    #+#             */
/*   Updated: 2023/08/12 17:01:21 by khammadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include<unistd.h>

static int	sp(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	size_t	n;

	s = 1;
	n = 0;
	i = sp(str);
	if (str[i] == '-')
	{
		s = s * (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	if (s == 1 && n > 9223372036854775807)
		return (-1);
	if (s == -1 && n > 9223372036854775807)
		return (0);
	return (s * n);
}

void	eat_take(t_philo *philo)
{
	printmessage(getime() - philo->data->tm, philo, "take right fork\n");
	printmessage(getime() - philo->data->tm, philo, "is eating\n");
}

int	ft_check_args(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] > '9' || argv[i][j] < '0')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

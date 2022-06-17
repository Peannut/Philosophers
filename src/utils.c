/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoukaddo <zoukaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:50:53 by zoukaddo          #+#    #+#             */
/*   Updated: 2022/06/17 02:05:52 by zoukaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	getime_usec(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000000 + tv.tv_usec);
}

int	init_mutex_forks(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->nbphilos)
	{
		if (pthread_mutex_init(&info->forks[i], NULL))
		{
			write(2, "Error init mutex\n", 17);
			return (1);
		}
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	long		number;

	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	number = 0;
	while (*str >= '0' && *str <= '9')
	{
		if (number > 2147483647)
			return (-1);
		number = number * 10 + *str - '0';
		str++;
	}
	return (number);
}

int	initializiginfo(t_info *info)
{
	info->forks = malloc(sizeof(pthread_mutex_t) * info->nbphilos);
	info->fork_status = malloc(sizeof(int) * info->nbphilos);
	memset(info->fork_status, FREE, sizeof(int) * info->nbphilos);
	if (!info->forks || !info->fork_status)
	{
		write(2, "Error: malloc failed\n", 21);
		return (1);
	}
	info->finished_philos = 0;
	info->end = 0;
	if (init_mutex_forks(info))
	{
		write(2, "Error: init mutex failed\n", 24);
		return (1);
	}
	info->start = getime_usec();
	return (0);
}

int	storeargs(int ac, char **av, t_info *info)
{
	if (ac != 5 && ac != 6)
	{
		write(2, "Invalid arguments\n", 18);
		return (0);
	}
	info->nbphilos = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_to_eat = ft_atoi(av[3]);
	info->time_to_sleep = ft_atoi(av[4]);
	info->must_eat = -1;
	if (ac == 6)
		info->must_eat = ft_atoi(av[5]);
	if (info->nbphilos < 1 || info->time_to_die < 1 || info->time_to_eat < 1 \
		|| info->time_to_sleep < 1 || info->must_eat < 1)
	{
		write(2, "Invalid arguments\n", 18);
		return (0);
	}
	return (1);
}

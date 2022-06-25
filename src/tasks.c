/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tasks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoukaddo <zoukaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:17:25 by zoukaddo          #+#    #+#             */
/*   Updated: 2022/06/24 01:07:17 by zoukaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philo *philo, char *msg)
{
	printf("%zu ms %d %s\n", (getime_usec() - philo->info->start) / 1000, \
		philo->num, msg);
}

void	ft_usleep(useconds_t time)
{
	size_t	t;

	t = getime_usec();
	while (getime_usec() - t < time)
		usleep(1);
}

void	eat_philo(t_philo *philo)
{
	while (1)
	{
		if (philo->info->fork_status[philo->r_fork] == FREE)
		{
			pthread_mutex_lock(&philo->info->forks[philo->r_fork]);
			pthread_mutex_lock(&philo->info->forks[philo->l_fork]);
			philo->info->fork_status[philo->r_fork] = LOCK;
			philo->info->fork_status[philo->l_fork] = LOCK;
			print_status(philo, "has taken a fork");
			print_status(philo, "has taken a fork");
			print_status(philo, "is eating");
			philo->last_eat = getime_usec();
			ft_usleep(philo->info->time_to_eat * 1000);
			pthread_mutex_unlock(&philo->info->forks[philo->r_fork]);
			pthread_mutex_unlock(&philo->info->forks[philo->l_fork]);
			philo->info->fork_status[philo->r_fork] = FREE;
			philo->info->fork_status[philo->l_fork] = FREE;
			break ;
		}
		else
			ft_usleep(30);
	}
}

void	philo_sleep(t_philo *philo)
{
	print_status(philo, "is sleeping");
	ft_usleep((philo->info->time_to_sleep * 1000));
}

void	philo_think(t_philo *philo)
{
	print_status(philo, "is thinking");
}

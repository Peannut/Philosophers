/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoukaddo <zoukaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 21:40:23 by zoukaddo          #+#    #+#             */
/*   Updated: 2022/06/25 02:12:23 by zoukaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/philo.h"

t_philo	*init_philo(t_info *info)
{
	t_philo	*philo;
	int		i;

	philo = malloc(info->nbphilos * sizeof(t_philo));
	if (!philo)
	{
		write(2, "Error malloc\n", 14);
		return (0);
	}
	i = 0; 
	while (i < info->nbphilos)
	{
		philo[i].num = i + 1;
		philo[i].info = info;
		philo[i].r_fork = i + 1;
		if (i == 0)
			philo[i].l_fork = info->nbphilos;
		else
			philo[i].l_fork = i;
		philo[i].last_eat = info->start;
		philo[i].num_eat = 0;
		i++;
	}
	return (philo);
}

void	*routine(void *av)
{
	while (1)
	{
		eat_philo((t_philo *)av);
		philo_sleep((t_philo *)av);
		philo_think((t_philo *)av);
	}
	return (NULL);
}

int	lunch_philos(pthread_t *threads, t_info *info, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < info->nbphilos)
	{
		if (pthread_create(&threads[i], NULL, routine, &philo[i]))
		{
			write(2, "Error occurring on the creation of thread\n", 42);
			return (1);
		}
		ft_usleep(100000);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		*philo;
	t_info		*info;
	pthread_t	*threads;

	info = malloc(sizeof(t_info));
	if (!info || !storeargs(ac, av, info) || initializiginfo(info))
		return (1);
	philo = init_philo(info);
	threads = malloc(info->nbphilos * sizeof(pthread_t));
	lunch_philos(threads, info, philo);
}

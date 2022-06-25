/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoukaddo <zoukaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 01:10:35 by zoukaddo          #+#    #+#             */
/*   Updated: 2022/06/24 01:15:18 by zoukaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	checkphilo(t_philo *philo)
{
	if ((getime_usec() - philo->last_eat) / 1000 > \
		(size_t)philo->info->time_to_die)
	{
		philo->info->end = 1;
		
	}
}

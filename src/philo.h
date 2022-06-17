/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zoukaddo <zoukaddo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:58:58 by zoukaddo          #+#    #+#             */
/*   Updated: 2022/06/17 19:45:21 by zoukaddo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef PHILO_H
# 	define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <pthread.h>

# define FREE 0
# define LOCK 1

typedef struct s_info
{
	int				nbphilos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				finished_philos;
	int				end;
	int				*fork_status;
	size_t			start;
	pthread_mutex_t	mtx_end;
	pthread_mutex_t	*forks;
}	t_info;

typedef struct s_philo
{
	t_info	*info;
	int		r_fork;
	int		l_fork;
	int		num;
	int		num_eat;
	size_t	last_eat;
}	t_philo;

int		ft_atoi(char *str);
int		storeargs(int ac, char **av, t_info *info);
int		initializiginfo(t_info *info);
void	eat_philo(t_philo *philo);

#endif 
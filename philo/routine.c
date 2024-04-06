/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:11:01 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/05 10:23:33 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_one_thread(t_philo *ph)
{
	while (1)
	{
		pthread_mutex_lock(&ph->l_fork);
		printf("%d %d has taken left fork\n",
			ft_get_current_time_diff(ph->table->start), ph->id);
		while (!ft_check_death(ph))
			;
		pthread_mutex_unlock(&ph->l_fork);
		if (ft_check_death(ph))
			break ;
	}
}

static void	ft_set_nbeat(t_philo *ph)
{
	if (ft_int_getter(&ph->table->nb_must_eat, &ph->table->data) != -1)
		ft_int_setter(&ph->nb_eat, ph->nb_eat + 1, &ph->table->data);
}

void	*ft_routine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(1500);
	while (1)
	{
		if (ft_check_death(ph))
			break ;
		else if (ft_int_getter(&ph->table->can_eat, &ph->table->data))
		{
			if (ph->table->nb_philo == 1)
			{
				ft_one_thread(ph);
				break ;
			}
			else if (ft_check_routine(ph))
			{
				ft_eat(ph);
				ft_set_nbeat(ph);
				ft_execute_end_routine(ph);
			}
		}
	}
	return (NULL);
}

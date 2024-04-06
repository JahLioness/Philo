/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:02:37 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/05 10:58:02 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_right_fork(t_philo *ph)
{
	pthread_mutex_lock(ph->r_fork);
	if (!ft_int_getter(&ph->table->is_dead, &ph->table->data))
	{
		pthread_mutex_lock(&ph->table->print);
		printf("%d %d has taken right fork\n",
			ft_get_current_time_diff(ph->table->start), ph->id);
		pthread_mutex_unlock(&ph->table->print);
	}
}

void	ft_left_fork(t_philo *ph)
{
	pthread_mutex_lock(&ph->l_fork);
	if (!ft_int_getter(&ph->table->is_dead, &ph->table->data))
	{
		pthread_mutex_lock(&ph->table->print);
		printf("%d %d has taken left fork\n",
			ft_get_current_time_diff(ph->table->start), ph->id);
		pthread_mutex_unlock(&ph->table->print);
	}
}

void	ft_eat(t_philo *ph)
{
	if (ft_int_getter(&ph->table->is_dead, &ph->table->data))
		return ;
	else if (ph->id % 2 == 0)
	{
		ft_left_fork(ph);
		ft_right_fork(ph);
	}
	else
	{
		ft_right_fork(ph);
		ft_left_fork(ph);
	}
	if (!ft_int_getter(&ph->table->is_dead, &ph->table->data))
	{
		pthread_mutex_lock(&ph->table->print);
		printf("%s%d %d is eating%s\n", GREEN,
			ft_get_current_time_diff(ph->table->start), ph->id, NC);
		pthread_mutex_unlock(&ph->table->print);
	}
	ft_get_time(&ph->last_meal);
	usleep(ph->table->time_to_eat * 1000);
	pthread_mutex_unlock(ph->r_fork);
	pthread_mutex_unlock(&ph->l_fork);
}

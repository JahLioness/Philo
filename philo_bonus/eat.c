/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:39:01 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/06 11:12:09 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_right_fork(t_philo *ph)
{
	sem_wait(ph->table->forks);
	if (!ft_long_getter(&ph->table->dead->__align, ph->table->data))
	{
		sem_wait(ph->table->print);
		printf("%d %d has taken a fork\n", ft_get_current_time_diff(ph->table->start), ph->id);
		sem_post(ph->table->print);
	}
}

static void	ft_left_fork(t_philo *ph)
{
	sem_wait(ph->table->forks);
	if (!ft_long_getter(&ph->table->dead->__align, ph->table->data))
	{
		sem_wait(ph->table->print);
		printf("%d %d has taken a fork\n", ft_get_current_time_diff(ph->table->start), ph->id);
		sem_post(ph->table->print);
	}
}

void	ft_eat(t_philo *ph)
{
	if (ft_long_getter(&ph->table->dead->__align, ph->table->data))
		return ;
	if (ph->id % 2 == 0)
	{
		ft_left_fork(ph);
		ft_right_fork(ph);
	}
	else
	{
		ft_right_fork(ph);
		ft_left_fork(ph);
	}
	if (!ft_long_getter(&ph->table->dead->__align, ph->table->data))
	{
		sem_wait(ph->table->print);
		printf("%s%d %d is eating%s\n", GREEN,
			ft_get_current_time_diff(ph->table->start), ph->id, NC);
		sem_post(ph->table->print);
	}
	ft_get_time(&ph->last_meal);
	usleep(ph->table->time_to_eat * 1000);
	sem_post(ph->table->forks);
	sem_post(ph->table->forks);
}

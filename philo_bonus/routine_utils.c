/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:45:03 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/06 12:05:14 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_check_death(t_philo *ph)
{
	if (ft_long_getter(&ph->table->dead->__align, ph->table->data)
		|| (ft_int_getter(&ph->nb_eat,
				ph->table->data) == ft_int_getter(&ph->table->nb_must_eat,
				ph->table->data) && ft_int_getter(&ph->table->nb_must_eat,
				ph->table->data) != -1))
		return (1);
	return (0);
}

int	ft_check_routine(t_philo *ph)
{
	if ((ft_int_getter(&ph->nb_eat, ph->table->data) >= 0
			&& ft_int_getter(&ph->nb_eat,
				ph->table->data) < ft_int_getter(&ph->table->nb_must_eat,
				ph->table->data)) || ft_int_getter(&ph->table->nb_must_eat,
			ph->table->data) == -1)
		return (1);
	return (0);
}

void	ft_execute_end_routine(t_philo *ph)
{
	if ((ft_int_getter(&ph->nb_eat,
				ph->table->data) < ft_int_getter(&ph->table->nb_must_eat,
				ph->table->data) || ft_int_getter(&ph->nb_eat,
				ph->table->data) == -1)
		&& !ft_long_getter(&ph->table->dead->__align, ph->table->data))
	{
		sem_wait(ph->table->print);
		printf("%d %d is sleeping\n",
			ft_get_current_time_diff(ph->table->start), ph->id);
		sem_post(ph->table->print);
		usleep(ft_int_getter(&ph->table->time_to_sleep, ph->table->data)
			* 1000);
		ft_think(ph);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:00:34 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/05 10:40:46 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_death(t_philo *ph)
{
	if (ft_int_getter(&ph->table->is_dead, &ph->table->data)
		|| (ft_int_getter(&ph->nb_eat,
				&ph->table->data) == ft_int_getter(&ph->table->nb_must_eat,
				&ph->table->data) && ft_int_getter(&ph->table->nb_must_eat,
				&ph->table->data) != -1))
		return (1);
	return (0);
}

int	ft_check_routine(t_philo *ph)
{
	if (((ft_int_getter(&ph->nb_eat, &ph->table->data) >= 0
				&& ft_int_getter(&ph->nb_eat,
					&ph->table->data) < ft_int_getter(&ph->table->nb_must_eat,
					&ph->table->data)) || ft_int_getter(&ph->table->nb_must_eat,
				&ph->table->data) == -1) && !ft_int_getter(&ph->table->is_dead,
			&ph->table->data))
		return (1);
	return (0);
}

void	ft_execute_end_routine(t_philo *ph)
{
	if (!ft_int_getter(&ph->table->is_dead, &ph->table->data)
		&& (ft_int_getter(&ph->nb_eat,
				&ph->table->data) < ft_int_getter(&ph->table->nb_must_eat,
				&ph->table->data) || ft_int_getter(&ph->nb_eat,
				&ph->table->data) == -1))
	{
		if (ft_int_getter(&ph->table->is_dead, &ph->table->data))
			return ;
		pthread_mutex_lock(&ph->table->print);
		printf("%d %d is sleeping\n",
			ft_get_current_time_diff(ph->table->start), ph->id);
		pthread_mutex_unlock(&ph->table->print);
		usleep(ft_int_getter(&ph->table->time_to_sleep, &ph->table->data)
			* 1000);
		ft_think(ph);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:47:02 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/24 13:44:25 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_think(t_philo *ph)
{
	int	time_to_think;

	if (ft_int_getter(&ph->table->is_dead, &ph->table->data))
		return ;
	time_to_think = 0;
	pthread_mutex_lock(&ph->table->print);
	printf("%d %d is thinking\n", ft_get_current_time_diff(ph->table->start),
		ph->id);
	pthread_mutex_unlock(&ph->table->print);
	if (ft_int_getter(&ph->table->time_to_eat,
			&ph->table->data) >= ft_int_getter(&ph->table->time_to_sleep,
			&ph->table->data))
		time_to_think = ft_int_getter(&ph->table->time_to_eat, &ph->table->data)
			- ft_int_getter(&ph->table->time_to_sleep, &ph->table->data) + 1;
	ft_sleep(time_to_think, ph->table);
}

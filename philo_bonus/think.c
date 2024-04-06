/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:55:34 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/06 11:13:07 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_think(t_philo *ph)
{
	int	time_to_think;
	
	if (ft_long_getter(&ph->table->dead->__align, ph->table->data))
		return ;
	time_to_think = 0;
	sem_wait(ph->table->print);
	printf("%d %d is thinking\n", ft_get_current_time_diff(ph->table->start), ph->id);
	sem_post(ph->table->print);
	if (ft_int_getter(&ph->table->time_to_eat,
			ph->table->data) >= ft_int_getter(&ph->table->time_to_sleep,
			ph->table->data))
		time_to_think = ft_int_getter(&ph->table->time_to_eat, ph->table->data)
			- ft_int_getter(&ph->table->time_to_sleep, ph->table->data) + 1;
	usleep(time_to_think * 1000);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:23:14 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/24 13:43:58 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_sleep(int time, t_table *table)
{
	struct timeval	now;
	int				current;
	int				time_passed;
	int				remain_time;

	ft_get_time(&now);
	current = ft_get_current_time_diff(now);
	while (ft_get_current_time_diff(now) - current <= time)
	{
		if (ft_int_getter(&table->is_dead, &table->data))
			break ;
		time_passed = ft_get_current_time_diff(now) - current;
		remain_time = time - time_passed;
		if (remain_time > 1000)
			usleep(1000);
		else
			while (ft_get_current_time_diff(now) - current <= time)
				usleep(50);
	}
}

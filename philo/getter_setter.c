/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:16:52 by ede-cola          #+#    #+#             */
/*   Updated: 2024/03/27 05:45:57 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_int_getter(int *value, pthread_mutex_t *mtx)
{
	int	ret;

	pthread_mutex_lock(mtx);
	ret = *value;
	pthread_mutex_unlock(mtx);
	return (ret);
}

void	ft_int_setter(int *value, int new_value, pthread_mutex_t *mtx)
{
	pthread_mutex_lock(mtx);
	*value = new_value;
	pthread_mutex_unlock(mtx);
}

void	ft_time_setter(struct timeval *time, pthread_mutex_t *mtx)
{
	pthread_mutex_lock(mtx);
	gettimeofday(time, NULL);
	pthread_mutex_unlock(mtx);
}

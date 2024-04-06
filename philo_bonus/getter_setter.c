/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_setter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:28:30 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/06 11:08:08 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_int_getter(int *value, sem_t *sem)
{
	int	ret;

	sem_wait(sem);
	ret = *value;
	sem_post(sem);
	return (ret);
}

long	ft_long_getter(long *value, sem_t *sem)
{
	int	ret;

	sem_wait(sem);
	ret = *value;
	sem_post(sem);
	return (ret);
}

void	ft_int_setter(int *value, int new_value, sem_t *sem)
{
	sem_wait(sem);
	*value = new_value;
	sem_post(sem);
}

void	ft_time_setter(struct timeval *time, sem_t *sem)
{
	sem_wait(sem);
	gettimeofday(time, NULL);
	sem_post(sem);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:13:48 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/05 10:14:10 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_mutex_ph_error(t_philo *ph, int i)
{
	while (--i >= 0)
		pthread_mutex_destroy(&ph[i].l_fork);
	printf("%sError: mutex init failed%s\n", RED, NC);
	return (1);
}

int	ft_ph_tread_error(t_philo *ph, int i)
{
	while (--i >= 0)
		pthread_detach(ph[i].thread);
	free(ph);
	printf("%sError: thread init failed%s\n", RED, NC);
	return (1);
}

int	ft_supervisor_error(pthread_t supervisor)
{
	pthread_detach(supervisor);
	printf("%sError: thread init failed%s\n", RED, NC);
	return (1);
}

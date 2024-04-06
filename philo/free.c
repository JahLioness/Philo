/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:18:17 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/05 10:58:11 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_free_mtx(t_table *table, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
		pthread_mutex_destroy(&ph[i].l_fork);
	free(ph);
	pthread_mutex_destroy(&table->data);
	pthread_mutex_destroy(&table->print);
}

void	ft_free_thread(t_table *table, t_philo *ph, pthread_t supervisor)
{
	int	i;

	i = 0;
	while (i < table->nb_philo)
	{
		pthread_join(ph[i].thread, NULL);
		i++;
	}
	ft_int_setter(&table->have_eat, 1, &table->data);
	pthread_join(supervisor, NULL);
}

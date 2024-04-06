/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:08:09 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/05 11:18:41 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_init_data(t_table *table, int ac, char **av)
{
	table->nb_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->nb_must_eat = -1;
	if (ac == 6)
		table->nb_must_eat = ft_atoi(av[5]);
	table->is_dead = 0;
	table->can_eat = 0;
	table->have_eat = 0;
	table->start.tv_sec = 0;
	table->start.tv_usec = 0;
	if (pthread_mutex_init(&table->data, NULL) != 0)
		return (1);
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return (1);
	return (0);
}

int	ft_init_philo(t_philo *ph, t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		ph[i].id = i + 1;
		ph[i].table = table;
		ph[i].last_meal = table->start;
		ph[i].nb_eat = -1;
		if (table->nb_must_eat != -1)
			ph[i].nb_eat = 0;
		if (pthread_mutex_init(&ph[i].l_fork, NULL) != 0)
			return (ft_mutex_ph_error(ph, i));
		ph[i].r_fork = &ph[(i + 1) % table->nb_philo].l_fork;
	}
	return (0);
}

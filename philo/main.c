/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 10:06:27 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/05 11:18:30 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_main(t_table *table, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		if (pthread_create(&ph[i].thread, NULL, ft_routine, &ph[i]))
			return (ft_ph_tread_error(ph, i), 1);
	}
	ft_time_setter(&table->start, &table->data);
	return (0);
}

int	main(int ac, char **av)
{
	t_table		table;
	t_philo		*ph;
	pthread_t	supervisor;

	if (ft_parse(ac, av) || ft_init_data(&table, ac, av))
		return (1);
	ph = malloc(sizeof(t_philo) * table.nb_philo);
	if (!ph)
	{
		printf("%sError: malloc failed%s\n", RED, NC);
		return (1);
	}
	if (ft_init_philo(ph, &table))
		return (free(ph), 1);
	table.ph = ph;
	if (ft_main(&table, ph))
		return (1);
	ft_int_setter(&table.can_eat, 1, &table.data);
	if (pthread_create(&supervisor, NULL, ft_supervise, &table))
		return (ft_supervisor_error(supervisor), 1);
	ft_free_thread(&table, ph, supervisor);
	ft_free_mtx(&table, ph);
	return (0);
}

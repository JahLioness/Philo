/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 11:25:49 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/23 12:26:43 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static int	ft_main(t_table *table, t_philo *ph)
{
	int	i;

	i = -1;
	ft_time_setter(&table->start, table->data);
	ft_int_setter(&table->can_eat, 1, table->data);
	while (++i < table->nb_philo)
	{
		ph[i].pid = fork();
		if (ph[i].pid == -1)
		{
			printf("%sError: fork failed%s\n", RED, NC);
			return (1);
		}
		if (ph[i].pid == 0)
		{
			ph[i].last_meal = table->start;
			ft_routine(&ph[i]);
		}
	}
	while (i--)
		waitpid(ph[i].pid, NULL, 0);
	return (0);
}
		// else
		// {
		// 	waitpid(ph[i].pid, NULL, 0);
		// 	kill(ph[i].pid, SIGKILL);
		// }

int	main(int ac, char **av)
{
	t_table		table;
	t_philo		*ph;

	if (ft_parse(ac, av))
		return (1);
	ft_init_table(&table, ac, av);
	ph = malloc(sizeof(t_philo) * table.nb_philo);
	if (!ph)
	{
		printf("%sError: malloc failed%s\n", RED, NC);
		return (1);
	}
	ft_init_philo(&table, ph);
	table.ph = ph;
	ft_init_sem(&table);
	if (ft_main(&table, ph))
		return (1);
	ft_free_philo(&table, ph);
	ft_free_sem(&table);
	return (0);
}
	// free(ph);

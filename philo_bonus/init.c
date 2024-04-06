/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 00:28:03 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/06 11:07:07 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_init_sem(t_table *table)
{
	sem_unlink("dead");
	sem_unlink("data");
	sem_unlink("forks");
	sem_unlink("print");
	table->dead = sem_open("dead", O_CREAT, 0644, 0);
	table->data = sem_open("data", O_CREAT, 0644, 1);
	table->print = sem_open("print", O_CREAT, 0644, 1);
	table->forks = sem_open("forks", O_CREAT, 0644, table->nb_philo);
}

void	ft_init_table(t_table *table, int ac, char **av)
{
	table->nb_philo = ft_atoi(av[1]);
	table->time_to_die = ft_atoi(av[2]);
	table->time_to_eat = ft_atoi(av[3]);
	table->time_to_sleep = ft_atoi(av[4]);
	table->nb_must_eat = -1;
	if (ac == 6)
		table->nb_must_eat = ft_atoi(av[5]);
	table->can_eat = 0;
	// table->is_dead = 0;
	table->have_eat = 0;
	table->start.tv_sec = 0;
	table->start.tv_usec = 0;
	table->dead = NULL;
	table->data = NULL;
	table->print = NULL;
	table->forks = NULL;
}

void	ft_init_philo(t_table *table, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
	{
		ph[i].id = i + 1;
		ph[i].table = table;
		ph[i].nb_eat = -1;
		if (table->nb_must_eat != -1)
			ph[i].nb_eat = 0;
	}
}

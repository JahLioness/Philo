/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:32:41 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/12 15:38:24 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_free_sem(t_table *table)
{
	sem_close(table->dead);
	sem_close(table->forks);
	sem_close(table->data);
	sem_close(table->print);
	sem_unlink("dead");
	sem_unlink("forks");
	sem_unlink("data");
	sem_unlink("print");
}

void	ft_free_philo(t_table *table, t_philo *ph)
{
	int	i;

	i = -1;
	while (++i < table->nb_philo)
		kill(ph[i].pid, SIGKILL);
	free(ph);
}

int	ft_supervisor_error(pthread_t supervisor)
{
	printf("%sError: supervisor thread creation failed%s\n", RED, NC);
	pthread_detach(supervisor);
	return (1);
}

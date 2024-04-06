/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:44:36 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/06 12:04:19 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_one_process(t_philo *ph)
{
	while (1)
	{
		sem_wait(ph->table->forks);
		sem_wait(ph->table->print);
		printf("%d %d has taken a fork\n",
			ft_get_current_time_diff(ph->table->start), ph->id);
		sem_post(ph->table->print);
		while (!ft_check_death(ph))
			;
		sem_post(ph->table->forks);
		if (ft_check_death(ph))
			break ;
	}
}

static void	ft_set_nb_eat(t_philo *ph)
{
	if (ft_int_getter(&ph->table->nb_must_eat, ph->table->data) != -1)
		ft_int_setter(&ph->nb_eat, ph->nb_eat + 1, ph->table->data);
}

static void	ft_execute_routine(t_philo *ph)
{
	ft_eat(ph);
	ft_set_nb_eat(ph);
	ft_execute_end_routine(ph);
}

void	*ft_routine(t_philo *ph)
{
	pthread_t	thread;

	if (ph->id % 2 == 0)
		usleep(1500);
	pthread_create(&thread, NULL, ft_supervise, ph);
	while (1)
	{
		if (ft_int_getter(&ph->table->can_eat, ph->table->data))
		{
			if (ph->table->nb_philo == 1)
			{
				ft_one_process(ph);
				break ;
			}
			if (ft_check_routine(ph))
				ft_execute_routine(ph);
		}
		if (ft_check_death(ph))
			break ;
	}
	pthread_join(thread, NULL);
	return (NULL);
}

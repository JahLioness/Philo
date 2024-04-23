/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:58:52 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/23 11:46:22 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_check_death_sup(t_table *table, t_philo *ph)
{
	if (ft_long_getter(&table->dead->__align, table->data) == 0 && ((ft_get_current_time_diff(ph->last_meal) >= table->t_t_die
				&& ft_get_current_time_diff(table->start) >= table->t_t_die)
			|| (ft_int_getter(&table->nb_philo, table->data) == 1
				&& ft_get_current_time_diff(table->start) >= table->t_t_die)))
	{
		sem_post(table->dead);
		if (ft_long_getter(&table->print->__align, table->data) == 1)
		{
			sem_wait(table->print);
			printf("%s%d %d died%s\n", RED, ft_get_current_time_diff(table->start),
				ph->id, NC);
		}
		// return ;
		sem_post(table->print);
	}
}

static int	ft_check(t_philo *ph)
{
	if (ft_long_getter(&ph->table->dead->__align, ph->table->data) > 0
		|| (ft_int_getter(&ph->nb_eat,
				ph->table->data) == ft_int_getter(&ph->table->nb_must_eat,
				ph->table->data) && ft_int_getter(&ph->table->nb_must_eat,
				ph->table->data) != -1))
		return (1);
	return (0);
}

void	*ft_supervise(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		if (ft_check(ph))
			break ;
		while (ft_int_getter(&ph->table->can_eat, ph->table->data) == 1)
		{
			if (ft_int_getter(&ph->table->nb_must_eat, ph->table->data) == -1
				|| ft_int_getter(&ph->table->nb_must_eat,
					ph->table->data) > ft_int_getter(&ph->nb_eat,
					ph->table->data))
			{
				ft_check_death_sup(ph->table, ph);
				break ;
			}
			if (ft_int_getter(&ph->nb_eat,
					ph->table->data) == ft_int_getter(&ph->table->nb_must_eat,
					ph->table->data) && ft_int_getter(&ph->table->nb_must_eat,
					ph->table->data) != -1)
				return (NULL);
		}
	}
	return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:58:52 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/06 12:10:46 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_check_death_sup(t_table *table, t_philo *ph)
{
	if (((ft_get_current_time_diff(ph->last_meal) >= table->t_t_die
				&& ft_get_current_time_diff(table->start) >= table->t_t_die)
			|| (ft_int_getter(&table->nb_philo, table->data) == 1
				&& ft_get_current_time_diff(table->start) >= table->t_t_die))
		&& !ft_long_getter(&table->dead->__align, table->data))
	{
		sem_wait(table->print);
		sem_post(table->dead);
		printf("%s%d %d died%s\n", RED, ft_get_current_time_diff(table->start),
			ph->id, NC);
		sem_post(table->print);
	}
}

static int	ft_check(t_philo *ph)
{
	if (ft_long_getter(&ph->table->dead->__align, ph->table->data)
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
		while (ph->table->can_eat == 1)
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

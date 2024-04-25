/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 20:14:55 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/24 11:43:19 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	ft_check_death_sup(t_table *table, int i)
{
	if ((ft_get_current_time_diff(table->ph[i].last_meal) > table->time_to_die
			&& ft_get_current_time_diff(table->start) > table->time_to_die)
		|| (ft_int_getter(&table->nb_philo, &table->data) == 1
			&& ft_get_current_time_diff(table->start) > table->time_to_die))
	{
		pthread_mutex_lock(&table->print);
		printf("%s%d %d died%s\n", RED, ft_get_current_time_diff(table->start),
			table->ph[i].id, NC);
		ft_int_setter(&table->is_dead, 1, &table->data);
		pthread_mutex_unlock(&table->print);
	}
}

void	*ft_supervise(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	while (1)
	{
		if (ft_int_getter(&table->is_dead, &table->data)
			|| ft_int_getter(&table->have_eat, &table->data))
			break ;
		i = -1;
		while (++i < table->nb_philo && table->can_eat == 1)
		{
			if (ft_int_getter(&table->nb_must_eat, &table->data) == -1
				|| (ft_int_getter(&table->nb_must_eat,
						&table->data) > ft_int_getter(&table->ph[i].nb_eat,
						&table->data)))
			{
				ft_check_death_sup(table, i);
				break ;
			}
		}
	}
	return (NULL);
}

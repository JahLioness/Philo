/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervise.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 07:58:52 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/06 11:16:38 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

// static void	ft_check_death_print(t_table *table, int i)
// {
// 	printf("last_meal: %d\n", ft_get_current_time_diff(table->ph[i].last_meal));
// 	if (((ft_get_current_time_diff(table->ph[i].last_meal) >= table->time_to_die
// 			&& ft_get_current_time_diff(table->start) >= table->time_to_die)
// 		|| (ft_int_getter(&table->nb_philo, table->data) == 1
// 			&& ft_get_current_time_diff(table->start) >= table->time_to_die)))
// 	{
// 		sem_wait(table->print);
// 		printf("%s%d %d died%s\n", RED, ft_get_current_time_diff(table->start),
// 			table->ph[i].id, NC);
// 		ft_int_setter(&table->is_dead, 1, table->data);
// 		sem_post(table->print);
// 	}
// }

// void	*ft_supervise_death(void *arg)
// {
// 	t_table	*table;
// 	int		i;

// 	table = (t_table *)arg;
// 	while (1)
// 	{
// 		if (ft_int_getter(&table->is_dead, table->data))
// 			break ;
// 		i = -1;
// 		while (++i < table->nb_philo && table->can_eat == 1)
// 		{
// 			if (ft_int_getter(&table->nb_must_eat, table->data) == -1
// 				|| ft_int_getter(&table->nb_must_eat,
// 						table->data) > ft_int_getter(&table->ph[i].nb_eat,
// 						table->data))
// 			{
// 				ft_check_death_print(table, i);
// 				break ;
// 			}
// 			if (ft_int_getter(&table->ph->nb_eat,
// 				table->data) == ft_int_getter(&table->nb_must_eat,
// 				table->data) && ft_int_getter(&table->nb_must_eat,
// 				table->data) != -1)
// 				return (NULL);
// 		}
// 	}
// 	return (NULL);
// }

static void	ft_check_death_sup(t_table *table, t_philo *ph)
{
	if (((ft_get_current_time_diff(ph->last_meal) >= table->time_to_die
			&& ft_get_current_time_diff(table->start) >= table->time_to_die)
		|| (ft_int_getter(&table->nb_philo, table->data) == 1
			&& ft_get_current_time_diff(table->start) >= table->time_to_die)) && !ft_long_getter(&table->dead->__align, table->data))
	{
		sem_wait(table->print);
		sem_post(table->dead);
		printf("%s%d %d died%s\n", RED, ft_get_current_time_diff(table->start),
			ph->id, NC);
		sem_post(table->print);
	}
}

void	*ft_supervise(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	while (1)
	{
		if (ft_long_getter(&ph->table->dead->__align, ph->table->data)
			|| (ft_int_getter(&ph->nb_eat,
				ph->table->data) == ft_int_getter(&ph->table->nb_must_eat,
				ph->table->data) && ft_int_getter(&ph->table->nb_must_eat,
				ph->table->data) != -1))
			return (NULL);
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

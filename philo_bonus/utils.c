/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:03:10 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/05 08:06:49 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	j = 0;
	nb = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			j++;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
		nb = nb * 10 + (nptr[i++] - '0');
	if (j != 0)
		nb = -nb;
	return (nb);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

void	ft_get_time(struct timeval *current)
{
	gettimeofday(current, NULL);
}

int	ft_get_current_time_diff(struct timeval start)
{
	int				diff;
	struct timeval	current;

	gettimeofday(&current, NULL);
	diff = (current.tv_sec - start.tv_sec) * 1000;
	diff += (current.tv_usec - start.tv_usec) / 1000;
	return (diff);
}

int	ft_get_time_diff(struct timeval start, struct timeval end)
{
	int	diff;

	diff = (end.tv_sec - start.tv_sec) * 1000;
	diff += (end.tv_usec - start.tv_usec) / 1000;
	return (diff);
}

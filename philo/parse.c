/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:03:48 by ede-cola          #+#    #+#             */
/*   Updated: 2024/03/18 13:06:44 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_parse(int ac, char **av)
{
	if (ac < 5 || ac > 6)
	{
		printf("%sError: wrong number of arguments%s\n", RED, NC);
		return (1);
	}
	if (!ft_atoi(av[1]) || ft_atoi(av[2]) < 60 || ft_atoi(av[3]) < 60
		|| ft_atoi(av[4]) < 60)
	{
		printf("%sError: wrong arguments%s\n", RED, NC);
		return (1);
	}
	if (ac == 6 && ft_atoi(av[5]) < 1)
	{
		printf("%sError: wrong arguments%s\n", RED, NC);
		return (1);
	}
	return (0);
}

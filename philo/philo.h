/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:55:40 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/24 12:16:50 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# define NC			"\e[0m"
# define YELLOW		"\e[33m"
# define BYELLOW	"\e[1;33m"
# define RED		"\e[31m"
# define GREEN		"\e[32m"
# define CYAN		"\e[0;36m"
# define BLUE		"\e[0;34m"

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_table
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	int				is_dead;
	int				can_eat;
	int				have_eat;
	struct timeval	start;
	pthread_mutex_t	data;
	pthread_mutex_t	print;
	struct s_philo	*ph;
}				t_table;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	t_table			*table;
	pthread_t		thread;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	*r_fork;
	struct timeval	last_meal;
}				t_philo;

/* FT_UTILS */
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_get_time_diff(struct timeval start, struct timeval end);
int		ft_get_current_time_diff(struct timeval start);
int		ft_parse(int ac, char **av);
int		ft_int_getter(int *value, pthread_mutex_t *mutex);
void	ft_get_time(struct timeval *current);
void	ft_int_setter(int *value, int new_value, pthread_mutex_t *mtx);
void	ft_time_setter(struct timeval *time, pthread_mutex_t *mtx);
void	ft_sleep(int time, t_table *table);

/* FT_ERRORS */
int		ft_mutex_ph_error(t_philo *ph, int i);
int		ft_ph_tread_error(t_philo *ph, int i);
int		ft_supervisor_error(pthread_t supervisor);

/* FT_FREE*/
void	ft_free_mtx(t_table *table, t_philo *ph);
void	ft_free_thread(t_table *table, t_philo *ph, pthread_t supervisor);

/* FT_INIT */
int		ft_init_data(t_table *table, int ac, char **av);
int		ft_init_philo(t_philo *ph, t_table *table);

/* FT_ROUTINE */
void	ft_eat(t_philo *ph);
void	ft_think(t_philo *ph);
void	*ft_routine(void *arg);
void	*ft_supervise(void *arg);
int		ft_check_death(t_philo *ph);
int		ft_check_routine(t_philo *ph);
void	ft_execute_end_routine(t_philo *ph);

#endif
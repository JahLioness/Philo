/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-cola <ede-cola@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 06:07:00 by ede-cola          #+#    #+#             */
/*   Updated: 2024/04/06 11:08:25 by ede-cola         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

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
# include <fcntl.h>
# include <signal.h>
# include <semaphore.h>
# include <pthread.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_table
{
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_must_eat;
	// int				is_dead;
	int				can_eat;
	int				have_eat;
	sem_t			*dead;
	sem_t			*data;
	sem_t			*print;
	sem_t			*forks;
	struct timeval	start;
	struct s_philo	*ph;
}				t_table;

typedef struct s_philo
{
	int				id;
	int				nb_eat;
	t_table			*table;
	pid_t			pid;
	struct timeval	last_meal;
}				t_philo;

/* FT_UTILS */
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_get_time_diff(struct timeval start, struct timeval end);
int		ft_get_current_time_diff(struct timeval start);
int		ft_parse(int ac, char **av);
void	ft_get_time(struct timeval *current);

/*	FT_INIT	*/
void	ft_init_sem(t_table *table);
void	ft_init_philo(t_table *table, t_philo *ph);
void	ft_init_table(t_table *table, int ac, char **av);

/* FT_SETTER_GETTER	*/
void	ft_int_setter(int *var, int value, sem_t *sem);
void	ft_time_setter(struct timeval *start, sem_t *sem);
int		ft_int_getter(int *var, sem_t *sem);
long	ft_long_getter(long *value, sem_t *sem);

/*	FT_ERROR_FREE	*/
void	ft_free_sem(t_table *table);
void	ft_free_philo(t_table *table, t_philo *ph);
int		ft_supervisor_error(pthread_t supervisor);

/*	FT_ROUTINE	*/
void	ft_eat(t_philo *ph);
void	*ft_routine(t_philo *ph);
void	ft_think(t_philo *ph);
void	*ft_supervise(void *arg);
void	*ft_supervise_death(void *arg);
int		ft_check_death(t_philo *ph);
int		ft_check_routine(t_philo *ph);
void	ft_execute_end_routine(t_philo *ph);

#endif
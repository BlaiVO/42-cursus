/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:00:18 by blvilarn          #+#    #+#             */
/*   Updated: 2024/01/29 16:16:10 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <stdio.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	int				num_of_philos;
	int				num_times_to_eat;
	int				*dead;
	pthread_mutex_t	*r_fork;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*dead_lock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_data
{
	int				num_of_philos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				num_times_to_eat;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				dead_flag;
	pthread_mutex_t	dead_lock;
	pthread_mutex_t	meal_lock;
	pthread_mutex_t	write_lock;
}					t_data;

//main.c
int		save_arguments(int argc, char **argv, t_data *data);
int		get_params(int argc, char **argv, t_data *data);
void	clean_data(char *str, t_data *data);
void	init_philos(t_data *data, size_t i);

//utils.c
int		ft_usleep(size_t milliseconds);
size_t	get_current_time(void);
int		ft_strlen(char *str);

//totally_not_libft.c
int		ft_iswhitespace(int c);
int		ft_isdigit(int c);
int		ft_isnum(char *str);
int		ft_atoi(const char *str);

//threads.c
int		dead_loop(t_philo *philo);
void	*philo_routine(void *pointer);
int		thread_create(t_data *data);

//routine_actions.c
void	print_message(char *str, t_philo *philo, int id);
void	philo_thinks(t_philo *philo);
void	philo_dreams(t_philo *philo);
void	philo_eats(t_philo *philo);

//monitor.c
int		philosopher_dead(t_philo *philo, size_t time_to_die);
int		check_if_dead(t_philo *philos);
int		check_if_all_ate(t_philo *philos);
void	*monitor(void *pointer);

#endif

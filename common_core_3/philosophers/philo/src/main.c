/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:51:39 by blvilarn          #+#    #+#             */
/*   Updated: 2024/01/12 12:26:06 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_gral	gral;

	if (argc == 5 || argc == 6)
	{
		if (!save_arguments(argc, argv, &gral))
		{
			printf("Invalid argument\n");
			return (0);
		}
		pthread_mutex_init(&gral.write_lock, NULL);
		pthread_mutex_init(&gral.dead_lock, NULL);
		pthread_mutex_init(&gral.meal_lock, NULL);
		thread_create(&gral);
		clean_gral(NULL, &gral);
	}
	else
	{
		printf("Invalid number of arguments. Accepted format: \n");
		printf("num_of_philos time_to_die time_to_sleep (num_times_to_eat)\n");
	}
	return (0);
}

int	save_arguments(int argc, char **argv, t_gral *gral)
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				i;

	if (!get_params(argc, argv, gral))
		return (0);
	philos = malloc(gral->num_of_philos * sizeof(t_philo));
	forks = malloc(gral->num_of_philos * sizeof(pthread_mutex_t));
	gral->philos = philos;
	gral->forks = forks;
	i = 0;
	while (i < gral->num_of_philos)
	{
		pthread_mutex_init(&gral->forks[i], NULL);
		init_philos(gral, i);
		i++;
	}
	return (1);
}

int	get_params(int argc, char **argv, t_gral *gral)
{
	int	i;

	i = 1;
	gral->num_of_philos = -1;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
			return (0);
		i++;
	}
	gral->num_of_philos = ft_atoi(argv[1]);
	gral->time_to_die = (size_t)ft_atoi(argv[2]);
	gral->time_to_eat = (size_t)ft_atoi(argv[3]);
	gral->time_to_sleep = (size_t)ft_atoi(argv[4]);
	gral->num_times_to_eat = -1;
	if (argc == 6)
		gral->num_times_to_eat = ft_atoi(argv[5]);
	return (1);
}

void	clean_gral(char *str, t_gral *gral)
{
	int	i;

	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&gral->write_lock);
	pthread_mutex_destroy(&gral->meal_lock);
	pthread_mutex_destroy(&gral->dead_lock);
	i = 0;
	while (i < gral->num_of_philos)
	{
		pthread_mutex_destroy(&gral->forks[i]);
		i++;
	}
	free(gral->forks);
	free(gral->philos);
}

void	init_philos(t_gral *gral, size_t i)
{
	gral->philos[i].id = (int)i + 1;
	gral->philos[i].eating = 0;
	gral->philos[i].meals_eaten = 0;
	gral->philos[i].time_to_die = gral->time_to_die;
	gral->philos[i].time_to_eat = gral->time_to_eat;
	gral->philos[i].time_to_sleep = gral->time_to_sleep;
	gral->philos[i].num_of_philos = gral->num_of_philos;
	gral->philos[i].num_times_to_eat = gral->num_times_to_eat;
	gral->philos[i].start_time = get_current_time();
	gral->philos[i].last_meal = get_current_time();
	gral->philos[i].write_lock = &gral->write_lock;
	gral->philos[i].dead_lock = &gral->dead_lock;
	gral->philos[i].meal_lock = &gral->meal_lock;
	gral->philos[i].dead = &gral->dead_flag;
	gral->philos[i].l_fork = &gral->forks[i];
	if (i == 0)
		gral->philos[i].r_fork = \
		&gral->forks[gral->philos[i].num_of_philos - 1];
	else
		gral->philos[i].r_fork = &gral->forks[i - 1];
}

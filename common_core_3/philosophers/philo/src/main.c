/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:51:39 by blvilarn          #+#    #+#             */
/*   Updated: 2024/02/08 18:37:52 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 5 || argc == 6)
	{
		if (!save_arguments(argc, argv, &data))
		{
			printf("Invalid argument\n");
			return (0);
		}
		pthread_mutex_init(&data.write_lock, NULL);
		pthread_mutex_init(&data.dead_lock, NULL);
		pthread_mutex_init(&data.meal_lock, NULL);
		thread_create(&data);
		clean_data(NULL, &data);
	}
	else
	{
		printf("Invalid number of arguments. Accepted format: \n");
		printf("num_of_philos time_to_die time_to_sleep (num_times_to_eat)\n");
	}
	return (0);
}

int	save_arguments(int argc, char **argv, t_data *data)
{
	int	i;

	if (!get_params(argc, argv, data))
		return (0);
	data->philos = malloc(data->num_of_philos * sizeof(t_philo));
	if (data->philos != NULL)
	{
		printf("Malloc Error\n");
		exit(1);
	}
	data->forks = malloc(data->num_of_philos * sizeof(pthread_mutex_t));
	if (data->forks != NULL)
	{
		free(data->philos);
		printf("Malloc error\n");
		exit(1);
	}
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		init_philos(data, i);
		i++;
	}
	return (1);
}

int	get_params(int argc, char **argv, t_data *data)
{
	int	i;

	i = 1;
	data->num_of_philos = -1;
	while (i < argc)
	{
		if (!ft_isnum(argv[i]))
			return (0);
		i++;
	}
	data->num_of_philos = ft_atoi(argv[1]);
	data->time_to_die = (size_t)ft_atoi(argv[2]);
	data->time_to_eat = (size_t)ft_atoi(argv[3]);
	data->time_to_sleep = (size_t)ft_atoi(argv[4]);
	data->num_times_to_eat = -1;
	if (argc == 6)
		data->num_times_to_eat = ft_atoi(argv[5]);
	return (1);
}

void	clean_data(char *str, t_data *data)
{
	int	i;

	if (str)
	{
		write(2, str, ft_strlen(str));
		write(2, "\n", 1);
	}
	pthread_mutex_destroy(&data->write_lock);
	pthread_mutex_destroy(&data->meal_lock);
	pthread_mutex_destroy(&data->dead_lock);
	i = 0;
	while (i < data->num_of_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	free(data->forks);
	free(data->philos);
	exit (1);
}

void	init_philos(t_data *data, size_t i)
{
	data->philos[i].id = i;
	data->philos[i].eating = 0;
	data->philos[i].meals_eaten = 0;
	data->philos[i].time_to_die = data->time_to_die;
	data->philos[i].time_to_eat = data->time_to_eat;
	data->philos[i].time_to_sleep = data->time_to_sleep;
	data->philos[i].num_of_philos = data->num_of_philos;
	data->philos[i].num_times_to_eat = data->num_times_to_eat;
	data->philos[i].start_time = get_current_time();
	data->philos[i].last_meal = get_current_time();
	data->philos[i].write_lock = &data->write_lock;
	data->philos[i].dead_lock = &data->dead_lock;
	data->philos[i].meal_lock = &data->meal_lock;
	data->philos[i].dead = &data->dead_flag;
	data->philos[i].l_fork = &data->forks[i];
	if (i == 0)
		data->philos[i].r_fork = \
		&data->forks[data->philos[i].num_of_philos - 1];
	else
		data->philos[i].r_fork = &data->forks[i - 1];
}

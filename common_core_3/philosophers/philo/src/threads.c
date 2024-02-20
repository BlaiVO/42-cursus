/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:52:02 by blvilarn          #+#    #+#             */
/*   Updated: 2024/02/20 17:12:33 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
	{
		pthread_mutex_unlock(philo->dead_lock);
		return (1);
	}
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 != 0)
		ft_usleep(2, philo);
	while (!dead_loop(philo))
	{
		philo_thinks(philo);
		philo_eats(philo);
		philo_dreams(philo);
	}
	return (pointer);
}

int	thread_create(t_data *data)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, data->philos) != 0)
		return (clean_data("Thread creation error", data), 1);
	i = 0;
	while (i < data->num_of_philos)
	{
		if (pthread_create(&data->philos[i].thread, NULL, &philo_routine,
				&data->philos[i]) != 0)
			return (clean_data("Thread creation error", data));
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		return (clean_data("Thread join error", data));
	while (i < data->num_of_philos)
	{
		if (pthread_join(data->philos[i].thread, NULL) != 0)
			return (clean_data("Thread join error", data));
		i++;
	}
	return (0);
}

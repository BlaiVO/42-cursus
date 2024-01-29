/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 11:52:02 by blvilarn          #+#    #+#             */
/*   Updated: 2024/01/12 11:52:03 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../philosophers.h"

int	dead_loop(t_philo *philo)
{
	pthread_mutex_lock(philo->dead_lock);
	if (*philo->dead == 1)
		return (pthread_mutex_unlock(philo->dead_lock), 1);
	pthread_mutex_unlock(philo->dead_lock);
	return (0);
}

void	*philo_routine(void *pointer)
{
	t_philo	*philo;

	philo = (t_philo *)pointer;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!dead_loop(philo))
	{
		philo_eats(philo);
		philo_dreams(philo);
		philo_thinks(philo);
	}
	return (pointer);
}

int	thread_create(t_gral *gral)
{
	pthread_t	observer;
	int			i;

	if (pthread_create(&observer, NULL, &monitor, gral->philos) != 0)
		clean_gral("Thread creation error", gral);
	i = 0;
	while (i < gral->num_of_philos)
	{
		if (pthread_create(&gral->philos[i].thread, NULL, &philo_routine,
				&gral->philos[i]) != 0)
			clean_gral("Thread creation error", gral);
		i++;
	}
	i = 0;
	if (pthread_join(observer, NULL) != 0)
		clean_gral("Thread join error", gral);
	while (i < gral->num_of_philos)
	{
		if (pthread_join(gral->philos[i].thread, NULL) != 0)
			clean_gral("Thread join error", gral);
		i++;
	}
	return (0);
}

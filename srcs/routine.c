/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:54:59 by juan              #+#    #+#             */
/*   Updated: 2022/02/10 17:21:26 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../inc/philo.h"
#include "../inc/macro.h"

void	miam_time(t_thread *thread)
{
	if (thread->access->dead == 0)
	{
		pthread_mutex_lock(&thread->access->fork[thread->number - 1]);
		pthread_mutex_lock(thread->access->next_fork[thread->number - 1]);
		thread->local_time = get_time();
		thread->miamed = get_time();
		thread->access->eat_count++;
		print_miam_timestamps(thread);
		thread->famished = 1;
		ft_usleep(thread->access->time_to_eat);
		thread->famished = 0;
		pthread_mutex_unlock(thread->access->next_fork[thread->number - 1]);
		pthread_mutex_unlock(&thread->access->fork[thread->number - 1]);
	}
}

void	sleep_time(t_thread *thread)
{
	if (thread->access->dead == 0)
	{
		pthread_mutex_lock(&thread->access->print);
		printf("%ld ms	philo %d sleeps soundly\n", \
			get_time() - thread->access->time,
			thread->number);
		pthread_mutex_unlock(&thread->access->print);
		thread->famished = 1;
		ft_usleep(thread->access->time_to_sleep);
		thread->famished = 0;
	}
}

void	think_time(t_thread *thread)
{
	if (thread->access->dead == 0)
	{
		pthread_mutex_lock(&thread->access->print);
		printf("%ld ms	philo %d thinks deeply\n",
			get_time() - thread->access->time,
			thread->number);
		pthread_mutex_unlock(&thread->access->print);
	}
}

void	sky_time(t_philo *philo)
{
	int	i;

	if (philo->number_of_philosophers == 1)
		death(philo, 0);
	while (philo->number_of_philosophers > 1)
	{
		if (check_nb_of_miam(philo))
			break ;
		i = 0;
		while (i < philo->number_of_philosophers)
		{
			if (philo->thread[i].famished)
				continue ;
			if (get_time() - philo->thread[i].miamed >= philo->time_to_die)
			{
				philo->dead = 1;
				death(philo, i);
				return ;
			}
			i++;
		}
	}
}

void	nihility(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->number_of_philosophers)
		pthread_join(philo->thread[i++].thread, NULL);
	i = 0;
	while (i < philo->number_of_philosophers)
		pthread_mutex_destroy(&philo->fork[i++]);
	pthread_mutex_destroy(&philo->napkin);
	pthread_mutex_destroy(&philo->print);
	free(philo->next_fork);
	free(philo);
}

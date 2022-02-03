/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 17:54:59 by juan              #+#    #+#             */
/*   Updated: 2022/02/03 16:45:55 by jbuan            ###   ########.fr       */
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
		//printf("%ld ms	philo %d embrouille\n", thread->local_time
		//	- thread->access->time, thread->number);
		thread->miamed = thread->local_time;
		thread->access->eat_count++;
		pthread_mutex_lock(&thread->fork);
		pthread_mutex_lock(thread->next_fork);
		pthread_mutex_lock(&thread->access->napkin);
		pthread_mutex_lock(&thread->access->print);
		printf("%ld ms	philo %d took a fork\n", thread->local_time
			- thread->access->time, thread->number);
		printf("%ld ms	philo %d took a fork\n", thread->local_time
			- thread->access->time, thread->number);
		printf("%ld ms	philo %d is eating\n", thread->local_time
			- thread->access->time, thread->number);
		pthread_mutex_unlock(&thread->access->napkin);
		pthread_mutex_unlock(&thread->access->print);
		thread->famished = 1;
		usleep(thread->access->time_to_eat * 1000);
		thread->local_time = get_time();
		thread->famished = 0;
		pthread_mutex_unlock(&thread->fork);
		pthread_mutex_unlock(thread->next_fork);
	}
}

void	sleep_time(t_thread *thread)
{
	if (thread->access->dead == 0)
	{
		pthread_mutex_lock(&thread->access->napkin);
		pthread_mutex_lock(&thread->access->print);
		printf("%ld ms	philo %d sleeps soundly\n", \
			thread->local_time - thread->access->time,
			thread->number);
		pthread_mutex_unlock(&thread->access->napkin);
		pthread_mutex_unlock(&thread->access->print);
		thread->sleepy = 1;
		usleep(thread->access->time_to_sleep * 1000);
		thread->local_time = get_time();
		thread->sleepy = 0;
	}
}

void	think_time(t_thread *thread)
{
	if (thread->access->dead == 0)
	{
		printf("%ld ms	philo %d thinks deeply\n",
			thread->local_time - thread->access->time,
			thread->number);
	}
}

void	sky_time(t_philo *philo)
{
	int	i;

	if (philo->number_of_philosophers == 1)
		death(philo, 1);
	while (philo->number_of_philosophers > 1)
	{
		i = 0;
		while (++i <= philo->number_of_philosophers)
		{
			if (philo->thread[i].famished)
				continue ;
			pthread_mutex_lock(&philo->print);
			if (philo->thread[i].local_time - \
			philo->thread[i].miamed >= philo->time_to_die)
			{
				death(philo, i);
				return ;
			}
			pthread_mutex_unlock(&philo->print);
		}
		if (check_nb_of_miam(philo))
			break ;
	}
	philo->dead = 1;
}

void	nihility(t_philo *philo)
{
	int	i;

	usleep(10);
	i = 0;
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_destroy(&philo->print);
	pthread_mutex_unlock(&philo->napkin);
	pthread_mutex_destroy(&philo->napkin);
	while (++i <= philo->number_of_philosophers)
	{
		pthread_mutex_unlock(&philo->thread[i].fork);
		pthread_mutex_destroy(&philo->thread[i].fork);
		pthread_mutex_unlock(philo->thread[i].next_fork);
		pthread_mutex_destroy(philo->thread[i].next_fork);
		pthread_join(philo->thread[i].thread, NULL);
	}
	free(philo);
}

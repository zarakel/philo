/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:17:20 by juan              #+#    #+#             */
/*   Updated: 2022/02/03 16:49:31 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../inc/philo.h"
#include "../inc/macro.h"

long	get_time(void)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds += tp.tv_usec / 1000;
	return (milliseconds);
}

void	*menu(void *arg)
{
	t_thread	*thread;

	thread = (t_thread *)arg;
	if (thread->access->number_of_philosophers == 1)
	{
		thread->miamed = get_time();
		printf("%ld ms	philo %d have no enough fork\n", get_time()
			- thread->access->time, thread->number);
		usleep(thread->access->time_to_die * 1000);
		return (0);
	}
	if (thread->number % 2 == 0)
	{
		thread->local_time += thread->access->time_to_eat;
		usleep(thread->access->time_to_eat * 1000);
	}
	while (thread->access->dead == 0)
	{
		miam_time(thread);
		sleep_time(thread);
		think_time(thread);
	}
	return (0);
}

int	check_nb_of_miam(t_philo *philo)
{
	if (philo->number_of_times_each_philosopher_must_eat > 0)
	{
		if (philo->eat_count
			>= philo->number_of_times_each_philosopher_must_eat
			* philo->number_of_philosophers)
			return (1);
		return (0);
	}
	return (0);
}

void	main_shit(t_philo *philo)
{
	int	i;
	int	errorp;

	//philo impair genre 1 et 3 si il n'y en a que 3 ne peuvent pas bouffer ensemble puisque ils ne peuvent pas partager leur fourchettes en commun
	i = 0;
	errorp = 0;
	philo->time = get_time();
	while (++i <= philo->number_of_philosophers)
		philo->thread[i].local_time = philo->time;
	philo->thread->local_time = philo->time;
	pthread_mutex_init(&philo->print, NULL);
	pthread_mutex_init(&philo->napkin, NULL);
	i = 0;
	while (++i <= philo->number_of_philosophers)
	{
		if (pthread_create(&philo->thread[i].thread, NULL,
				menu, &philo->thread[i]) != 0)
		{
			error_san(ERRNO4, ERRMSG4, errorp);
			return ;
		}
	}
	sky_time(philo);
}

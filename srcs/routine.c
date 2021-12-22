#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../inc/philo.h"
#include "../inc/macro.h"

void	miam_time(t_thread *thread)
{
	pthread_mutex_lock(&thread->access->napkin);
	thread->miamed = thread->local_time;
	if (thread->number % 2 == 0)
	{
		thread->local_time += thread->access->time_to_eat;
		usleep(thread->access->time_to_eat * 1000);
	}
	if (sky_time(thread) == 1)
		return;
	pthread_mutex_lock(&thread->fork);
	pthread_mutex_lock(thread->next_fork);
	printf("%ld ms	philo %d took a fork\n", thread->local_time - thread->access->time, thread->number);
	printf("%ld ms	philo %d took a fork\n", thread->local_time - thread->access->time, thread->number);
	printf("%ld ms	philo %d is eating\n", thread->local_time - thread->access->time, thread->number);
	thread->local_time += thread->access->time_to_eat;
	thread->miamed = thread->local_time;
	pthread_mutex_unlock(&thread->access->napkin);
	usleep(thread->access->time_to_eat * 1000);
}

void	sleep_time(t_thread *thread)
{
	pthread_mutex_lock(&thread->access->print);
	pthread_mutex_lock(&thread->access->napkin);
	printf("%ld ms	philo %d sleeps soundly\n", thread->local_time - thread->access->time, thread->number);
	thread->local_time += thread->access->time_to_sleep;
	if (sky_time(thread) == 1)
			return ;
	pthread_mutex_unlock(&thread->access->print);
	pthread_mutex_unlock(&thread->access->napkin);
	usleep(thread->access->time_to_sleep * 1000);	
}

int	sky_time(t_thread *thread)
{
// est censé me permettre de reperer quand un philo est mort due a un trop long temps san manger
	if (thread->local_time - thread->miamed >= thread->access->time_to_die && thread->alive == 1)
	{
		pthread_mutex_lock(&thread->access->napkin);
		pthread_mutex_lock(&thread->access->print);
		thread->alive = 0;
		printf("%ld ms philo %d is dead ..\n", thread->local_time - thread->access->time, thread->number);
		pthread_mutex_unlock(&thread->access->napkin);
		pthread_mutex_unlock(&thread->access->print);
		return (1);
	}
	if (thread->alive == 0)
		return (1);
	return (0);
}

void	nihility(t_philo *philo)
{
	int	i;

	i = 1;
	pthread_mutex_unlock(&philo->print);
	pthread_mutex_destroy(&philo->print);
	pthread_mutex_unlock(&philo->napkin);
	pthread_mutex_destroy(&philo->napkin);
	while (i <= philo->number_of_philosophers)
	{
		pthread_mutex_unlock(&philo->thread[i].fork);
		pthread_mutex_destroy(&philo->thread[i].fork);
		pthread_mutex_unlock(philo->thread[i].next_fork);
		pthread_mutex_destroy(philo->thread[i].next_fork);
		pthread_join(philo->thread[i].thread, NULL);
		//free(philo->thread + i);
		i++;
	}
	free(philo);
}

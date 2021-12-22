#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "../inc/philo.h"
#include "../inc/macro.h"

long	get_time()
{
	struct timeval	tp;
	long	milliseconds;

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
		pthread_mutex_lock(&thread->fork);
		pthread_mutex_lock(&thread->access->print);
		pthread_mutex_lock(&thread->access->napkin);
		thread->miamed = get_time();
		printf("%ld ms	philo %d took a fork, unfortunately, no other fork are in sight ... \n", get_time() - thread->access->time, thread->number);
		usleep(thread->access->time_to_die * 1000);
		if (sky_time(thread) == 1)
			nihility(thread->access);
		return (0);
	}
	else
		while (thread->alive == 1)
		{
				miam_time(thread);
				sleep_time(thread);
		}
	return (0);
}

void	main_shit(t_philo *philo)
{
	int	i;

	i = 1;
	philo->time = get_time(); // temps de reference;
	while (i <= philo->number_of_philosophers) //boucle pour traiter tout les philos jusqua ce qu'il y en ait un qui meurt
	{
		if (philo->famished == 1)
		{
			philo->thread[i].local_time = philo->time;
			if (pthread_create(&philo->thread[i].thread, NULL, menu, &philo->thread[i]) != 0)
				error_san(ERRNO4, ERRMSG4);
		}
		usleep(1);
		if (philo->thread[i].alive == 0)
			return ;
		philo->full++;
		i++;
	}
	return ;
}

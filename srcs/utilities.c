/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <jbuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:45:32 by juan              #+#    #+#             */
/*   Updated: 2022/02/09 07:50:47 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/macro.h"
#include "../lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void	error_san(int error, char *error_msg, int errorp)
{
	if (error == ERRNO0)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO1)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO3)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO4)
		write(2, error_msg, ft_strlen(error_msg));
	errorp = 1;
}

void	death(t_philo *philo, int i)
{
	pthread_mutex_lock(&philo->print);
	philo->thread[i].local_time = get_time();
	printf("%ld ms	philo %d is dead\n", get_time()
		- philo->time, philo->thread[i].number);
	pthread_mutex_unlock(&philo->print);
	philo->dead = 1;
}

void	ft_usleep(long time)
{
	long	reference_time;

	reference_time = get_time();
	while (get_time() - reference_time < time)
		usleep(time);
}

void	init_fork(t_philo *philo)
{
	int	i;

	i = 0;
	philo->fork = malloc(sizeof(pthread_mutex_t) 
	* philo->number_of_philosophers);
	philo->next_fork = malloc(sizeof(pthread_mutex_t) 
	* philo->number_of_philosophers);
	while (i < philo->number_of_philosophers)
	{
		pthread_mutex_init(&philo->fork[i], NULL);
		i++;
	}
	i = 0;
	while (i < philo->number_of_philosophers)
	{
		if (i == 0)
			philo->next_fork[i] = 
			philo->fork[philo->number_of_philosophers - 1];
		else
			philo->next_fork[i] = philo->fork[i - 1];
	}
}

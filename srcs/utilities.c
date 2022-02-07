/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <jbuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:45:32 by juan              #+#    #+#             */
/*   Updated: 2022/02/07 11:53:39 by juan             ###   ########.fr       */
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
	philo->thread[i].local_time = get_time();
	printf("%ld ms	philo %d is dead\n", get_time()
		- philo->time, philo->thread[i].number);
	philo->dead = 1;
}

void	ft_usleep(long time, t_thread *thread)
{
	long	reference_time;

	reference_time = get_time();
	pthread_mutex_lock(&thread->access->napkin);
	while (get_time() - reference_time < time)
		usleep(time);
	pthread_mutex_unlock(&thread->access->napkin);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:50:26 by juan              #+#    #+#             */
/*   Updated: 2021/12/01 17:18:19 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_philo	t_philo;

struct s_philo
{
	int	number_of_philosophers;
	int	time_to_eat;
	int	time_to_sleep;
	int	time_to_think;
	int	time_to_die;
	int	number_of_times_each_philosopher_must_eat;
};

#endif

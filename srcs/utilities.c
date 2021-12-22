/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <jbuan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:45:32 by juan              #+#    #+#             */
/*   Updated: 2021/12/15 17:13:03 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philo.h"
#include "../inc/macro.h"
#include "../lib/libft/libft.h"
#include <unistd.h>
#include <stdlib.h>

void	error_san(int error, char *error_msg)
{
	if (error == ERRNO0)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO1)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO2)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO3)
		write(2, error_msg, ft_strlen(error_msg));
	if (error == ERRNO4)
		write(2, error_msg, ft_strlen(error_msg));
}

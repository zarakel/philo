/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_double_dimension.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 18:32:30 by juan              #+#    #+#             */
/*   Updated: 2022/01/18 18:32:32 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	free_double_dimension(char **str)
{
	char	**tmp;

	tmp = str;
	while (*tmp)
		free(*tmp++);
	free(str);
}

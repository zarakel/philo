/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc_double_dimension.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 17:31:37 by jbuan             #+#    #+#             */
/*   Updated: 2021/12/01 17:31:58 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	**malloc_map_arr(char **lines)
{
	int		i;
	char	**ptr;

	ptr = 0;
	i = 0;
	while (lines[i])
		i++;
	ptr = malloc(sizeof(char *) * (i + 1));
	return (ptr);
}

char	**malloc_and_strdup_string(char **argv)
{
	char	**ptr;
	char	*tmp;
	int		i;

	ptr = NULL;
	tmp = NULL;
	ptr = malloc_map_arr(argv);
	if (!ptr)
		exit(0);
	i = 0;
	while (ptr[i])
	{
		ptr[i] = ft_strdup(tmp);
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

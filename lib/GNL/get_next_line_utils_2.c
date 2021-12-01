/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_2.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 18:59:19 by juan              #+#    #+#             */
/*   Updated: 2021/11/24 19:01:06 by juan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strdup(char *s1)
{
	char	*dst;
	int		i;

	i = ft_strlen(s1);
	dst = (char *)malloc(sizeof(*dst) * (i + 1));
	if (!(dst))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_gnl_strjoin(char *s1, char *s2)
{
	char	*c;
	size_t	lena;
	size_t	lenb;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_gnl_strdup(s2));
	if (!s2)
		return (ft_gnl_strdup(s1));
	lena = ft_strlen(s1);
	lenb = ft_strlen(s2);
	c = (char *)malloc(sizeof(char) * (lena + (lenb + 1)));
	if (!c)
		return (NULL);
	ft_strlcpy(c, s1, lena + 1);
	free(s1);
	ft_strlcat(c + (lena), s2, lenb + 1);
	return (c);
}

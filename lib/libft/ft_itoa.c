/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 13:55:16 by jbuan             #+#    #+#             */
/*   Updated: 2021/05/02 14:44:28 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int	nbl(unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static char	*trad(int n, unsigned int nb, unsigned int len, char *dst)
{
	int	i;

	if (n < 0)
		dst[0] = '-';
	i = len - 1;
	while (nb >= 10)
	{
		dst[i] = nb % 10 + '0';
		nb = nb / 10;
		i--;
	}
	dst[i] = nb % 10 + '0';
	dst[len] = '\0';
	return (dst);
}

char	*ft_itoa(int n)
{
	char			*dst;
	unsigned int	len;
	unsigned int	nb;

	if (n >= 0)
	{
		nb = n;
		len = nbl(nb);
	}
	if (n < 0)
	{
		nb = -n;
		len = nbl(nb);
		len++;
	}
	dst = (char *)malloc(sizeof(char) * len + 1);
	if (!dst)
		return (NULL);
	return (trad(n, nb, len, dst));
}

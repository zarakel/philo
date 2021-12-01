/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 08:55:49 by jbuan             #+#    #+#             */
/*   Updated: 2021/05/31 15:21:27 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	compteur_sot(char *stock)
{
	int	i;

	i = 0;
	while (stock[i])
	{
		if (stock[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	etapres(char **stock, char **line, int i)
{
	char	*tmp;
	int		len;

	(*stock)[i] = '\0';
	*line = ft_gnl_strdup(*stock);
	len = ft_strlen(*stock + i + 1);
	if (len == 0)
	{
		free(*stock);
		*stock = 0;
		return (1);
	}
	tmp = ft_gnl_strdup(*stock + i + 1);
	free(*stock);
	*stock = tmp;
	return (1);
}

int	vraiment(char **stock, char **line, int bitslus)
{
	int	i;

	if (bitslus < 0)
		return (-1);
	i = compteur_sot(*stock);
	if ((*stock) && (i >= 0))
		return (etapres(stock, line, i));
	else if (*stock)
	{
		*line = *stock;
		*stock = 0;
		return (0);
	}
	*line = ft_gnl_strdup("");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*stock;
	int			i;
	int			bitslus;
	char		buff[BUFFER_SIZE + 1];

	if ((fd < 0) || (line == 0) || (BUFFER_SIZE <= 0))
		return (-1);
	bitslus = BUFFER_SIZE;
	while (bitslus == BUFFER_SIZE)
	{
		bitslus = read(fd, buff, BUFFER_SIZE);
		if (bitslus < 0)
			return (-1);
		buff[bitslus] = '\0';
		stock = ft_gnl_strjoin(stock, buff);
		i = compteur_sot(stock);
		if (i >= 0)
			return (etapres(&stock, line, i));
	}
	return (vraiment(&stock, line, bitslus));
}

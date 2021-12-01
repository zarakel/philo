/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbuan <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 16:52:51 by jbuan             #+#    #+#             */
/*   Updated: 2021/05/20 16:53:58 by jbuan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef FD_MAX
#  define FD_MAX 255
# endif

int		get_next_line(int fd, char **line);
int		count_newline(char *stock);
int		find_line(char **stock, char **line, int i);
int		check_line(char **stock, char **line, int bitslus);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);

#endif

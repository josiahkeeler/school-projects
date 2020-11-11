/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 19:19:22 by jokeeler          #+#    #+#             */
/*   Updated: 2020/10/07 20:17:14 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_del(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
		return (1);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*d[FD_LIMIT];
	long		r;
	char		*b;

	if (fd > -1 && !d[fd])
		d[fd] = ft_strnew(BUFFER_SIZE + 1);
	if (fd < 0 || BUFFER_SIZE < 1 || !line || !d[fd] ||
		(read(fd, d[fd], 0)) < 0 || !(r = 1))
		return (-1 * ft_del(&d[fd]));
	b = d[fd];
	*line = ft_strnew(1);
	while (d[fd][0] != '\n')
	{
		if (!d[fd][0])
		{
			if (!(r = read(fd, b, BUFFER_SIZE)))
				break ;
			b[r] = '\0';
			d[fd] = b;
		}
		d[fd] += ft_strappend(d[fd], line);
	}
	ft_strcpy(d[fd] + (!r ? 0 : 1), b, BUFFER_SIZE);
	d[fd] = b;
	return (!r ? 0 * ft_del(&d[fd]) : 1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 15:38:44 by jokeeler          #+#    #+#             */
/*   Updated: 2020/10/07 20:17:27 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define FD_LIMIT 12288

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(char *str);
char	*ft_strnew(size_t size);
void	ft_strcpy(char *src, char *dst, size_t len);
size_t	ft_strappend(char *src, char **dst);
int		get_next_line(const int fd, char **line);

#endif

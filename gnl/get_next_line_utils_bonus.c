/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 10:38:24 by jokeeler          #+#    #+#             */
/*   Updated: 2020/10/07 20:17:16 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str && str[len] && str[len] != '\n')
		len++;
	return (len);
}

char	*ft_strnew(size_t size)
{
	char	*str;
	size_t	i;

	if (!(str = malloc(sizeof(char *) * size)))
		return (NULL);
	i = 0;
	while (i < size)
		str[i++] = '\0';
	return (str);
}

void	ft_strcpy(char *src, char *dst, size_t len)
{
	size_t i;

	i = 0;
	while (src && *src && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

size_t	ft_strappend(char *src, char **dst)
{
	size_t	srcl;
	size_t	dstl;
	char	*buf;

	srcl = ft_strlen(src);
	dstl = ft_strlen(*dst);
	if (!(buf = ft_strnew(srcl + dstl + 1)))
		return (0);
	ft_strcpy(*dst, buf, dstl);
	if (*dst)
		free(*dst);
	*dst = buf;
	ft_strcpy(src, &buf[dstl], srcl);
	return (srcl);
}

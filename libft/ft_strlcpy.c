/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:59:30 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/15 20:22:51 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	if (!dst || !src)
		return (0);
	i = 0;
	while (size && i < size - 1 && src[i] && (dst[i] = src[i]))
		i++;
	if (size)
		dst[i] = '\0';
	return (ft_strlen(src));
}

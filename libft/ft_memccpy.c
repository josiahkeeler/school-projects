/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:53:18 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/16 10:10:19 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			m;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	m = 0;
	while (m < n && (d[m] = s[m]) && (unsigned char)d[m] != (unsigned char)c)
		m++;
	if (s[m] == (unsigned char)c)
		return (&d[m + 1]);
	return (NULL);
}

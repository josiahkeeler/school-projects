/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:53:59 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/17 20:21:15 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*t;
	unsigned char		x;

	t = (const unsigned char *)s;
	x = (unsigned char)c;
	while (n)
	{
		if (*t == x)
			return ((void *)t);
		else
			++t;
		--n;
	}
	return (NULL);
}

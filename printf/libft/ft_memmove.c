/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:40:39 by jokeeler          #+#    #+#             */
/*   Updated: 2020/05/22 22:19:32 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*s;
	char	*d;
	size_t	i;

	i = -1;
	s = (char *)src;
	d = (char *)dest;
	if ((src || dest) && s < d)
	{
		while (n-- > 0)
			d[n] = s[n];
	}
	else if (src || dest)
	{
		while (++i < n)
			d[i] = s[i];
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:54:36 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/16 23:16:22 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*t1;
	unsigned char	*t2;
	size_t			i;

	if (n == 0)
		return (0);
	t1 = (unsigned char *)s1;
	t2 = (unsigned char *)s2;
	i = 0;
	while (n && i < n - 1 && (unsigned char)t1[i] == (unsigned char)t2[i])
		i++;
	return ((unsigned char)t1[i] - (unsigned char)t2[i]);
}

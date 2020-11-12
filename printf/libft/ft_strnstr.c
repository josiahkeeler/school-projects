/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:55:56 by jokeeler          #+#    #+#             */
/*   Updated: 2020/03/10 14:36:39 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	n;

	if (!(*little))
		return ((char *)big);
	while (*big && len-- > 0)
	{
		n = 0;
		while (big[n] == little[n] && big[n] && little[n] && n <= len)
			n++;
		if (!(little[n]))
			return ((char *)big);
		big++;
	}
	return (NULL);
}

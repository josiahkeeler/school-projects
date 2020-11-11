/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:51:07 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/16 10:24:11 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*r;
	size_t	i;

	if (!s || !(r = ft_calloc(ft_strlen(s) + 1, sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		r[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (r);
}

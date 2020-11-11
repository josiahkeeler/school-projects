/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 21:19:21 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/16 10:06:08 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	len = 0;
	while (ft_strchr(set, *s1) && *s1)
		s1++;
	while (s1[len])
		len++;
	while (ft_strchr(set, s1[len]) && *s1)
		len--;
	if (!(trim = (char *)ft_calloc(++len + 1, sizeof(char))))
		return (NULL);
	while (len-- > 0)
		trim[len] = s1[len];
	return (trim);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 21:57:46 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/16 13:37:15 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int		word(char const *s, char *t, char **array, size_t i)
{
	size_t	l;

	if (!t)
		l = (long)ft_strlen(s) + 1;
	else
		l = t - s + 1;
	if (!(array[i] = (char *)ft_calloc(l, sizeof(char))))
		return (0);
	return (1);
}

char			**ft_split(char const *s, char c)
{
	size_t	strings;
	size_t	i;
	char	**array;
	char	*t;

	if (!s)
		return (NULL);
	strings = count(s, c);
	i = 0;
	if (!(array = (char **)malloc(sizeof(char *) * (strings + 1))))
		return (NULL);
	array[strings] = NULL;
	while (strings && s && *s)
	{
		while (*s && *s == c)
			s++;
		t = ft_strchr(s, c);
		if (!word(s, t, array, i))
			return (NULL);
		ft_strlcpy(array[i++], s, !t ? (long)ft_strlen(s) + 1 : t - s + 1);
		s = t;
		while (s && *s && *s == c)
			s++;
	}
	return (array);
}

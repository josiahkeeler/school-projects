/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:55:54 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/17 14:11:15 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*t;
	size_t	size;

	size = ft_strlen(s) + 1;
	if (!(t = (char *)malloc(sizeof(char) * size)))
		return (NULL);
	ft_strlcpy(t, s, size);
	return (t);
}

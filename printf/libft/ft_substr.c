/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 15:54:39 by josiahkeele       #+#    #+#             */
/*   Updated: 2020/07/16 10:46:18 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	l;

	if (!s || !(substr = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	l = ft_strlen(s);
	while (i < len && start < l && s[start])
		substr[i++] = s[start++];
	substr[len] = '\0';
	return (substr);
}

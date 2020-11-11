/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 18:55:59 by jokeeler          #+#    #+#             */
/*   Updated: 2020/05/15 22:10:50 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *tmp;

	tmp = s;
	while (*tmp)
		tmp++;
	while (tmp - s != 0 && *tmp != c)
		tmp--;
	if (*tmp == c)
		return ((char *)tmp);
	return (NULL);
}

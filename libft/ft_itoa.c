/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/22 22:57:31 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/16 11:02:42 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*ret;
	size_t	len;

	i = n;
	len = (i < 0) ? 1 : 0;
	while ((i /= 10))
		len++;
	if (!(ret = (char *)ft_calloc(len + 2, sizeof(char))))
		return (NULL);
	if (!n || n == -2147483648)
	{
		if (!(n /= 10))
			ret[0] = '0';
		else
			ret[len--] = '8';
	}
	while (n)
	{
		ret[len--] = (n < 0) ? n * -1 % 10 + '0' : n % 10 + '0';
		(n / 10 == 0 && n < 0) ? (ret[len--] = '-') : 0;
		n /= 10;
	}
	return (ret);
}

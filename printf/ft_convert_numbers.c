/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:31:21 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/19 00:23:17 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlong(long n)
{
	char buf[20];
	int i;
	unsigned int loop;

	i = 0;
	loop = 1;
	ft_bzero(buf, 20);
	while (loop)
	{
		buf[i++] = n % 10 + '0';
		n /= 10;
		loop = n;
	}
	while (i)
		ft_putchar_fd(buf[--i], 1);
}
// ft_convert_dec

// ft_convert_int

// ft_convert_unsigned_dec

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                   +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 22:07:18 by jokeeler          ##    #+#             */
/*   Updated: 2021/03/13 22:11:07 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned long n, char specifier)
{
	char hex[20];
	int i;
	unsigned long loop;
	char *base16;

	i = 0;
	loop = 1;
	ft_bzero(hex, 20);
	base16 = specifier == 'X' ? HEX_UP : HEX_LOW;
	while (loop)
	{
		hex[i++] = base16[n % 16];
		n /= 16;
		loop = n;
	}
	while (i)
		ft_putchar_fd(hex[--i], 1);
}
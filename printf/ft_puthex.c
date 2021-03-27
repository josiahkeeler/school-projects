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
	char			hex[20];
	int				i;
	unsigned long	loop;
	char			*base16;

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

void	ft_putuint(unsigned int n)
{
	if (n > 9)
		ft_putuint(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

int	ft_intlen(long n, int div)
{
	int	i;

	i = 0;
	if (n <= 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n /= div;
		i++;
	}
	return (i);
}

int	ft_ulen(unsigned long n, int div)
{
	int	i;

	i = 0;
	if (!n)
		i++;
	while (n)
	{
		n /= div;
		i++;
	}
	return (i);
}

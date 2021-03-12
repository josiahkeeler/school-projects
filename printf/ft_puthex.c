/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josiahkeeler <josiahkeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 16:58:50 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/11 17:08:32 by josiahkeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>


void	ft_put_hex(unsigned int n, char specifier) //takes unsigned int
{
	char hex[9];
	int i;

	i = 0;
	ft_bzero(hex, 9);
	if (specifier == 'X')
	{
		while (n > 0) // doesn't work when n == 0
		{
			hex[i++] = HEX_UP[n % 16];
			n /= 16;
		}
	}
	while (i-- > 0)
		ft_putchar_fd(hex[i], 1);
}

int	main(void)
{
	int x = 0;
	ft_put_hex(x, 'X');
	printf("\n%X\n", x);
	return (0);
}
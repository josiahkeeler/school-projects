/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josiahkeeler <josiahkeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:31:21 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/05 23:37:25 by josiahkeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_puthex(unsigned int n, char specifier) //takes unsigned int
{
	char hex[9];
	int i;

	i = 0;
	ft_bzero(hex, 9)
	if (specifier == 'X')
	{
		while (n > 0)
		hex[i++] = HEX_UP[n % 16];
		n /= 16;
	}
	while (i-- > 0)
		ft_putchar_fd(hex[i], 1);
}

void	ft_convert_hex(const *input, va_list ap)
{
	if (*input && (*input == 'x' || *input == 'X'))
	{

	} 
}
void	ft_convert_ptr(const *input, va_list ap)
{
	void *ptr;

	if (*input && *input == 'p')
	{
		ptr = (void *)va_arg(ap, void *); //ptr is unsigned long (8 bytes)
		
	}
}

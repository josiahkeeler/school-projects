/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:31:21 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/23 16:15:05 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_putuint(unsigned int n)
{
	if (n > 9)
		ft_putuint(n / 10);
	ft_putchar_fd(n % 10 + '0', 1);
}

void		ft_convert_numbers(const char *input, va_list ap)
{
	if (*input && (*input == 'i' || *input == 'd'))
		ft_putnbr_fd(va_arg(ap, int), 1);
	else if (*input && *input == 'u')
		ft_putuint(va_arg(ap, unsigned int));
	else if (*input && (*input == 'x' || *input == 'X'))
		ft_puthex((unsigned long)va_arg(ap, int), *input);
	else if (*input && *input == 'p')
	{
		ft_putstr_fd("0x", 1);
		ft_puthex((unsigned long)va_arg(ap, void *), 'x');
	}	
}
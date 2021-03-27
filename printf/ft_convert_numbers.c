/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:31:21 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/26 17:54:08 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_int(const char *input, va_list ap, t_format *flags)
{
	int	len;
	int	n;
	
	if (*input && (*input == 'i' || *input == 'd'))
	{
		n = va_arg(ap, int);
		len = ft_intlen(ft_abs(n), 10);
		if (n < 0)
			flags->width -= 1;
		if ((flags->mem & 1) == 1 && (flags->precision > len || !flags->precision))
			len = flags->precision;
		if ((flags->mem & 14) == 2)
			ft_putlchar(' ', flags->width - len);
		if (n < 0)
			ft_putchar_fd('-', 1);
		if ((flags->mem & 15) == 6)
			ft_putlchar('0', flags->width - len);
		if ((flags->mem & 5) == 1)
			ft_putlchar('0', flags->precision - ft_intlen(ft_abs(n), 10));
		if (n == -2147483648)
			ft_putstr_fd("2147483648", 1);
		else if (!(flags->mem & 1) || flags->precision != 0)
			ft_putnbr_fd(ft_abs(n), 1);
		if ((flags->mem & 10) == 10)
			ft_putlchar(' ', flags->width - len);
	}
}

void	ft_convert_uint(const char *input, va_list ap, t_format *flags)
{
	int				len;
	unsigned int	n;

	if (*input && *input == 'u')
	{
		n = va_arg(ap, int);
		len = ft_intlen(n, 10);
		if ((flags->mem & 1) == 1 && (flags->precision > len || !flags->precision))
			len = flags->precision;
		if ((flags->mem & 14) == 2)
			ft_putlchar(' ', flags->width - len);
		if ((flags->mem & 15) == 6)
			ft_putlchar('0', flags->width - len);
		if ((flags->mem & 1) == 1)
			ft_putlchar('0', flags->precision - ft_intlen(n, 10));
		if (!(flags->mem & 1) || flags->precision != 0)
			ft_putuint(n);
		if ((flags->mem & 10) == 10)
			ft_putlchar(' ', flags->width - len);
	}
}

void	ft_convert_hex(const char *input, va_list ap, t_format *flags)
{
	int		len;
	long	n;

	if (*input && (*input == 'x' || *input == 'X'))
	{
		n = va_arg(ap, long);
		len = ft_intlen(n, 16);
		if ((flags->mem & 1) == 1 && (flags->precision > len || !flags->precision))
			len = flags->precision;
		if ((flags->mem & 14) == 2)
			ft_putlchar(' ', flags->width - len);
		if ((flags->mem & 15) == 6)
			ft_putlchar('0', flags->width - len);
		if ((flags->mem & 1) == 1)
			ft_putlchar('0', flags->precision - ft_intlen(n, 16));
		if (!(flags->mem & 1) || flags->precision != 0)
			ft_puthex(n, *input);
		if ((flags->mem & 10) == 10)
			ft_putlchar(' ', flags->width - len);
	}
}

void	ft_convert_ptr(const char *input, va_list ap, t_format *flags)
{
	unsigned long	ptr;
	int				len;

	if (*input && *input == 'p')
	{
		ptr = (unsigned long)va_arg(ap, void *);
		len = ft_ulen(ptr, 16) + 2;
		if ((flags->mem & 10) == 2)
			ft_putlchar(' ', flags->width - len);
		ft_putstr_fd("0x", 1);
		ft_puthex(ptr, 'x');
		if ((flags->mem & 10) == 10)
			ft_putlchar(' ', flags->width - len);
	}	
}

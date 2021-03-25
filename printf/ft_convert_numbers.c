/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:31:21 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/25 14:22:55 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_int(const char *input, va_list ap, t_format *flags)
{
	int		len;
	int		n;

	if (*input && (*input == 'i' || *input == 'd'))
	{
		n = va_arg(ap, int);
		len = ft_intlen(n, 10);
		if ((flags->mem & 1) == 1 && flags->precision >= len)
			len = flags->precision;
		if ((flags->mem & 10) == 2)
			ft_putlchar(' ', flags->width - len);
		if ((flags->mem & 1) == 1)
			ft_putlchar('0', flags->precision - len);
		ft_putnbr_fd(n, 1);
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
		if ((flags->mem & 1) == 1 && flags->precision >= len)
			len = flags->precision;
		if ((flags->mem & 10) == 2)
			ft_putlchar(' ', flags->width - len);
		if ((flags->mem & 1) == 1)
			ft_putlchar('0', flags->precision - len);
		ft_putuint(n);
		if ((flags->mem & 10) == 10)
			ft_putlchar(' ', flags->width - len);
	}
}

void	ft_convert_hex(const char *input, va_list ap, t_format *flags)
{
	int	len;
	int	n;

	if (*input && (*input == 'x' || *input == 'X'))
	{
		n = va_arg(ap, int);
		len = ft_intlen(n, 16);
		if ((flags->mem & 1) == 1 && flags->precision >= len)
			len = flags->precision;
		if ((flags->mem & 10) == 2)
			ft_putlchar(' ', flags->width - len);
		if ((flags->mem & 1) == 1)
			ft_putlchar('0', flags->precision - len);
		ft_puthex((unsigned long)n, *input);
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

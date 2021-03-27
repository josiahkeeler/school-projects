/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:10:54 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/26 17:46:14 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlchar(int c, int len)
{
	int	i;

	i = 0;
	while (i++ < len)
		ft_putchar_fd(c, 1);
}

void	ft_putlstr(char *str, int len)
{
	int	i;

	i = 0;
	while (*str && i++ < len)
		ft_putchar_fd(*str++, 1);
}

void	ft_convert_char(const char *input, va_list ap, t_format *flags)
{
	if (*input && *input == 'c')
	{
		if ((flags->mem & 10) == 2)
			ft_putlchar(' ', flags->width - 1);
		ft_putchar_fd(va_arg(ap, int), 1);
		if ((flags->mem & 10) == 10)
			ft_putlchar(' ', flags->width - 1);
	}
	else if (*input && *input == '%')
	{
		if ((flags->mem & 14) == 2)
			ft_putlchar(' ', flags->width - 1);
		if ((flags->mem & 14) == 6)
			ft_putlchar('0', flags->width - 1);
		ft_putchar_fd('%', 1);
		if ((flags->mem & 10) == 10)
			ft_putlchar(' ', flags->width - 1);
	}
}

void	ft_convert_str(const char *input, va_list ap, t_format *flags)
{
	char	*str;
	int		len;

	if (*input && *input == 's')
	{
		str = va_arg(ap, char *);
		if (!str || (flags->precision < 0 && flags->width < 0))
			str = "(null)";
		len = ft_strlen(str);
		if ((flags->mem & 1) == 1 && flags->precision <= len && flags->precision >= 0)
			len = flags->precision;
		if ((flags->mem & 10) == 2)
			ft_putlchar(' ', flags->width - len);
		if ((flags->mem & 1) == 1 && flags->precision <= len && flags->precision >= 0)
			ft_putlstr(str, flags->precision);
		else if (str)
			ft_putstr_fd(str, 1);
		if ((flags->mem & 10) == 10)
			ft_putlchar(' ', flags->width - len);
	}
}
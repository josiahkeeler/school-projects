/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:10:54 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/25 13:44:16 by jokeeler         ###   ########.fr       */
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
	while (i++ < len)
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
		ft_putchar_fd('%', 1);
}

void	ft_convert_str(const char *input, va_list ap, t_format *flags)
{
	char	*str;
	int		len;

	if (*input && *input == 's')
	{
		str = va_arg(ap, char *);
		len = ft_strlen(str);
		if ((flags->mem & 1) == 1)
			len = flags->precision;
		if ((flags->mem & 10) == 2)
			ft_putlchar(' ', flags->width - len);
		if ((flags->mem & 1) == 1 && flags->precision <= len)
			ft_putlstr(str, flags->precision);
		else
			ft_putstr_fd(str, 1);
		if ((flags->mem & 10) == 10)
			ft_putlchar(' ', flags->width - len);
	}
}

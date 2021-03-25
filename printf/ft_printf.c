/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:31:36 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/25 14:54:08 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *input, ...)
{
	va_list		ap;
	size_t		i;
	t_format	flags;

	i = 0;
	va_start(ap, input);
	while (*input)
	{
		input = str_loop(input);
		init_flags(&flags);
		input = arg_loop(input, ap, &flags);
	}
	va_end(ap);
	return (i);
}

void	init_flags(t_format *flags)
{
	flags->mem = 0;
	flags->width = 0;
	flags->precision = 0;
}

const char	*str_loop(const char *input)
{
	size_t		i;
	const char	*start;

	start = input;
	i = 0;
	while (*input != '%' && *input)
	{
		input++;
		i++;
	}
	write(1, start, i);
	return (input);
}

const char	*arg_loop(const char *input, va_list ap, t_format *flags)
{
	if (*input == '%')
	{
		input++;
		input = ft_flags0(input, ap, flags);
		input = ft_flags1(input, ap, flags);
		ft_convert_char(input, ap, flags);
		ft_convert_str(input, ap, flags);
		ft_convert_int(input, ap, flags);
		ft_convert_uint(input, ap, flags);
		ft_convert_hex(input, ap, flags);
		ft_convert_ptr(input, ap, flags);
		input++;
	}
	else if (*input)
		input++;
	return (input);
}

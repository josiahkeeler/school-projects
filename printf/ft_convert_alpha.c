/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josiahkeeler <josiahkeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:10:54 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/02/26 16:47:39 by josiahkeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_char(const char *input, va_list ap)
{
	if (*input && *input == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
}

void	ft_convert_str(const char *input, va_list ap)
{
	if (*input && *input == 's')
	{
		ft_putstr_fd(va_arg(ap, char *), 1);
		input++;
	}
}

void	ft_convert_spec(const char *input)
{
	if (*input && *input == '%')
	{
		ft_putchar_fd('%', 1);
		input++;
	}
}

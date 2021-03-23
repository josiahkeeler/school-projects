/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_alpha.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:10:54 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/22 15:44:52 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_alpha(const char *input, va_list ap)
{
	if (*input && *input == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (*input && *input == 's')
		ft_putstr_fd(va_arg(ap, char *), 1);
	else if (*input && *input == '%')
		ft_putchar_fd('%', 1);
}
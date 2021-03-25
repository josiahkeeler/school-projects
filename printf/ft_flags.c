/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:10:51 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/25 14:53:31 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_flags0(const char *input, va_list ap, t_format *flags)
{
	char	buf[10];
	int		i;

	ft_bzero(buf, 10);
	i = 0;
	if (*input && (*input == '-' || *input == '0'))
	{
		flags->mem += *input == '-' ? 8 : 4;
		input++;
	}
	if (*input && *input == '*')
	{
		flags->width = va_arg(ap, int);
		flags->mem += 2;
		input++;
	}
	else if (*input && ft_isdigit((*input)))
	{
		while (*input && ft_isdigit(*input))
			buf[i++] = *input++;
		flags->width = ft_atoi(buf);
		flags->mem += 2;
	}
	return (input);
}

const char	*ft_flags1(const char *input, va_list ap, t_format *flags)
{
	char	buf[10];
	int		i;

	if (*input && *input == '.')
	{
		input++;
		if (*input && *input == '*')
			flags->precision = va_arg(ap, int);
		else
		{
			i = 0;
			ft_bzero(buf, 10);
			while (*input && ft_isdigit(*input))
				buf[i++] = *input++;
			flags->precision = ft_atoi(buf);
		}
		flags->mem += 1;
	}
	return (input);
}

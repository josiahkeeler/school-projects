/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:10:51 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/26 17:56:29 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

const char	*ft_flags0(const char *input, va_list ap, t_format *flags)
{
	char	buf[10];
	int		i;

	ft_bzero(buf, 10);
	i = 0;
	while (*input && (*input == '-' || *input == '0' || *input == ' '))
	{
		flags->mem |= *input == '-' ? 8 : 4;
		input++;
	}
	if (*input && *input == '*')
	{
		flags->width = va_arg(ap, int);
		flags->mem += 2;
		input++;
		if (flags->width < 0)
		{
			flags->width = ft_abs(flags->width);
			flags->mem |= 8;
		}
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
		{
			flags->precision = va_arg(ap, int);
			input++;
		}
		else
		{
			i = 0;
			ft_bzero(buf, 10);
			while (*input && ft_isdigit(*input))
				buf[i++] = *input++;
			flags->precision = ft_atoi(buf);
		}
		flags->mem += 1;
		flags->mem &= 11;
	}
	return (input);
}

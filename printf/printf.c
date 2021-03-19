/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:31:36 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/19 00:26:03 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "stdio.h"

/** malloc, free, write, va_start, va_arg, va_copy,
va_end


• The prototype of ft_printf should be int ft_printf(const char *, ...);
• You have to recode the libc’s printf function
• It must not do the buffer management like the real printf
• It will manage the following conversions: cspdiuxX%
https://alvinalexander.com/programming/printf-format-cheat-sheet/
• It will manage any combination of the following flags: ’-0.*’ and minimum field
width with all conversions
• It will be compared with the real printf
• You must use the command ar to create your librairy, using the command libtool
is forbidden. **/

int ft_printf(const char *input, ...)
{
	va_list ap;
	size_t i;

	i = 0;
	va_start(ap, input);
	while (*input)
	{
		input = str_loop(input);
		input = arg_loop(input, ap);
	}
	va_end(ap);
	return (i);
}

const char *str_loop(const char *input)
{
	size_t i;
	const char *start;

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

const char *arg_loop(const char *input, va_list ap)
{
	if (*input == '%')
	{
		input++;
		input = ft_flags(input);
		ft_convert_char(input, ap);
		ft_convert_str(input, ap);
		ft_convert_spec(input);
		ft_convert_ptr(input, ap);
		input++;
	}
	else if (*input)
		input++;
	return (input);
}


int main(void)
{
	char *str;

	str = "hello world";
	ft_printf("Test string.\nPrint $ = %------c\nPrint string = %s\nPrint %% = %%\n", '$', "string");
	ft_printf("Print string. [%s]\nprint pointer [%p]\n", str, str);
	printf("Print string. [%s]\nprint pointer [%p]\n", str, str);
	return (0);
}
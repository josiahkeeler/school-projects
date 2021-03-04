/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josiahkeeler <josiahkeeler@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/04 15:31:21 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/04 15:57:21 by josiahkeele      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_hex(unsigned int n) //takes unsigned int
{

}
void	ft_convert_hex(const *input, va_list ap)
{
	if (*input && (*input == 'x' || *input == 'X'))
	{

	} 
}
void	ft_convert_ptr(const *input, va_list ap)
{
	void *ptr;

	if (*input && *input == 'p')
	{
		ptr = (void *)va_arg(ap, void *); //ptr is unsigned long (8 bytes)
		
	}
}

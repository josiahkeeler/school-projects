/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/26 16:10:51 by josiahkeele       #+#    #+#             */
/*   Updated: 2021/03/22 15:59:08 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* flags are "-0.*"
- left justifies the field
0 Left-pads the number with zeroes (0) instead of spaces
* The width is not specified in the format string, 
	but as an additional integer value argument preceding the argument 
	that has to be formatted.
. precision field */
const char *ft_flags(const char *input)
{
	while (ft_strchr(FLAGS, *input))
	{
		input++;
	}
	return (input);
}
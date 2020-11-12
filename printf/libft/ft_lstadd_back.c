/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/20 18:34:30 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/16 23:53:37 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *head;

	if (!lst)
		return ;
	head = *lst;
	while (head && head->next)
		head = head->next;
	if (!head)
		*lst = new;
	else
		head->next = new;
}

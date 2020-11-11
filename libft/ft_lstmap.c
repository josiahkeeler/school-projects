/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jokeeler <jokeeler@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/03 13:50:09 by jokeeler          #+#    #+#             */
/*   Updated: 2020/07/17 20:29:51 by jokeeler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *head;
	t_list *new;

	head = NULL;
	while (lst)
	{
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&head, del);
			ft_lstdelone(new, del);
			return (NULL);
		}
		ft_lstadd_back(&head, new);
		lst = lst->next;
	}
	return (head);
}

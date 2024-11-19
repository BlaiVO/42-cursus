/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blvilarn <blvilarn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 16:19:19 by blvilarn          #+#    #+#             */
/*   Updated: 2024/08/21 15:33:33 by blvilarn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lstnew;
	t_list	*tmpnode;
	void	*content;

	if (!lst)
		return (NULL);
	lstnew = NULL;
	while (lst)
	{
		content = f(lst->content);
		tmpnode = ft_lstnew(content);
		if (!tmpnode)
		{
			del(content);
			ft_lstclear(&lstnew, del);
			return (NULL);
		}
		ft_lstadd_back(&lstnew, tmpnode);
		lst = lst->next;
	}
	return (lstnew);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:16:01 by assabich          #+#    #+#             */
/*   Updated: 2024/11/27 16:02:20 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_listnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_listclear(t_list **lst, void (*del)(void*))
{
	t_list	*actu;

	while (*lst)
	{
		actu = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = actu;
	}
	*lst = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlist;
	void	*ncontent;
	t_list	*nnode;
	t_list	*lnode;

	nlist = NULL;
	lnode = NULL;
	while (lst)
	{
		ncontent = f(lst->content);
		nnode = ft_listnew(ncontent);
		if (!nnode)
		{
			ft_listclear(&nlist, del);
		}
		if (!nlist)
			nlist = nnode;
		else
			lnode->next = nnode;
		lnode = nnode;
		lst = lst->next;
	}
	return (nlist);
}

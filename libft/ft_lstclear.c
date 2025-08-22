/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 12:14:07 by assabich          #+#    #+#             */
/*   Updated: 2024/11/26 12:36:05 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
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

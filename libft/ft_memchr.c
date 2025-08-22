/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 09:48:59 by assabich          #+#    #+#             */
/*   Updated: 2024/11/23 11:33:41 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	char	*s;
	size_t	i;

	s = (char *)src;
	i = 0;
	while (i < n)
	{
		if (s[i] == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

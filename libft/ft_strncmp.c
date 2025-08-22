/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:35:19 by assabich          #+#    #+#             */
/*   Updated: 2024/11/27 14:59:20 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		d;

	i = 0;
	while (i < n && (*(s1 + i) || *(s2 + i)))
	{
		d = *((unsigned char *)s1 + i) - *((unsigned char *)s2 + i);
		if (d)
			return (d);
		i++;
	}
	return (0);
}

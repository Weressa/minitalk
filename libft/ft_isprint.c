/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 11:00:28 by assabich          #+#    #+#             */
/*   Updated: 2024/11/13 11:42:14 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int	main()
{
	char	c;

	c = 'O';
	printf("Resultat du character:%c est: %d", c, isprint(c));
	printf("Resultat du character:%c est: %d", c, ft_isprint(c));
	c = '\n';
	printf("\nResultat du character:%c est: %d", c, isprint(c));
	printf("Resultat du character:%c est: %d", c, ft_isprint(c));
	return (0);
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:26:43 by assabich          #+#    #+#             */
/*   Updated: 2024/11/13 10:10:24 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include<stdio.h>
#include<ctype.h>

int	main()
{
	printf("\n Character used: %d", '0');
	printf("\n Resultat avec isalpha: %d", isalpha('0'));
	printf("\n Resultat avec ft_isalpha: %d", ft_isalpha('0'));
	return (0);
}*/

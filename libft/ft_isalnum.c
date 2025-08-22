/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 09:55:17 by assabich          #+#    #+#             */
/*   Updated: 2024/11/14 13:05:38 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
		return (1);
	return (0);
}
/*
#include <stdio.h>
#include <ctype.h>

int     main()
{
        char    c;

        c = '5';
        printf("When %c is passed, return value is %d\n", c, isalnum(c));
        printf("When %c is passed, return value is %d\n", c, ft_isalnum(c));
        c = 'Q';
        printf("\nWhen %c is passed, return value is %d\n", c, isalnum(c));
        printf("When %c is passed, return value is %d\n", c, ft_isalnum(c));
        c = 'l';
        printf("\nWhen %c is passed, return value is %d\n", c, isalnum(c));
        printf("When %c is passed, return value is %d\n", c, ft_isalnum(c));
        c = '+';
        printf("\nWhen %c is passed, return value is %d\n", c, isalnum(c));
        printf("When %c is passed, return value is %d\n", c, ft_isalnum(c));
        return (0);
}*/

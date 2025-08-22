/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:58:59 by assabich          #+#    #+#             */
/*   Updated: 2024/11/27 14:55:13 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	int		n;

	i = 0;
	s = 1;
	n = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if (str[i] == '-')
		s = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - '0';
		i++;
	}
	return (s * n);
}
/*
#include <stdio.h>

int     main(void)
{
        printf("42:%d\n", ft_atoi("  \n  42t4457"));
        printf("-42:%d\n", ft_atoi(" --+-42sfs:f545"));
        printf("0:%d\n", ft_atoi("\0 1337"));
        printf("0:%d\n", ft_atoi("-0"));
        printf("0:%d\n", ft_atoi(" - 1 3 2 5 6 3 2 1 6 7"));
        printf("-1325632167:%d\n", ft_atoi("-1325632167"));
        printf("-100:%d\n", ft_atoi("-100"));
        printf("min:%d\n", ft_atoi("\t---+2147483648"));
        printf("max:%d\n", ft_atoi("\v2147483647"));
}*/

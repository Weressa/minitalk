/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:45:36 by assabich          #+#    #+#             */
/*   Updated: 2024/11/22 17:54:34 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len(int n)
{
	int	taille;

	taille = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		taille += 1;
	while (n != 0)
	{
		n /= 10;
		taille++;
	}
	return (taille);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	int		taille;
	long	dig;

	dig = n;
	i = 0;
	taille = len(n);
	str = (char *)malloc((taille + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[taille] = '\0';
	if (dig < 0)
	{	
		str[0] = '-';
		i = 1;
		dig = -dig;
	}
	while (taille > i)
	{
		str[taille - 1] = (dig % 10) + '0';
		dig /= 10;
		taille--;
	}
	return (str);
}

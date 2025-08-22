/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ubase.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 15:42:35 by assabich          #+#    #+#             */
/*   Updated: 2024/12/08 16:03:17 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ubase(long n, int base)
{
	char	*symbol;
	int		count;

	symbol = "0123456789ABCDEF";
	count = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		count++;
	}
	if (n < base)
		count += write(1, &symbol[n], 1);
	else
	{
		count += ft_ubase(n / base, base);
		count += ft_ubase(n % base, base);
	}
	return (count);
}

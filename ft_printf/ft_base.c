/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 14:53:35 by assabich          #+#    #+#             */
/*   Updated: 2024/12/08 19:44:30 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base(long n, int base)
{
	char	*symbols;
	int		count;

	symbols = "0123456789abcdef";
	count = 0;
	if (n < 0 && base == 10)
	{
		count += write(1, "-", 1);
		n = -n;
	}
	if (n < base)
		count += write(1, &symbols[n], 1);
	else
	{
		count += ft_base(n / base, base);
		count += write(1, &symbols[n % base], 1);
	}
	return (count);
}

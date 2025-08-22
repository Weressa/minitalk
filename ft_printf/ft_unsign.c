/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 16:50:12 by assabich          #+#    #+#             */
/*   Updated: 2024/12/08 20:43:46 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsign(unsigned long n, int base)
{
	char	*symbol;
	int		count;

	symbol = "0123456789abcdef";
	count = 0;
	if (base < 2 || base > 16)
		return (0);
	if (n < (unsigned long)base)
		count += write(1, &symbol[n], 1);
	else
	{
		count += ft_unsign(n / base, base);
		count += ft_unsign(n % base, base);
	}
	return (count);
}

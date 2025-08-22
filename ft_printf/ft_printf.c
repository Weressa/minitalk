/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 18:45:43 by assabich          #+#    #+#             */
/*   Updated: 2024/12/11 11:08:14 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count += ft_putstr("(nil)");
	}
	else
	{
		count += ft_putstr("0x");
		count += ft_unsign((unsigned long)ptr, 16);
	}
	return (count);
}

int	ft_format(char specifier, va_list ap)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		count += ft_putchar(va_arg(ap, int));
	else if (specifier == 's')
		count += ft_putstr(va_arg(ap, char *));
	else if (specifier == 'd' || specifier == 'i')
		count += ft_base((long)va_arg(ap, int), 10);
	else if (specifier == 'x')
		count += ft_base((unsigned long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'X')
		count += ft_ubase((unsigned long)va_arg(ap, unsigned int), 16);
	else if (specifier == 'u')
		count += ft_unsign((unsigned long)va_arg(ap, unsigned int), 10);
	else if (specifier == 'p')
		count += ft_ptr(va_arg(ap, void *));
	else if (specifier == '%')
		count += write(1, &specifier, 1);
	else
		count += write(1, &specifier, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		i;

	va_start(ap, format);
	count = 0;
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (!format[i] || format[i] == ' ')
				return (-1);
			count += ft_format(format[i], ap);
		}
		else
			count += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (count);
}

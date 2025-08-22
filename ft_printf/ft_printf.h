/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:52:41 by assabich          #+#    #+#             */
/*   Updated: 2024/12/05 16:29:21 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_base(long n, int base);
int	ft_ubase(long n, int base);
int	ft_unsign(unsigned long n, int base);
int	ft_printf(const char *format, ...);

#endif

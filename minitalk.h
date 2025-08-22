/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 15:24:00 by assabich          #+#    #+#             */
/*   Updated: 2025/08/22 18:51:37 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

enum
{
	READY,
	BUSY,
};

void	ft_signal(int sig, void *handler, bool info);
void	ft_kill(pid_t pid, int sig);
int		ft_atoi(const char *str);

#endif

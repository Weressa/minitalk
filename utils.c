/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 16:12:09 by assabich          #+#    #+#             */
/*   Updated: 2025/08/22 19:07:25 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_signal(int sig, void *handler, bool info)
{
	struct sigaction	sa;

	ft_bzero(&sa, sizeof(sa));
	if (info)
	{
		sa.sa_flags = SA_SIGINFO;
		sa.sa_sigaction = handler;
	}
	else
		sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGUSR1);
	sigaddset(&sa.sa_mask, SIGUSR2);
	if (sigaction(sig, &sa, NULL) < 0)
	{
		write(2, "Sigaction failed\n", 17);
		exit(EXIT_FAILURE);
	}
}

void	ft_kill(pid_t pid, int sig)
{
	if (kill(pid, sig) < 0)
	{
		write (2, "kill failed\n", 12);
		exit(EXIT_FAILURE);
	}
}

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

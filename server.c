/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:23:19 by assabich          #+#    #+#             */
/*   Updated: 2025/08/22 19:23:09 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_end(unsigned char *c, pid_t client, int *bit)
{
	if (*c == '\0')
	{
		write(STDOUT_FILENO, "\n", 1);
		kill (client, SIGUSR2);
		*c = 0;
	}
	else
		write (STDOUT_FILENO, c, 1);
	*c = 0;
	*bit = 0;
}

void	handler(int sig, siginfo_t *info, void *more_info)
{
	static unsigned char	c;
	static int				bit;
	static pid_t			client;

	(void)more_info;
	if (info->si_pid)
		client = info->si_pid;
	if (sig == SIGUSR1)
		c |= (0b10000000 >> bit);
	bit++;
	if (bit == CHAR_BIT)
		print_end(&c, client, &bit);
	kill(client, SIGUSR1);
}

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 1)
	{
		write(2, "Launch with ./server\n", 20);
		return (EXIT_FAILURE);
	}
	ft_printf("Server PID= %d\n", getpid());
	ft_signal(SIGUSR1, handler, true);
	ft_signal(SIGUSR2, handler, true);
	while (1)
		pause();
	return (EXIT_SUCCESS);
}

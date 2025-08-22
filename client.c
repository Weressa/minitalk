/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: assabich <assabich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 15:23:37 by assabich          #+#    #+#             */
/*   Updated: 2025/08/22 17:09:12 by assabich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

volatile sig_atomic_t	g_server = BUSY;

static void	end_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "OK!", 3);
	exit(EXIT_SUCCESS);
}

static void	confirm_handler(int sig)
{
	(void)sig;
	g_server = READY;
}

static void	send_char(unsigned char c, pid_t server)
{
	int	bit;

	bit = 0;
	while (bit < CHAR_BIT)
	{
		if (c & (0x80 >> bit))
			ft_kill(server, SIGUSR1);
		else
			ft_kill(server, SIGUSR2);
		bit++;
		while (g_server == BUSY)
			usleep(42);
		g_server = BUSY;
	}
}

int	main(int ac, char **av)
{
	pid_t			server;
	unsigned char	*message;
	int				i;

	i = 0;
	if (ac != 3)
	{
		write(2, "Wrong number of arguments\n", 26);
		return (EXIT_FAILURE);
	}
	server = ft_atoi(av[1]);
	message = (unsigned char *)av[2];
	ft_signal(SIGUSR1, confirm_handler, false);
	ft_signal(SIGUSR2, end_handler, false);
	while (message[i])
		send_char(message[i++], server);
	send_char('\0', server);
	return (EXIT_SUCCESS);
}

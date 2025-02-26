/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:56:43 by bamezoua          #+#    #+#             */
/*   Updated: 2025/02/22 09:19:29 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signal, siginfo_t *info, void *context)
{
	static char	character = 0;
	static int	bit_count = 0;
	static int	client_pid = 0;

	if (client_pid != info->si_pid)
	{
		bit_count = 0;
		character = 0;
		client_pid = info->si_pid;
	}
	(void)context;
	character = (character << 1) | (signal == SIGUSR1);
	bit_count++;
	if (bit_count == 8)
	{
		if (character == '\0')
		{
			ft_putchar('\n');
		}
		else
			ft_putchar(character);
		bit_count = 0;
		character = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	signal_action;

	(void)av;
	if (ac != 1)
		return (ft_putstr("Usage: ./server\n"), 1);
	signal_action.sa_sigaction = handle_signal;
	signal_action.sa_flags = SA_SIGINFO;
	sigemptyset(&signal_action.sa_mask);
	if (sigaction(SIGUSR1, &signal_action, NULL) == -1 || sigaction(SIGUSR2,
			&signal_action, NULL) == -1)
		return (1);
	ft_putstr("Server PID: ");
	ft_putnbr(getpid());
	ft_putstr("\nListening...\n");
	while (1)
	{
	}
}

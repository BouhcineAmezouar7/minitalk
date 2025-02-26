/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 12:55:52 by bamezoua          #+#    #+#             */
/*   Updated: 2025/02/22 10:10:55 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_bit_signal(int pid, int bit)
{
	if (bit)
	{
		if (kill(pid, SIGUSR1) == -1)
		{
			write(1, "\n[ ==> error while sending <== ]\n\n", 35);
			exit(1);
		}
	}
	else
	{
		if (kill(pid, SIGUSR2) == -1)
		{
			write(1, "\n[ ==> error while sending <== ]\n\n", 35);
			exit(1);
		}
	}
	usleep(300);
}

void	send_character(int pid, char character)
{
	int	bit_index;

	bit_index = 7;
	while (bit_index >= 0)
	{
		send_bit_signal(pid, (character >> bit_index) & 1);
		bit_index--;
	}
}

void	send_message(int pid, char *message)
{
	while (*message)
	{
		send_character(pid, *message++);
	}
	send_character(pid, '\0');
}

void	handle_signal(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("✅✅ Done ✅✅\n");
}

int	main(int argc, char **argv)
{
	int					process_id;
	struct sigaction	signal_action;

	if (argc != 3)
	{
		ft_putstr("Usage: ./client <PID> <MESSAGE>\n");
		return (1);
	}
	process_id = ft_atoi(argv[1]);
	if (process_id <= 0 || process_id > 4194304)
		return (ft_putstr("Invalid PID\n"), 1);
	signal_action.sa_handler = handle_signal;
	signal_action.sa_flags = 0;
	if (sigaction(SIGUSR1, &signal_action, NULL) == -1)
		return (1);
	send_message(process_id, argv[2]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 11:37:11 by bamezoua          #+#    #+#             */
/*   Updated: 2025/02/22 10:24:09 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		n *= -1;
		ft_putchar('-');
	}
	if (n < 10)
	{
		ft_putchar('0' + n);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

int	ft_isdigit(int n)
{
	return ('0' <= n && n <= '9');
}

int	ft_atoi(const char *nbr)
{
	int (n), (s), (len);
	n = 0;
	s = 1;
	len = 0;
	while ((9 <= *nbr && *nbr <= 13) || *nbr == 32 || *nbr == '0')
		nbr++;
	if (*nbr == '-' || *nbr == '+')
	{
		if (*nbr == '-')
			s = -1;
		nbr++;
	}
	while (ft_isdigit(*nbr))
	{
		n = n * 10 + (*nbr - '0');
		if (len > 7)
			return (ft_putstr("Invalid PID\n"), exit(-1), -1);
		len++;
		nbr++;
	}
	if (*nbr)
		return (ft_putstr("Invalid PID\n"), exit(-1), -1);
	return (n * s);
}

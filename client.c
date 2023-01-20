/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:17 by htam              #+#    #+#             */
/*   Updated: 2023/01/17 12:51:19 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	fth(int n)
{
	write(1, "1", 1);
}
int	ft_send_sig(int pid, char *str)
{
	int	n;
	int bit;

	n = 0;
	while (str[n])
	{
		bit = 7;
		while (bit >= 0)
		{
			if ((str[n] >> bit & 1))
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			bit--;
			usleep(50);
		}
		usleep(50);
		n++;
	}
	return (0);
}

int	mini_atoi(char *str)
{
	int	n;
	int	rei;

	n = 0;
	rei = 0;
	while (str[n])
	{
		if (str[n] < '0' || str[n] > '9')
			return (0);
		rei = rei * 10 + str[n] - '0';
		n++;
	}
	if (rei > 4194304)
		return (0);
	return (rei);
}

int main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3)
		return (0);
	pid = mini_atoi(argv[1]);
	ft_send_sig(pid, argv[2]);


	return (0);
}
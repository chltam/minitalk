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
#include "./ft_printf/ft_printf.h"
int	ft_printf(const char *str, ...);

void	ft_send_sig(int pid, char *str)
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
			usleep(500);
		}
		usleep(50); 
		n++;
	}
	return ;
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
void	ft_test_hand(int pid, char c)
{
	int bit;
	
	bit = 7;
	while (bit >= 0)
	{
		if ((c >> bit & 1))
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		bit--;
		usleep(400);

	}
}
void	ft_feedback(int signum)
{
	if(signum == SIGUSR1)
		ft_printf("message received!\n");
	return ;
}

int main(int argc, char *argv[])
{
	int	pid;
	int	n; 

	n = 0;
	if (argc != 3)
		return (0);
	pid = mini_atoi(argv[1]);
	//ft_send_sig(pid, argv[2]);
	while (argv[2][n])
	{
		ft_test_hand(pid, argv[2][n]);
		usleep(100);
		n++;
	}
	ft_test_hand(pid, 0);

	signal(SIGUSR1, ft_feedback);
	pause();
	
	

	return (0);
}
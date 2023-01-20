/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 12:51:08 by htam              #+#    #+#             */
/*   Updated: 2023/01/17 12:51:10 by htam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
//240 159 152 129

void sighand(int signum, siginfo_t *info, void *v)
{
	static char	c;
	static int		bit;

	if (bit < 8)
	{
		if(signum == SIGUSR2)
			c = c | 128 >> bit;
		else
			c = c;
		bit++;
	}
	if (bit == 8)
	{
		write(1, &c, 1);
		//kill(SIGUSR1, info->si_pid);
		c = 0;
		bit = 0;
	}

	return ;
}

void print_pid(int nbr)
{
	if (nbr > 9)
	{
		print_pid(nbr / 10);
		nbr %= 10;
	}
	nbr += 48;
	write(1, &nbr, 1);
	return ;
}

int main()
{
	int pid;
	siginfo_t	*info;
	struct sigaction	sa;

	pid = getpid();
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighand;
	
	print_pid(pid);
	while(1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
			
	return (0);
}
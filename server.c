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
#include "./ft_printf/ft_printf.h"
//240 159 152 129
int	ft_printf(const char *str, ...);
void sighand(int signum, siginfo_t *info, void *v)
{
	static char	c;
	static int		bit;

	(void) v;
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
		if (c == 0)
		{
			kill(info->si_pid, 10);
		}
		write(1, &c, 1);
		c = 0;
		bit = 0;
	}
	return ;
}


int main()
{
	int pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("%d\n", pid);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = sighand;
	
	while(1)
	{
		sigaction(SIGUSR1, &sa, NULL);
		sigaction(SIGUSR2, &sa, NULL);
		pause();
	}
			
	return (0);
}
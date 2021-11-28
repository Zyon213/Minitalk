/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:53:27 by yonas             #+#    #+#             */
/*   Updated: 2021/11/29 02:45:46 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

/*
typedef struct s_signal
{
	unsigned int bit;
	char	symbol;
	int pid;
}		t_signal;

t_signal 	g_bites;
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
/*
void	handler_sigusr(int sig, siginfo_t *siginfo, void *context)
{
	static int 	i = 0;
	static pid_t client_pid = 0;
	static unsigned char c = 0;

	(void)context;
	if (!client_pid)
		client_pid = siginfo->si_pid;
	c |= (sig == SIGUSR2);
	if (++i == 8)
	{
		i = 0;
		if (!c)
		{
			kill(client_pid, SIGUSR2);
			client_pid = 0;
			return ;
		}
		ft_putchar(c);
		c = 0;
		kill(client_pid, SIGUSR1);
	}
	else
		c <<= 1;
}


/*
void	handler_sigusr(int num, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	if (num == SIGUSR1)
		g_bites.symbol += g_bites.bit;
	g_bites.bit >>= 1;
	if (!g_bites.bit)
	{
		if (!g_bites.symbol)
			ft_putchar('\n');
		else
			ft_putchar(g_bites.symbol);
		g_bites.bit = 0b10000000;
		g_bites.symbol = 0;
	}
	usleep(50);
	kill(info->si_pid, SIGUSR1);
}
*/
void	handler_sigusr(int signum, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	static char c = 0xFF;
	static int bits = 0;
	static char *msg = 0;

	if (signum == SIGUSR2)
	{
	//	write(1,"0",1);
		c ^= 0x80 >> bits;
	}
	else if (signum == SIGUSR1)
	{
	//	write(1,"1",1);
		c |= 0x80 >> bits;
	}
	bits++;
	if (bits == 8)
	{
		if (c)
		//	write(1,&c,1);
		//	printf("%c",c);
			ft_putchar(c);
		bits = 0;
		c = 0xFF;
	}
	usleep(100);
}
/*
void	handler_sigusr1(int signum)
{
//	(void)signum;
	write(1,"1",1);
}

void	handler_sigusr2(int signum)
{
//	(void)signum;
	write(1,"0",1);
}
*/
int	main(void)
{
	struct sigaction sact;

//	g_bites.symbol = 0;
//	g_bites.bit = 0b10000000;
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = &handler_sigusr;
	sigaction(SIGUSR1, &sact, 0);
	sigaction(SIGUSR2, &sact, 0);

	int pid;

	pid = getpid();
	printf("PID: %d\n",pid);
//	signal(SIGUSR1, handler_sigusr);
//	signal(SIGUSR2, handler_sigusr);
	while (1)
		pause();
}

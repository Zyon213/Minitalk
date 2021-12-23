/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:53:27 by yonas             #+#    #+#             */
/*   Updated: 2021/12/23 16:25:04 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_printmsg(char *msg)
{
	ft_putstr(msg);
	ft_putchar('\n');
	return (NULL);
}

void	send_signal(int pid, int signum)
{
	if (kill(pid, signum) == -1)
		exit (EXIT_FAILURE);
}

void	handler_sigusr(int signum, siginfo_t *info, void *context)
{
	static char	c = 0xFF;
	static int	bit = 0;
	static int	pid = 0;
	static char	*str = 0;

	(void)context;
	if ((info)->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= 0x80 >> bit;
	else if (signum == SIGUSR2)
		c ^= 0x80 >> bit;
	if (++bit == 8)
	{
		if (!c)
		{
			str = ft_printmsg(str);
			send_signal(pid, SIGUSR2);
		}
		else
			str = ft_appendchr(str, c);
		bit = 0;
		c = 0xFF;
	}
	send_signal(pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sact;
	int					pid;

	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = &handler_sigusr;
	sigaction(SIGUSR1, &sact, 0);
	sigaction(SIGUSR2, &sact, 0);
	pid = getpid();
	ft_putstr("PID: ");
	ft_putnbr(pid);
	ft_putchar('\n');
	while (1)
		pause();
}

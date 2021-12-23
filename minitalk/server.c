/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:53:27 by yonas             #+#    #+#             */
/*   Updated: 2021/12/23 15:39:51 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler_sigusr(int signum, siginfo_t *info, void *ucontext)
{
	static char	c = 0xFF;
	static int	bits = 0;

	(void) ucontext;
	(void) info;
	if (signum == SIGUSR2)
		c ^= 0x80 >> bits;
	else if (signum == SIGUSR1)
		c |= 0x80 >> bits;
	bits++;
	if (bits == 8)
	{
		if (c)
			ft_putchar(c);
		bits = 0;
		c = 0xFF;
	}
	usleep(100);
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
		pause ();
}

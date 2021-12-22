/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:06:33 by yonas             #+#    #+#             */
/*   Updated: 2021/12/22 20:57:29 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handlerend(int signum)
{
	static int	flag = 1;

	if (signum == SIGUSR1 && flag)
	{
		ft_putstr("\nMessage sent ----");
		flag = 0;
	}
	if (signum == SIGUSR2)
	{
		ft_putstr(" Message recieved \n");
		flag = 1;
		exit (EXIT_SUCCESS);
	}
}

void	ft_sendsignal(int pid, char *msg)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	if (!msg)
		exit (EXIT_FAILURE);
	while (1)
	{
		j = -1;
		while (++j < 8)
		{
			if (msg[i] & (0x80 >> j))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			}
			else if (kill(pid, SIGUSR2) == -1)
				exit (1);
			usleep(100);
		}
		if (!msg)
			break;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, sig_handlerend);
	signal(SIGUSR2, sig_handlerend);
	if (argc != 3 || (!ft_isnum(argv[1])))
	{
		ft_putstr("Invalid argument \n");
		exit(EXIT_FAILURE);
	}
	pid = ft_strtoint(argv[1]);
	ft_sendsignal(pid, argv[2]);
	return (0);
}

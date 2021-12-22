/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:06:33 by yonas             #+#    #+#             */
/*   Updated: 2021/12/22 03:27:06 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_minitalk.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

int	ft_atob(char *str);

void	ft_message(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1,&str[i],1);
		i++;
	}

}

void	sig_handlerend(int signum)
{
	static int	flag = 1;

	if (signum == SIGUSR1 && flag)
	{
		ft_message("\nMessage sent");
		flag = 0;
	}
	if (signum == SIGUSR2)
	{
		ft_message(" Message recieved \n");
		flag = 1;
		exit (EXIT_SUCCESS);
	}
}

void	ft_sendsignal(int pid,char *message)
{
	int	i;
	int	bit;

	bit = -1;
	i = 0;
	if (!message)
		exit(EXIT_FAILURE);
	while (1)
	{
		bit = -1;
		while (++bit < 8)
		{
			if (message[i] & (0x80 >> bit))
			{
				if (kill(pid, SIGUSR1) == -1)
					exit(1);
			}
			else if (kill(pid, SIGUSR2) == -1)
				exit(1);
			usleep(100);
		}
		if (!message[i])
			break ;
		++i;
	}
}
/*
void	ft_sendsignal(int pid, char *msg)
{
	int i;
	int j;

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
		if (!msg[i])
			break;
		i++;
	
	}
}
*/
int	ft_atob(char *str)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		nb = nb * 10 + (str[i] - 48);
		i++;
	}
	return (nb);
}

int	main(int argc, char *argv[])
{
	int pid;
	signal(SIGUSR1, sig_handlerend);
	signal(SIGUSR2, sig_handlerend);

	if (argc != 3) //or alpha numeric
	{
		printf("Invalid argument \n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atob(argv[1]);
	ft_sendsignal(pid, argv[2]);
	return (0);
}

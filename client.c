/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:06:33 by yonas             #+#    #+#             */
/*   Updated: 2021/11/29 02:13:46 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
int	ft_atob(char *str);

//void	ft_sendsignal(char *msg)
void	ft_sendsignal(int pid, char *msg)
{
	int i;
	int j;

	i = 0;
	while (msg[i])
	{
		j = 0;
		while (j < 8)
		{
			if (msg[i] << j & 0x80)
			{
				if (kill(pid, SIGUSR1) == -1)
					exit (1);
			}
			else
			{
				if (kill(pid, SIGUSR2) == -1)
					exit (1);
			}
			usleep(100);
			j++;
		}
		i++;
	}
}

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

	if (argc != 3)
	{
		printf("Invalid argument \n");
		exit(EXIT_FAILURE);
	}
	pid = ft_atob(argv[1]);
	ft_sendsignal(pid, argv[2]);
	return (0);
}

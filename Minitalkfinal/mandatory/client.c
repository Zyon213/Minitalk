/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:06:33 by yonas             #+#    #+#             */
/*   Updated: 2021/12/22 16:55:18 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void	ft_sendsignal(int pid, char *msg)
{
	int	i;
	int	j;

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

int	main(int argc, char *argv[])
{
	int	pid;

	if (argc != 3 || (!ft_isnum(argv[1])))
	{
		ft_putstr("Invalid argument \n");
		exit(EXIT_FAILURE);
	}
	pid = ft_strtoint(argv[1]);
	ft_sendsignal(pid, argv[2]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yonas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 17:53:27 by yonas             #+#    #+#             */
/*   Updated: 2021/12/22 03:31:50 by yonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "ft_minitalk.h"
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (*s++)
		++i;
	return (i);
}


void	ft_putstr_fd(char *s)
{
	int	len;

	if (!s)
		return ;
	len = ft_strlen(s);
	write(1, s, len);
}

char	*print_string(char *message)
{
	ft_putstr_fd(message);
	ft_putchar('\n');
	free(message);
	return (NULL);
}

char	*ft_char_to_str(char c)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

char	*ft_str_add_char(char *str, char c)
{
	char	*add;
	int		i;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_char_to_str(c));
	add = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!add)
	{
		free(str);
		return (NULL);
	}
	i = -1;
	while (str[++i])
		add[i] = str[i];
	free(str);
	add[i++] = c;
	add[i] = '\0';
	return (add);
}

void	ft_messages(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1,&str[i++],1);
}
/*
char	*ft_appendc(char *str, char c)
{
	int i;
	int n;
	char *dup;
	
	n = ft_strlen(str);
	if (!c)
		return (NULL);
	dup = malloc(sizeof(char) * n + 2);
	if (!dup)
		return (NULL);
	if (!str)
	{
		dup[0] = c;
		dup[1] = '\0';
		return (dup);
	}
	i = 0;	
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i++] = c;
	free(str);
	dup[i] = '\0';
	return (dup);
}
*/


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
	static char	*message = 0;

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
			message = print_string(message);
			send_signal(pid, SIGUSR2);
		}
		else
			message = ft_str_add_char(message, c);
		bit = 0;
		c = 0xFF;
	}
	send_signal(pid, SIGUSR1);
}

/*
void	handler_sigusr(int signum, siginfo_t *info, void *ucontext)
{
	(void) ucontext;
	static int pid = 0;
	static char c = 0xFF;
	static int bits = 0;
	static char *message = 0;

	if ((info)->si_pid)
		pid = info->si_pid;
	if (signum == SIGUSR1)
		c |= 0x80 >> bits;
	else if (signum == SIGUSR2)
		c ^= 0x80 >> bits;
	if (++bits == 8)
	{


		if (!c)
		{
			message = print_string(message);
			send_signal(pid, SIGUSR2);
		}
		else
			message = ft_str_add_char(message, c);

		bits = 0;
		c = 0xFF;

	}
	send_signal(pid, SIGUSR1);

}
*/
void	itoa_isnegative(int *n, int *negative)
{
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
	}
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*dup;

	len = ft_strlen(s);
	i = 0;
	dup = (char *) malloc(sizeof(char) * (len + 1));
	if (dup == 0)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_itoa(int n)
{
	int		tmpn;
	int		len;
	int		negative;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	tmpn = n;
	len = 2;
	negative = 0;
	itoa_isnegative(&n, &negative);
	while (tmpn /= 10)
		len++;
	len += negative;
	str = (char *) malloc(sizeof(char) * len);
	if (str == 0)
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + '0';
		n = n / 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}
int	main(void)
{
	struct sigaction sact;
	sigemptyset(&sact.sa_mask);
	sact.sa_flags = SA_SIGINFO;
	sact.sa_sigaction = &handler_sigusr;
	sigaction(SIGUSR1, &sact, 0);
	sigaction(SIGUSR2, &sact, 0);

	int pid;

	pid = getpid();
	ft_messages("PID: ");
	ft_messages(ft_itoa(pid));

	while (1)
		pause();
}

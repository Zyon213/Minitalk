/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:45:46 by yoyohann          #+#    #+#             */
/*   Updated: 2021/12/22 16:45:54 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_putnbr(int n)
{
	int		nb;
	char	str[16];
	int		len;

	nb = n;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		exit (1);
	}
	if (nb < 0)
		nb = -nb;
	len = ft_nbrlen(n);
	str[len--] = '\0';
	while (nb != 0)
	{
		str[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	ft_putstr(str);
}

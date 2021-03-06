/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:46:49 by yoyohann          #+#    #+#             */
/*   Updated: 2021/12/22 16:46:52 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t	ft_strtoint(char *str)
{
	size_t	nb;
	int		i;

	i = 0;
	nb = 0;
	while (str[i])
	{
		nb = (nb * 10) + (str[i] - 48);
		i++;
	}
	return (nb);
}

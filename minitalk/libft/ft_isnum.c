/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:50:17 by yoyohann          #+#    #+#             */
/*   Updated: 2021/12/22 16:56:07 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isnumber(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isnumber(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 16:00:16 by yoyohann          #+#    #+#             */
/*   Updated: 2021/12/23 16:02:29 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_chrappend(char c)
{
	char	*str;

	str = malloc(sizeof(char) * 2);
	if (!str)
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:08:21 by yoyohann          #+#    #+#             */
/*   Updated: 2021/12/23 16:25:37 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_appendchr(char *str, char c)
{
	int		i;
	char	*dup;

	if (!c)
		return (NULL);
	if (!str)
		return (ft_chrappend(c));
	dup = malloc(sizeof(char) * ft_strlen(str) + 2);
	if (!dup)
		return (NULL);
	i = -1;
	while (str[++i])
		dup[i] = str[i];
	dup[i++] = c;
	free(str);
	dup[i] = '\0';
	return (dup);
}

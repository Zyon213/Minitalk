/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_appendchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 18:08:21 by yoyohann          #+#    #+#             */
/*   Updated: 2021/12/22 18:10:43 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_appendchr(char *str, char c)
{
	int		i;
	int		n;
	char	*dup;

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
	i = -1;
	while (str[++i])
		dup[i] = str[i];
	dup[i++] = c;
	free(str);
	dup[i] = '\0';
	return (dup);
}

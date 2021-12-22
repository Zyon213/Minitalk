/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoyohann <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 16:08:20 by yoyohann          #+#    #+#             */
/*   Updated: 2021/12/22 18:14:56 by yoyohann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MINITALK_H
# define MINITALK_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_nbrlen(int n);
void	ft_putnbr(int n);
size_t	ft_strtoint(char *str);
int		ft_isnumber(char c);
int		ft_isnum(char *str);
char	*ft_appendchr(char *str, char c);

#endif

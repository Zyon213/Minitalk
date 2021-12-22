# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonas <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 18:56:22 by yonas             #+#    #+#              #
#    Updated: 2021/11/29 19:53:13 by yonas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libmin.a
CLIENT = client
SERVER	= server
SRC_CLIENT = client.c
SRC_SERVER = server.c
CC = gcc 
FLAG = -Wall -Wextra -Werror

obj:
	$(CC) -c $(SRC_CLIENT) $(SRC_SERVER)

lib:
	ar rc $(LIB) *.o

all: client server

clean:
	rm -f *.o
fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all


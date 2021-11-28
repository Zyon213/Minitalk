SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

all: server client

server: ft_server.o
	gcc -o server ft_server.o -lft

client: ft_client.o
	gcc -o client ft_client.o -lft

%.o: %.c
	gcc -c -Wall -Wextra -Werror $?


clean:
	rm -f $(OBJECTS)
	make -C clean

fclean: clean
	rm -f server client:

re: fclean all

.PHONY: all clean fclean re

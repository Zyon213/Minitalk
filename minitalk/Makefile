CLIENT = client.c
SERVER = server.c
CLIENT_B = client_bonus.c
SERVER_B = server_bonus.c
LIB = libtalk.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
AR = ar rc
RM = rm -f
DIR = ./libft/
CLT = client
SRV = server
CLTB = client_bonus
SRVB = server_bonus

all: server client

bonus: client_b server_b
obj:
	$(CC) -c $(DIR)*.c
liba: obj
	$(AR) $(LIB) *.o
server: liba
	$(CC) $(FLAGS) $(SERVER) -L. $(LIB) -o $(SRV)
client: liba
	$(CC) $(FLAGS) $(CLIENT) -L. $(LIB) -o $(CLT)
server_b: liba
	$(CC) $(FLAGS) $(SERVER_B) -L. $(LIB) -o $(SRVB)
client_b: liba
	$(CC) $(FLAGS) $(CLIENT_B) -L. $(LIB) -o $(CLTB)
clean:
	$(RM) *.o
clean_b:
	$(RM) $(CLTB) $(SRVB)
fclean: clean clean_b
	$(RM) $(CLT) $(SRV)
	$(RM) $(LIB)
re: all fclean

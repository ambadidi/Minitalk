NAME1 = client

NAME2 = server

SRCS_CLIENT = client.c

SRCS_SERV = server.c

FLAGS = -Wall -Wextra -Werror -c

OBJS_CLENT = $(SRCS_CLIENT:.c=.o)

OBJS_SERV = $(SRCS_SERV:.c=.o)

INC = minitalk.h

CC = gcc

all: $(NAME1)

$(NAME1): $(SRCS_CLIENT) $(SRCS_SERV) $(INC)
	@$(CC) $(FLAGS) $(INC) $(SRCS_SERV)
	@$(CC) $(OBJS_SERV) -o $(NAME2)
	@$(CC) $(FLAGS) $(INC) $(SRCS_CLIENT)
	@$(CC) $(OBJS_CLENT) -o $(NAME1)

clean:
	rm -rf $(OBJS_CLENT) $(OBJS_SERV)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all 
NAME1 = client
NAME2 = server
SRCS_CLIENT = client.c
SRCS_SERV = server.c
INC = minitalk.h
FLAGS = -Wall -Wextra -Werror -c
OBJS_CLENT = $(SRCS_CLIENT:.c=.o)
OBJS_SERV = $(SRCS_SERV:.c=.o)
CC = clang  
all: $(NAME1)
$(NAME1): $(SRCS_CLIENT) $(SRCS_SERV) $(INC)
	echo $(SRCS)
	$(CC) $(FLAGS) $(INC) $(SRCS_SERV)
	ar -rc $(NAME1) $(OBJS)
	ranlib $(NAME1)

clean:
	rm -rf $(OBJS_CLENT) $(OBJS_SERV)

fclean: clean
	rm -rf $(NAME1) $(NAME2)

re: fclean all 
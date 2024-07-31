NAME = server
NAME2 = client

all : client server

$(NAME2) : client.c
	cc -Wall -Wextra -Werror client.c -o $(NAME2) 
	
$(NAME) : server.c
	cc -Wall -Wextra -Werror  server.c -o $(NAME)

clean : 

fclean : clean
	rm server
	rm client

re : fclean all

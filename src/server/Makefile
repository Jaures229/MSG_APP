SRC	=	main.cpp	\
		server_render.cpp	\
		server.cpp	\
		security.cpp	\
		server_client.cpp	\
		client_server.cpp

OBJ	=	${SRC}

NAME	=	@Server

all:	${NAME}

${NAME}:
	g++ -o ${NAME} -std=c++20 ${SRC} -O1 -O2 -O3 -g3

clean:
	rm -f *~
	rm -f ${NAME}
	rm -f *.o

fclean: clean

re: fclean all

SRC	=	main.cpp

OBJ	=	${SRC}

NAME	=	@Server

all:	${NAME}

${NAME}:
	g++ -o ${NAME} -std=c++20 ${SRC} -O1 -O2 -O3 -g3

clean:
	rm -f *~
	rm -f ${NAME}

fclean: clean

re: fclean all

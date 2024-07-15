SRC	=	main.cpp	\
		../loader/loader.cpp	\
		../Client/client.cpp

OBJ	=	${SRC}

NAME	=	@Client

all:	${NAME}

SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network

${NAME}:
	g++ -o ${NAME} -std=c++20 ${SRC} -O1 -O2 -O3 -g3 $(SFML)

clean:
	rm -f *~
	rm -f ${NAME}

fclean: clean

re: fclean all

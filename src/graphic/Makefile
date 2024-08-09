SRC	=	main.cpp	\
		loader.cpp	\
		client.cpp	\
		graphic.cpp	\
		protocol.cpp	\
		../../include/*.cpp

OBJ	=	${SRC}

NAME	=	@Client

all:	${NAME}

FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lGL -g3

${NAME}:
	g++ -o ${NAME} -std=c++20 ${SRC} ${FLAGS}
clean:
	rm -f *~
	rm -f ${NAME}
	rm -f *.o
	rm -f *.ini

fclean: clean

re: fclean all

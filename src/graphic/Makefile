SRC	=	main.cpp	\
		loader.cpp	\
		client.cpp	\
		../../include/*.cpp

OBJ	=	${SRC}

NAME	=	@Server

all:	${NAME}

FLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-network -lsfml-audio -lGL -g3

${NAME}:
	g++ -o ${NAME} -std=c++20 ${SRC} ${FLAGS}
clean:
	rm -f *~
	rm -f ${NAME}
	rm *.o

fclean: clean

re: fclean all

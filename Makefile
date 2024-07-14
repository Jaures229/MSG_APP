
NAME	=	MSG_APP

all:	${NAME}

${NAME}:
	make -C src/graphic -s
	make -C src/server	-s

server:
	make -C src/server -s

Client:
	make -C src/graphic -s

clean:
	rm -f *~
	make fclean -C src/graphic -s
	make fclean -C src/server -s
fclean: clean

re: fclean all

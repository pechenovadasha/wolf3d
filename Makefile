wolf:
	clang -std=c18 -Wall -pedantic *.c Libft/*.c  -lSDL2
fclean:
	rm -rf *.o
	rm -rf wolf
re: fclean wolf
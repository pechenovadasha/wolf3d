wolf:
	 gcc *.c Libft/*.c -I include -L lib -l SDL2-2.0.0
fclean:
	rm -rf *.o
	rm -rf wolf
re: fclean wolf
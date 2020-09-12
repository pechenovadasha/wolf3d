wolf:
	 gcc *.c Libft/*.c -I include -L lib -l SDL2-2.0.0
	#gcc *.c Libft/*.c -framework GLUT -framework OpenGL -std=c99 -I ~/Library/Frameworks/SDL2.framework/Headers/  -framework GLUT -framework OpenGL -std=c99 -I ~/Library/Frameworks/SDL2_image.framework/Headers/

fclean:
	rm -rf *.o
	rm -rf wolf
re: fclean wolf
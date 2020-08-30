#ifndef WOLF_H
#define WOLF_H

#include <SDL2/SDL.h>
//#include <SDL2/SDL_test_images.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "Libft/libft.h"

#define WIDTH_W

typedef struct s_sdl
{
	int a;
}				t_sdl;

typedef struct	s_main
{
	int player_x;
	int player_y;
	int number_of_x;
	int number_of_y;
	int **map;

}				t_main;

int check(char *file, t_main *data);
void rendering(t_main *data, t_sdl *sdl);

#endif

#include "wolf.h"

void initial(t_main *data, t_sdl *sdl)
{
	data->number_of_x = -1;
	data->number_of_y = -1;
	data->player_x = -1;
	data->player_y = -1;
}

int main(int argc, char **argv)
{
	t_main data;
	t_sdl sdl;
	if (argc < 2)
	{
		write(1, "Usage: ./wolf <map>\n", 20);
		return(-1);
	}
	initial(&data, &sdl);
	if((check(argv[1], &data)) == -1)
	{
		write(1, "Wrong map\n", 10);
		return(-1);
	}
	rendering(&data, &sdl);
	return(0);
}

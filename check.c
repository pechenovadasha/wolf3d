#include "wolf.h"

void write_from_file_into_massive(int fd, t_main *data)
{
	char *line;
	int i;
	int j;

	data->map = (int **)malloc(sizeof(int*) * data->number_of_y + 1);
	i = -1;
	j = 0;
	while(++i <= data->number_of_y)
		data->map[i] = (int*)malloc(sizeof(int) * data->number_of_x + 1);
	while(get_next_line(fd, &line) && j <= data->number_of_y)
	{
		i = 0;
		while(line[i] != '\0' && i <= data->number_of_x)
		{
			data->map[j][i] = line[i] - '0';
			i++;
		}
		j++;
	}
}

int check_map(int fd, t_main *data)
{
	char *line;
	int i;

	while(get_next_line(fd, &line))
	{
		i = 0;
		while(line[i])
		{
			if((line[i] < 47 || line[i] > 54) && line[i] != '8')
				return(-1);
//			if ((i == 0 || data->number_of_y == -1) && line[i] == '0')
//			{
//				write(1, "Wrong map outline\n", 18);
//				return(-1);
//			}
			if (line[i] == '8')
			{
				if (data->player_x == -1){
				data->player_x = i;
				data->player_y = data->number_of_y + 1;
				}
				else
				{
					write(1, "Too much players\n", 17);
					return(-1);
				}
			}
			i++;
		}
		if (data->number_of_x == -1)
			data->number_of_x = i;
		else if (data->number_of_x != i)
		{
			write(1, "Wrong number of column\n", 23);
			return(-1);
		}
		data->number_of_y++;
	}
	return(0);
}

int open_for_check(char *file, t_main *data)
{
	int fd;
	int fd1;

	fd = open(file, O_RDONLY);
	fd1 = open(file, O_RDONLY);
	if (fd <= 0 || fd1<= 0 || (check_map(fd, data) == -1))
	{
		write(1, "Wrong map\n", 10);
		return (-1);
	}
	write_from_file_into_massive(fd1, data);
	return(0);
}

int check(char *file, t_main *data)
{
	if ((open_for_check(file, data)) == -1)
		return(-1);
	return(0);
}

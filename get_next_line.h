#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 4096

int	get_next_line(int const fd, char **line);
int	ft_new_str(char **str, char **line, int const fd, int ret);

#endif

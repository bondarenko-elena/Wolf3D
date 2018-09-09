#include "../includes/wolf3d.h"

void	get_y(int fd, t_env *env, char *filename)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(fd, &line) == 1)
		i++;
	free(line);
	close(fd);
	env->get_y = i;
	fd = open(filename, O_RDONLY);
}
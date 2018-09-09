#include "../includes/wolf3d.h"

int open_file(t_env *env, char *filename)
{
	int fd;
	char *line;
	int y;

	y = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	get_position(fd, env, filename);
	check_chars(fd, filename, env);
	env->map = (int**)malloc(sizeof(int**) * env->get_y);
	while (get_next_line(fd, &line) == 1)
	{
		read_line(line, y, env);
		y++;
	}
	if (!env->map)
		return (0);
	close(fd);
	return (0);
}
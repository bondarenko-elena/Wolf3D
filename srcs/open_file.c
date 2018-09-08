#include "../includes/wolf3d.h"

int open_file(t_env *env, char *filename)
{
	int fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	read_file(fd, env);
	return (0);
}
#include "../includes/wolf3d.h"

int				open_file(t_env *env, char *filename)
{
	int		fd;

	// fd = open(filename, O_DIRECTORY);
	// if (fd >= 0)
		// return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	return (read_file(fd, env));
}
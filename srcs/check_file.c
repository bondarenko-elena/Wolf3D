#include "../includes/wolf3d.h"

int check_file(char *filename)
{
	if ((ft_strcmp(filename, "maps/map.1")
		|| ft_strcmp(filename, "maps/map.2")
		|| ft_strcmp(filename, "maps/map.3")
		|| ft_strcmp(filename, "dev")) != 0)
		return (-1);
	return (0);
}
#include "../includes/wolf3d.h"

int check_file(char *filename)
{
	if ((ft_strcmp(filename, "maps/map.1") || ft_strcmp(filename, "map/map.2") || ft_strcmp(filename, "map/map.3")) != 0)
		return (-1);
	return (0);
}
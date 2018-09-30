#include "../includes/wolf3d.h"

int		read_file(int fd, t_env *e)
{
	char	*line;
	int		y;
	int		**map;

	y = 0;
	get_position(fd, e);
	map = (int **)malloc(sizeof(int **) * e->map_height);
	while (get_next_line(fd, &line) == 1)
	{
		read_line(line, y, map, e);
		y++;
	}
	if (map[(int)e->player.position.x][(int)e->player.position.y] != 0)
		map_error();
	e->map = map;
	// ft_tabledel(map, )
	return (1);
}
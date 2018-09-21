#include "../includes/wolf3d.h"

void		read_line(char *line, int y, int **map, t_env *e)
{
	int		x;
	char	**line_split;

	x = -1;
	if (y >= e->map_height)
		map_error();
	line_split = ft_strsplit(line, ' ');
	map[y] = (int *)malloc(sizeof(int *) * e->width);
	while (line_split[++x] != '\0')
	{
		if (!(line_split[x][0] >= '0' && line_split[x][0] <= '9'
					&& ft_atoi(line_split[x]) >= 0 && x < e->map_width))
			map_error();
		map[y][x] = ft_atoi(line_split[x]);
		if ((x == 0 || x == e->map_width - 1 || y == 0 || y == e->map_height -
					1) && map[y][x] == 0)
			map_error();
	}
	if (x != e->map_width)
		map_error();
}
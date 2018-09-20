#include "../includes/wolf3d.h"

static void		read_pos(int fd, t_env *e)
{
	char	*line;
	char	**line_split;
	int		i;

	i = -1;
	if (get_next_line(fd, &line) < 1)
		error_map();
	line_split = ft_strsplit(line, ' ');
	while (line_split[++i] != '\0')
		;
	if (i != 4)
		error_map();
	e->map_width = ft_atoi(line_split[0]);
	e->map_height = ft_atoi(line_split[1]);
	e->player.pos.x = ft_atoi(line_split[2]) + 0.5;
	e->player.pos.y = ft_atoi(line_split[3]) + 0.5;
	if (e->map_width < 0 || e->map_height < 0 || e->player.pos.x < 0 ||
			e->player.pos.y < 0 || e->player.pos.x >= e->map_width ||
			e->player.pos.y >= e->map_width)
		error_map();
}

static void		read_line(char *line, int y, int **map, t_env *e)
{
	int		x;
	char	**line_split;

	x = -1;
	if (y >= e->map_height)
		error_map();
	line_split = ft_strsplit(line, ' ');
	map[y] = (int *)malloc(sizeof(int *) * e->width);
	while (line_split[++x] != '\0')
	{
		if (!(line_split[x][0] >= '0' && line_split[x][0] <= '9'
					&& ft_atoi(line_split[x]) >= 0 && x < e->map_width))
			error_map();
		map[y][x] = ft_atoi(line_split[x]);
		if ((x == 0 || x == e->map_width - 1 || y == 0 || y == e->map_height -
					1) && map[y][x] == 0)
			error_map();
	}
	if (x != e->map_width)
		error_map();
}

static int		read_file(int fd, t_env *e)
{
	char	*line;
	int		y;
	int		**map;

	y = -1;
	read_pos(fd, e);
	map = (int **)malloc(sizeof(int **) * e->map_height);
	while (get_next_line(fd, &line) == 1)
		read_line(line, ++y, map, e);
	if (map[(int)e->player.pos.x][(int)e->player.pos.y] != 0)
		error_map();
	e->map = map;
	return (1);
}

int				open_file(t_env *e, char *f)
{
	int		fd;

	fd = open(f, O_DIRECTORY);
	if (fd >= 0)
		return (0);
	fd = open(f, O_RDONLY);
	if (fd < 0)
		return (0);
	return (read_file(fd, e));
}

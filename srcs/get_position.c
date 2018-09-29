#include "../includes/wolf3d.h"

void		get_position(int fd, t_env *e)
{
	char	*line;
	char	**line_splitted;
	int		i;

	i = 0;
	if (get_next_line(fd, &line) < 1)
		map_error();
	line_splitted = ft_strsplit(line, ' ');
	while (line_splitted[i] != '\0')
		i++;
	if (i != 4)
	{
		ft_tabledel(line_splitted, i);
		map_error();
	}
	e->map_width = ft_atoi(line_splitted[0]);
	e->map_height = ft_atoi(line_splitted[1]);
	e->player.position.x = ft_atoi(line_splitted[2]) + 0.5;
	e->player.position.y = ft_atoi(line_splitted[3]) + 0.5;
	// ft_tabledel(line_splitted, i);
	if (e->map_width < 0 || e->map_height < 0 || e->player.position.x < 0 ||
			e->player.position.y < 0 || e->player.position.x >= e->map_width ||
			e->player.position.y >= e->map_width)
		map_error();
}
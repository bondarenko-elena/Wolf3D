#include "../includes/wolf3d.h"

int		read_file(int fd, t_env *env)
{
	char	*line;
	int		y;

	y = 0;
	get_position(fd, env);
	env->map = (int **)malloc(sizeof(int **) * env->map_height);
	while (get_next_line(fd, &line) == 1)
	{
		read_line(line, y, env->map, env);
		free(line);
		y++;
	}
	free(line);
	if (env->map[(int)env->player.position.x][(int)env->player.position.y] != 0)
	{
		while (env->map_height > -1)
		{
			free(env->map[env->map_height]);
			env->map_height--;
		}
		free(env->map);
		map_error();
	}
	return (1);
}
#include "../includes/wolf3d.h"

void get_position(int fd, t_env *env, char *filename)
{
	char *line;
	char **str_splitted;
	int i;

	i = 0;
	if (get_next_line(fd, &line) < 1)
	{
		printf("%d\n", 2);
		map_error();
	}
	str_splitted = ft_strsplit(line, ' ');
	while (str_splitted[i] != '\0')
		i++;
	if (i != 4)
	{
		printf("%d\n", 3);
		map_error();
	}
	env->map_width = ft_atoi(str_splitted[0]);
	env->map_height = ft_atoi(str_splitted[1]);
	env->player.position.x = (double)ft_atoi(str_splitted[2]) + 0.5;
	env->player.position.y = (double)ft_atoi(str_splitted[3]) + 0.5;

	// printf("env->map_width: %d\n", env->map_width);
	// printf("env->map_height: %d\n", env->map_height);
	// printf("env->player.position.x: %lf\n", env->player.position.x);
	// printf("env->player.position.y: %lf\n", env->player.position.y);

	// ft_tabledel(str_splitted, 4);

	get_y(fd, env, filename);

	if (env->map_width < 0 || env->map_height < 0 || env->player.position.x < 0 || env->player.position.y < 0 || env->player.position.x >= env->map_width || env->player.position.y >= env->map_width)
	{
		printf("%d\n", 4);
		map_error();
	}
}
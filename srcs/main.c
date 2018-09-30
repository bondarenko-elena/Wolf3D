#include "../includes/wolf3d.h"

int				main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 2 /*&& (check_file(argv[1]) == 0)*/)
	{
		env = init_env();
		if (open_file(env, argv[1]) == 0)
		{
			free(env);
			ft_putendl("Unable to read file.");
			return (-1);
		}
		env->mlx.window = mlx_new_window(env->mlx.mlx_init, WIDTH, HEIGHT, "Wolf3D@olbondar");
		event(env);
		mlx_loop(env->mlx.mlx_init);
////////////////////////////////////////////////////////////////////////////////////////////////
/*		env->map_height--;
		while (env->map_height > -1)
		{
			free(env->map[env->map_height]);
			env->map_height--;
		}
		free(env->map);*/
////////////////////////////////////////////////////////////////////////////////////////////////
	}
	if (argc == 2 && (check_file(argv[1]) == -1))
		ft_putendl("Wrong input map. Available maps is between 1 and 3");
	if (argc < 2 || argc > 2)
		ft_putendl("Wrong number of arguments. Usage: ./Wolf3D maps/map.n.");
	return (0);
}
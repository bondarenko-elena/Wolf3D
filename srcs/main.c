#include "../includes/wolf3d.h"

int	main(int argc, char **argv)
{
	t_env	*env;

	if (argc == 2 && (check_file(argv[1]) == 0))
	{
		env = pre_init_env();
		if (open_file(env, argv[1]) != 0)
		{
			ft_putendl("Unable to read file.");
			return (-1);
		}
		post_init_env(env);
		event(env);
		mlx_loop(env->mlx_init);
	}
	if (argc == 2 && (check_file(argv[1]) == -1))
		ft_putendl("Wrong input map. Available maps is between 1 and 3");
	if (argc < 2 || argc > 2)
		ft_putendl("usage: ./Wolf3D maps/map.n. You should choose just one map.");
	return (0);
}
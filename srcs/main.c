/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:52 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:40:02 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int argc, char **argv)
{
	t_env		*env;

	env = NULL;
	if (argc < 2 || argc > 2)
		ft_putendl("Wrong number of arguments. Usage: ./Wolf3D maps/filename.");
	if (argc == 2)
	{
		env = init_env(env);
		if (open_file(env, argv[1]) == 0)
		{
			free_struct(env);
			read_error();
		}
		if (!check_file(env))
		{
			free_struct(env);
			map_error();
		}
		else
			read_file(env, argv[1]);
	}
	return (0);
}

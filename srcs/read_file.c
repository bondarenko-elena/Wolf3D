/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <olbondar@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 09:32:55 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/18 09:45:59 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	read_file(t_env *env, char *filename)
{
	close(env->fd);
	env->fd = open(filename, O_RDONLY);
	read_map(env);
	init_window(env);
	do_magic(env);
}

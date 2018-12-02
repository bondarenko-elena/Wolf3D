/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_color1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:04:36 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/19 18:04:38 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	define_color1(t_env *env, int def, int iterator)
{
	if (def < 0)
		env->ray->color = add_smog(get_color_tex(env, iterator, 0),
			env->ray->perp_wall_d);
	else
		env->ray->color = add_smog(get_color_tex(env, iterator, 1),
			env->ray->perp_wall_d);
}

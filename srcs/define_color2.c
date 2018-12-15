/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_color2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olbondar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/19 18:04:46 by olbondar          #+#    #+#             */
/*   Updated: 2018/10/19 18:04:47 by olbondar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	define_color2(t_env *env, int def, int iterator)
{
	if (def < 0)
		env->ray->color = add_smog(get_color_tex(env, iterator, 2),
			env->ray->perp_wall_d);
	else
		env->ray->color = add_smog(get_color_tex(env, iterator, 3),
			env->ray->perp_wall_d);
}

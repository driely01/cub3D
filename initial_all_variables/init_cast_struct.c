/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cast_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:04:02 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/30 21:04:25 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initial_cast_vars(t_cub *data)
{
	data->cast.lenght = 0;
	data->cast.color = 0;
	data->cast.flag = 0;
	data->cast.offset = 0;
	data->cast.hx = 0;
	data->cast.hy = 0;
	data->cast.hx_offs = 0;
	data->cast.hy_offs = 0;
	data->cast.vx = 0;
	data->cast.vy = 0;
	data->cast.vx_offs = 0;
	data->cast.vy_offs = 0;
	data->cast.ray_ang = 0;
	data->cast.angl_inc = (M_PI / 3) / WIDTH;
	data->cast.wall_height = 0;
	data->cast.step = 0;
}

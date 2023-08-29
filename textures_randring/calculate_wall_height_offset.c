/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_wall_height_offset.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:19:02 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/27 15:06:56 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	calculate_wall_height_offset(t_cub *data, int height, int i)
{
	(void)i;
	data->cast.wall_height = UNIT / (data->cast.dist
			* cos(fabs(data->draw.pa - data->cast.ray_ang))) * HEIGHT;
	if (data->cast.flag == 1)
		data->cast.offset = (int)data->cast.hx % UNIT;
	else
		data->cast.offset = (int)data->cast.vy % UNIT;
	data->cast.step = height / data->cast.wall_height;
	if (data->cast.wall_height > HEIGHT)
		data->cast.wall_height = HEIGHT;
}

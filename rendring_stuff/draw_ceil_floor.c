/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:18:32 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/21 21:14:37 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_ceil_floor(t_cub *data, int i)
{
	int		j;
	double	wall_height;

	wall_height = UNIT / (data->cast.distances[i]
			* cos(fabs(data->draw.pa - data->cast.ray_ang))) * HEIGHT;
	j = 0;
	while (j < HEIGHT)
	{
		if (j < ((HEIGHT / 2) - (wall_height / 2)))
			my_put_pixel(data, i, j, 0x05071D);
		else if (j - ((HEIGHT / 2) - (wall_height / 2)) > wall_height)
			my_put_pixel(data, i, j, 0x292b2c);
		j++;
	}
}

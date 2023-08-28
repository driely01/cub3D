/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ceil_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:18:32 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/28 01:02:00 by amoukhle         ###   ########.fr       */
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
			my_put_pixel(data, i, j, data->c_color);
		else if (j - ((HEIGHT / 2) - (wall_height / 2)) > wall_height)
			my_put_pixel(data, i, j, data->f_color);
		j++;
	}
}

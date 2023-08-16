/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls_3d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 22:18:32 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/16 23:38:38 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_walls(t_cub *data, int i)
{
	int		j;
	double	wall_height;


	wall_height = UNIT / (data->cast.distances[i] * cos(fabs(data->draw.pa - data->cast.ray_ang))) * HEIGHT;
	if (wall_height > HEIGHT)
		wall_height = HEIGHT;
	j = 0;
	while (j < HEIGHT)
	{
		if (j < ((HEIGHT / 2) - (wall_height / 2)))
			my_put_pixel(data, i, j, 0xc4fff9);
		else if (j - ((HEIGHT / 2) - (wall_height / 2)) <= wall_height)
			my_put_pixel(data, i, j, data->cast.color);
		else
			my_put_pixel(data, i, j, 0x292b2c);
		j++;
	}

}
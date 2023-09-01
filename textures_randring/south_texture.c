/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   south_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:00:04 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/30 23:28:52 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	so_textures_so_down(t_cub *data, double next_px, int choice)
{
	if (choice == 1)
	{
		data->text.color = (unsigned int *)data->text.so_add + \
				(data->text.so_width * (data->text.so_height / 2)
				+ ((data->cast.offset * data->text.so_width) / UNIT))
			- (data->text.so_width * (int)next_px);
	}
	else if (choice == 0)
	{
		data->text.color = (unsigned int *)data->text.so_add + \
				(data->text.so_width * (data->text.so_height / 2)
				+ ((data->cast.offset * data->text.so_width) / UNIT))
			+ (data->text.so_width * (int)next_px);
	}
}

void	so_textures(t_cub *data, int i)
{
	int		j;
	double	next_px;

	calculate_wall_height_offset(data, data->text.so_height, i);
	next_px = 0;
	j = HEIGHT / 2;
	while (j > (HEIGHT / 2) - (data->cast.wall_height / 2))
	{
		so_textures_so_down(data, next_px, 1);
		my_put_pixel(data, i, j, *data->text.color);
		next_px += data->cast.step;
		j--;
	}
	j = HEIGHT / 2;
	next_px = 0;
	while (j < (HEIGHT / 2) + (data->cast.wall_height / 2))
	{
		so_textures_so_down(data, next_px, 0);
		my_put_pixel(data, i, j, *data->text.color);
		next_px += data->cast.step;
		j++;
	}
	draw_ceil_floor(data, i);
}

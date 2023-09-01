/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   east_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:16:57 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/30 23:29:34 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ea_textures_up_down(t_cub *data, double next_px, int choice)
{
	if (choice == 1)
	{
		data->text.color = (unsigned int *)data->text.ea_add + \
				(data->text.ea_width * (data->text.ea_height / 2)
				+ ((data->cast.offset * data->text.ea_width) / UNIT))
			- (data->text.ea_width * (int)next_px);
	}
	else if (choice == 0)
	{
		data->text.color = (unsigned int *)data->text.ea_add + \
				(data->text.ea_width * (data->text.ea_height / 2)
				+ ((data->cast.offset * data->text.ea_width) / UNIT))
			+ (data->text.ea_width * (int)next_px);
	}
}

void	ea_textures(t_cub *data, int i)
{
	int		j;
	double	next_px;

	calculate_wall_height_offset(data, data->text.ea_height, i);
	next_px = 0;
	j = HEIGHT / 2;
	while (j > (HEIGHT / 2) - (data->cast.wall_height / 2))
	{
		ea_textures_up_down(data, next_px, 1);
		my_put_pixel(data, i, j, *data->text.color);
		next_px += data->cast.step;
		j--;
	}
	j = HEIGHT / 2;
	next_px = 0;
	while (j < (HEIGHT / 2) + (data->cast.wall_height / 2))
	{
		ea_textures_up_down(data, next_px, 0);
		my_put_pixel(data, i, j, *data->text.color);
		next_px += data->cast.step;
		j++;
	}
	draw_ceil_floor(data, i);
}

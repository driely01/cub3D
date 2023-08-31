/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   west_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:45:31 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/30 23:29:39 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	we_textures_up_down(t_cub *data, double next_px, int choice)
{
	if (choice == 1)
	{
		data->text.color = (unsigned int *)data->text.we_add + \
				(data->text.we_width * (data->text.we_height / 2)
				+ ((data->cast.offset * data->text.we_width) / UNIT))
			- (data->text.we_width * (int)next_px);
	}
	else if (choice == 0)
	{
		data->text.color = (unsigned int *)data->text.we_add + \
				(data->text.we_width * (data->text.we_height / 2)
				+ ((data->cast.offset * data->text.we_width) / UNIT))
			+ (data->text.we_width * (int)next_px);
	}
}

void	we_textures(t_cub *data, int i)
{
	int				j;
	double			next_px;

	calculate_wall_height_offset(data, data->text.we_height, i);
	next_px = 0;
	j = HEIGHT / 2;
	while (j > (HEIGHT / 2) - (data->cast.wall_height / 2))
	{
		we_textures_up_down(data, next_px, 1);
		my_put_pixel(data, i, j, *data->text.color);
		next_px += data->cast.step;
		j--;
	}
	j = HEIGHT / 2;
	next_px = 0;
	while (j < (HEIGHT / 2) + (data->cast.wall_height / 2))
	{
		we_textures_up_down(data, next_px, 0);
		my_put_pixel(data, i, j, *data->text.color);
		next_px += data->cast.step;
		j++;
	}
	draw_ceil_floor(data, i);
}

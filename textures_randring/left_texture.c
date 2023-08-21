/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 16:45:31 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/21 17:00:23 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	left_textures_up_down(t_cub *data, double next_px, int choice)
{
	if (choice == 1)
	{
		data->text.color = (unsigned int *)data->text.left_add + \
				(data->text.left_width * (data->text.left_height / 2)
				+ ((data->cast.offset * data->text.left_width) / UNIT))
			- (data->text.left_width * (int)next_px);
	}
	else if (choice == 0)
	{
		data->text.color = (unsigned int *)data->text.left_add + \
				(data->text.left_width * (data->text.left_height / 2)
				+ ((data->cast.offset * data->text.left_width) / UNIT))
			+ (data->text.left_width * (int)next_px);
	}
}

void	left_textures(t_cub *data, int i)
{
	int				j;
	double			next_px;

	calculate_wall_height_offset(data, data->text.left_height, i);
	next_px = 0;
	j = HEIGHT / 2;
	while (j > (HEIGHT / 2) - (data->cast.wall_height / 2))
	{
		left_textures_up_down(data, next_px, 1);
		my_put_pixel(data, i, j, *data->text.color);
		next_px += data->cast.step;
		j--;
	}
	j = HEIGHT / 2;
	next_px = 0;
	while (j < (HEIGHT / 2) + (data->cast.wall_height / 2))
	{
		left_textures_up_down(data, next_px, 0);
		my_put_pixel(data, i, j, *data->text.color);
		next_px += data->cast.step;
		j++;
	}
}

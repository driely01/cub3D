/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:55:27 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 01:17:22 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	door_textures_up_down(t_cub *data, double next_px, int choice)
{
	if (choice == 1)
	{
		data->text.color = (unsigned int *)data->text.door_add + \
				(data->text.door_width * (data->text.door_height / 2)
				+ ((data->cast.offset * data->text.door_width) / UNIT))
			- (data->text.door_width * (int)next_px);
	}
	else if (choice == 0)
	{
		data->text.color = (unsigned int *)data->text.door_add + \
				(data->text.door_width * (data->text.door_height / 2)
				+ ((data->cast.offset * data->text.door_width) / UNIT))
			+ (data->text.door_width * (int)next_px);
	}
}

void	door_textures(t_cub *data, int i)
{
	int				j;
	double			next_px;

	calculate_door_height_offset(data, data->text.door_height, i);
	next_px = 0;
	j = HEIGHT / 2;
	while (j > (HEIGHT / 2) - (data->cast.d_height / 2))
	{
		door_textures_up_down(data, next_px, 1);
		my_put_pixel(data, i, j, *data->text.color);
		next_px += data->cast.step;
		j--;
	}
	j = HEIGHT / 2;
	next_px = 0;
	while (j < (HEIGHT / 2) + (data->cast.d_height / 2))
	{
		door_textures_up_down(data, next_px, 0);
		my_put_pixel(data, i, j, *data->text.color);
		next_px += data->cast.step;
		j++;
	}
}

void	check_angle(t_cub *data, int r, int choice)
{
	int	d;

	d = 0;
	if (choice == 1)
	{
		if (data->cast.ray_ang > 0 && data->cast.ray_ang < M_PI)
			so_textures(data, r);
		else
			no_textures(data, r);
	}
	else if (choice == 0)
	{
		if (data->cast.ray_ang > M_PI / 2 && data->cast.ray_ang < 3 * M_PI / 2)
			we_textures(data, r);
		else
			ea_textures(data, r);
	}
	get_dist_door(data, r);
}

void	ray_coordinate(t_cub *data, int *i, int r, int is_hor)
{
	data->color = 0x0275d8;
	(void)i;
	if (is_hor == 1)
	{
		data->cast.dist = hor_ray_casting(data);
		data->cast.flag = 1;
		data->cast.color = 0xee7224;
		check_angle(data, r, 1);
	}
	else if (is_hor == 0)
	{
		data->cast.dist = ver_ray_casting(data);
		data->cast.color = 0xefae7e;
		data->cast.flag = 0;
		check_angle(data, r, 0);
	}
}

void	draw_casted_rays(t_cub *data)
{
	int			r;
	int			i;

	r = -1;
	i = 0;
	increment_ray_angle(data, 0);
	while (++r < WIDTH)
	{
		if (hor_ray_casting(data) < ver_ray_casting(data))
			ray_coordinate(data, &i, r, 1);
		else
			ray_coordinate(data, &i, r, 0);
		if (data->sprit1 == 1)
			draw_fire_animation(data, r);
		else if (data->sprit2 == 1)
			draw_torch_animation(data, r);
		increment_ray_angle(data, 1);
	}
}

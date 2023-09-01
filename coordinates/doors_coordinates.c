/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_coordinates.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 00:51:02 by amoukhle          #+#    #+#             */
/*   Updated: 2023/09/01 01:20:47 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	door_ver_coordinates(t_cub *data)
{
	if (data->draw.line[(int)(data->cast.vy / UNIT)] \
		[(int)(data->cast.vx / UNIT)] == 'D' && data->cast.d_vx == 0
		&& !check_door(data, data->cast.vx, data->cast.vy))
	{
		data->cast.d_vx = data->cast.vx;
		data->cast.d_vy = data->cast.vy;
		data->cast.d_v_dist = distance(data, data->cast.d_vx, data->cast.d_vy);
	}
}

void	door_hor_coordinates(t_cub *data)
{
	if (data->draw.line[(int)(data->cast.hy / UNIT)] \
		[(int)(data->cast.hx / UNIT)] == 'D' && data->cast.d_hx == 0
		&& !check_door(data, data->cast.hx, data->cast.hy))
	{
		data->cast.d_hx = data->cast.hx;
		data->cast.d_hy = data->cast.hy;
		data->cast.d_h_dist = distance(data, data->cast.d_hx, data->cast.d_hy);
	}
}

void	get_dist_door_next(t_cub *data, int *d)
{
	if (data->cast.d_vx != 0 && data->cast.d_hx != 0)
	{
		if (data->cast.d_v_dist > data->cast.d_h_dist)
		{
			data->cast.d_dist = data->cast.d_h_dist;
			data->cast.d_flag = 1;
			if (!check_door(data, data->cast.d_hx, data->cast.d_hy))
				*d = 1;
		}
		else
		{
			data->cast.d_dist = data->cast.d_v_dist;
			data->cast.d_flag = 0;
			if (!check_door(data, data->cast.d_vx, data->cast.d_vy))
				*d = 1;
		}
	}
}

void	get_dist_door(t_cub *data, int r)
{
	int	d;

	d = 0;
	if (data->cast.d_vx != 0 || data->cast.d_hx != 0)
	{
		if (data->cast.d_vx == 0 && data->cast.d_hx != 0)
		{
			data->cast.d_dist = data->cast.d_h_dist;
			data->cast.d_flag = 1;
			if (!check_door(data, data->cast.d_hx, data->cast.d_hy))
				d = 1;
		}
		else if (data->cast.d_vx != 0 && data->cast.d_hx == 0)
		{
			data->cast.d_dist = data->cast.d_v_dist;
			data->cast.d_flag = 0;
			if (!check_door(data, data->cast.d_vx, data->cast.d_vy))
				d = 1;
		}
		else
			get_dist_door_next(data, &d);
		if (data->cast.d_dist < data->cast.dist && d == 1)
			door_textures(data, r);
	}
}

void	calculate_door_height_offset(t_cub *data, int height, int i)
{
	(void)i;
	data->cast.d_height = UNIT / (data->cast.d_dist
			* cos(fabs(data->draw.pa - data->cast.ray_ang))) * HEIGHT;
	if (data->cast.d_flag == 1)
		data->cast.offset = (int)data->cast.d_hx % UNIT;
	else
		data->cast.offset = (int)data->cast.d_vy % UNIT;
	data->cast.step = height / data->cast.d_height;
	if (data->cast.d_height > HEIGHT)
		data->cast.d_height = HEIGHT;
}

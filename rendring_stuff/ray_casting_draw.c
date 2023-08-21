/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:55:27 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/21 18:00:05 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_angle(t_cub *data, int r, int choice)
{
	if (choice == 1)
	{
		if (data->cast.ray_ang > 0 && data->cast.ray_ang < M_PI)
			up_textures(data, r);
		else
			down_textures(data, r);
	}
	else if (choice == 0)
	{
		if (data->cast.ray_ang > M_PI / 2 && data->cast.ray_ang < 3 * M_PI / 2)
			left_textures(data, r);
		else
			right_textures(data, r);
	}
}

void	ray_coordinate(t_cub *data, int *i, int is_hor)
{
	int	pxy[2];
	int	pxy1[2];

	data->color = 0x0275d8;
	if (is_hor == 1)
	{
		pxy[0] = data->draw.px;
		pxy[1] = data->draw.py;
		pxy1[0] = data->cast.hx;
		pxy1[1] = data->cast.hy;
		data->cast.distances[(*i)++] = hor_ray_casting(data);
		data->cast.flag = 1;
		data->cast.color = 0xee7224;
	}
	else if (is_hor == 0)
	{
		pxy[0] = data->draw.px;
		pxy[1] = data->draw.py;
		pxy1[0] = data->cast.vx;
		pxy1[1] = data->cast.vy;
		data->cast.distances[(*i)++] = ver_ray_casting(data);
		data->cast.color = 0xefae7e;
		data->cast.flag = 0;
	}
}

void	draw_casted_rays(t_cub *data)
{
	int	r;
	int	i;

	r = -1;
	i = 0;
	allocate_distance_array(data);
	increment_ray_angle(data, 0);
	while (++r < WIDTH)
	{
		if (hor_ray_casting(data) < ver_ray_casting(data))
		{
			ray_coordinate(data, &i, 1);
			check_angle(data, r, 1);
		}
		else
		{
			ray_coordinate(data, &i, 0);
			check_angle(data, r, 0);
		}
		draw_ceil_floor(data, r);
		increment_ray_angle(data, 1);
	}
}

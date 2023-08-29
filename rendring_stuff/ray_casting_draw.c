/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:55:27 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/27 23:03:25 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_angle(t_cub *data, int r, int choice)
{
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
		draw_ceil_floor(data, r);
		if (data->sprit1 == 1)
			draw_fire_animation(data, r);
		else if (data->sprit2 == 1)
			draw_torch_animation(data, r);
		increment_ray_angle(data, 1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_draw.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:55:27 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/16 23:24:49 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		data->cast.color = 0x065535;
		check_before_draw(data, pxy, pxy1);
	}
	else if (is_hor == 0)
	{
		pxy[0] = data->draw.px;
		pxy[1] = data->draw.py;
		pxy1[0] = data->cast.vx;
		pxy1[1] = data->cast.vy;
		data->cast.distances[(*i)++] = ver_ray_casting(data);
		data->cast.color = 0x00ff00;
		check_before_draw(data, pxy, pxy1);
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
			ray_coordinate(data, &i, 1);
		else
			ray_coordinate(data, &i, 0);
		draw_walls(data, r);
		increment_ray_angle(data, 1);
	}
}

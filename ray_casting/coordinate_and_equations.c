/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinate_and_equations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:45:38 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/18 21:27:24 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	distance(t_cub *data, double x2, double y2)
{
	return (sqrt(((x2 - data->draw.px) * (x2 - data->draw.px))
			+ ((y2 - data->draw.py) * (y2 - data->draw.py))));
}

void	vertical_ray_equation(t_cub *data)
{
	if (data->cast.ray_ang > M_PI / 2 && data->cast.ray_ang < 3 * M_PI / 2)
	{
		data->cast.vx = floor(data->draw.px / UNIT) * UNIT - 0.000001;
		data->cast.vy = data->draw.py + (data->draw.px - data->cast.vx) 
			* -tan(data->cast.ray_ang);
		data->cast.vx_offs = -UNIT;
		data->cast.vy_offs = -data->cast.vx_offs * -tan(data->cast.ray_ang);
	}
	else if (data->cast.ray_ang < M_PI / 2 || data->cast.ray_ang > 3 * M_PI / 2)
	{
		data->cast.vx = floor(data->draw.px / UNIT) * UNIT + UNIT;
		data->cast.vx_offs = UNIT;
		data->cast.vy_offs = -data->cast.vx_offs * -tan(data->cast.ray_ang);
		data->cast.vy = data->draw.py + (data->draw.px - data->cast.vx) 
			* -tan(data->cast.ray_ang);
	}
	else if (data->cast.ray_ang == M_PI / 2 
		|| data->cast.ray_ang == 3 * M_PI / 2)
	{
		data->cast.vx = -1;
		data->cast.vy = -1;
	}
}

void	horizontal_ray_equation(t_cub *data)
{
	if (data->cast.ray_ang > M_PI)
	{
		data->cast.hy = floor(data->draw.py / UNIT) * UNIT - 0.000001;
		data->cast.hy_offs = -UNIT;
		data->cast.hx_offs = -data->cast.hy_offs / -tan(data->cast.ray_ang);
		data->cast.hx = data->draw.px + (data->draw.py - data->cast.hy) 
			/ tan(-data->cast.ray_ang);
	}
	if (data->cast.ray_ang < M_PI)
	{
		data->cast.hy = floor(data->draw.py / UNIT) * UNIT + UNIT;
		data->cast.hy_offs = UNIT;
		data->cast.hx_offs = -data->cast.hy_offs / -tan(data->cast.ray_ang);
		data->cast.hx = data->draw.px + (data->draw.py - data->cast.hy) 
			/ tan(-data->cast.ray_ang);
	}
	if (data->cast.ray_ang == 0 || data->cast.ray_ang == M_PI)
	{
		data->cast.hy = -1;
		data->cast.hx = -1;
	}
}

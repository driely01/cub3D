/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:30:05 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/14 16:20:21 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	distance(t_cub *data, double x2, double y2)
{
	return (sqrt(((x2 - data->draw.px) * (x2 - data->draw.px))
			+ ((y2 - data->draw.py) * (y2 - data->draw.py))));
}

// double	vertical_ray_casting(t_cub *data)
// {
// 	if (data->draw.pa > M_PI / 2 && data->draw.pa < 3 * M_PI / 2)
// 	{
// 		data->cast.vx = floor(data->draw.px / UNIT) * UNIT - 1;
// 		data->cast.vy = data->draw.py + (data->draw.px - data->cast.vx)
// 			* -tan(data->draw.pa);
// 		data->cast.vx_offs = -UNIT;
// 		data->cast.vy_offs = UNIT * -tan(data->draw.pa);
// 	}
// 	else if (data->draw.pa < M_PI / 2 || data->draw.pa > 3 * M_PI / 2)
// 	{
// 		data->cast.vx = floor(data->draw.px / UNIT) * UNIT + UNIT;
// 		data->cast.vx_offs = UNIT;
// 		data->cast.vy_offs = -UNIT * -tan(data->draw.pa);
// 		data->cast.vy = data->draw.py + (data->draw.px - data->cast.vx)
// 			* -tan(data->draw.pa);
// 	}
// 	else if (data->draw.pa == M_PI / 2 || data->draw.pa == 3 * M_PI / 2)
// 	{
// 		data->cast.vx = data->draw.px;
// 		data->cast.vy = data->draw.py;
// 	}	
	
// 	while (data->draw.pa != M_PI / 2 && data->draw.pa != 3 * M_PI / 2 
// 		&& data->cast.vx > 0 && data->cast.vy > 0 && data->cast.vy < data->cordt.height
// 		&& (size_t)floor(data->cast.vx / UNIT) < ft_strlen(data->draw.line[(int)floor(data->cast.vy / UNIT)]))
// 	{
// 		if (data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT)]
// 			&& data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT)] != '1')
// 		{
// 			data->cast.vx += data->cast.vx_offs;
// 			data->cast.vy += data->cast.vy_offs;
// 		}
// 		else
// 			break ;
// 	}
// 	return (distance(data, data->cast.vx, data->cast.vy));
// }

// double	ray_casting(t_cub *data)
// {
// 	if (data->draw.pa > M_PI)
// 	{
// 		data->cast.hy = floor(data->draw.py / UNIT) * UNIT - 1;
// 		data->cast.hy_offs = -UNIT;
// 		data->cast.hx_offs = UNIT / tan(-data->draw.pa);
// 		data->cast.hx = data->draw.px + (data->draw.py - data->cast.hy) / tan(-data->draw.pa);
// 	}
// 	if (data->draw.pa < M_PI)
// 	{
// 		data->cast.hy = floor(data->draw.py / UNIT) * UNIT + UNIT;
// 		data->cast.hy_offs = UNIT;
// 		data->cast.hx_offs = UNIT / tan(data->draw.pa);
// 		data->cast.hx = data->draw.px + (data->draw.py - data->cast.hy) / tan(-data->draw.pa);
// 	}
// 	if (data->draw.pa == 0 || data->draw.pa == M_PI)
// 	{
// 		data->cast.hy = data->draw.py;
// 		data->cast.hx = data->draw.px;
// 	}

// 	while (data->draw.pa != 0 && data->draw.pa != M_PI &&
// 		data->cast.hx >= 0 && data->cast.hy >= 0 && data->cast.hy < data->cordt.height
// 		&& (size_t)floor(data->cast.hx / UNIT) < ft_strlen(data->draw.line[(int)floor(data->cast.hy / UNIT)]))
// 	{
// 		if (data->draw.line[(int)floor(data->cast.hy / UNIT)][(int)floor(data->cast.hx / UNIT)]
// 			&& data->draw.line[(int)floor(data->cast.hy / UNIT)][(int)floor(data->cast.hx / UNIT)] != '1')
// 		{
// 			data->cast.hx += data->cast.hx_offs;
// 			data->cast.hy += data->cast.hy_offs;
// 		}
// 		else
// 			break;
// 	}
// 	return (distance(data, data->cast.hx, data->cast.hy));
// }

double	vertical_ray_casting(t_cub *data)
{
	if (data->cast.ray_ang > M_PI / 2 && data->cast.ray_ang < 3 * M_PI / 2)
	{
		data->cast.vx = floor(data->draw.px / UNIT) * UNIT - 1;
		data->cast.vy = data->draw.py + (data->draw.px - data->cast.vx)
			* -tan(data->cast.ray_ang);
		data->cast.vx_offs = -UNIT;
		data->cast.vy_offs = UNIT * -tan(data->cast.ray_ang);
	}
	else if (data->cast.ray_ang < M_PI / 2 || data->cast.ray_ang > 3 * M_PI / 2)
	{
		data->cast.vx = floor(data->draw.px / UNIT) * UNIT + UNIT;
		data->cast.vx_offs = UNIT;
		data->cast.vy_offs = -UNIT * -tan(data->cast.ray_ang);
		data->cast.vy = data->draw.py + (data->draw.px - data->cast.vx)
			* -tan(data->cast.ray_ang);
	}
	else if (data->cast.ray_ang == M_PI / 2 || data->cast.ray_ang == 3 * M_PI / 2)
	{
		data->cast.vx = data->draw.px;
		data->cast.vy = data->draw.py;
	}	
	
	while (data->cast.ray_ang != M_PI / 2 && data->cast.ray_ang != 3 * M_PI / 2 
		&& data->cast.vx > 0 && data->cast.vy > 0 && data->cast.vy < data->cordt.height
		&& (size_t)floor(data->cast.vx / UNIT) < ft_strlen(data->draw.line[(int)floor(data->cast.vy / UNIT)]))
	{
		if (data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT)]
			&& data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT)] != '1'
			&& data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT)] != ' '
			&& data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT)] != 0)
		{
			data->cast.vx += data->cast.vx_offs;
			data->cast.vy += data->cast.vy_offs;
		}
		else
			break ;
	}
	return (distance(data, data->cast.vx, data->cast.vy));
}

double	ray_casting(t_cub *data)
{
	if (data->cast.ray_ang > M_PI)
	{
		data->cast.hy = floor(data->draw.py / UNIT) * UNIT - 1;
		data->cast.hy_offs = -UNIT;
		data->cast.hx_offs = UNIT / tan(-data->cast.ray_ang);
		data->cast.hx = data->draw.px + (data->draw.py - data->cast.hy) / tan(-data->cast.ray_ang);
	}
	if (data->cast.ray_ang < M_PI)
	{
		data->cast.hy = floor(data->draw.py / UNIT) * UNIT + UNIT;
		data->cast.hy_offs = UNIT;
		data->cast.hx_offs = UNIT / tan(data->cast.ray_ang);
		data->cast.hx = data->draw.px + (data->draw.py - data->cast.hy) / tan(-data->cast.ray_ang);
	}
	if (data->cast.ray_ang == 0 || data->cast.ray_ang == M_PI)
	{
		data->cast.hy = data->draw.py;
		data->cast.hx = data->draw.px;
	}

	while (data->cast.ray_ang != 0 && data->cast.ray_ang != M_PI &&
		data->cast.hx >= 0 && data->cast.hy >= 0 && data->cast.hy < data->cordt.height
		&& (size_t)floor(data->cast.hx / UNIT) < ft_strlen(data->draw.line[(int)floor(data->cast.hy / UNIT)]))
	{
		if (data->draw.line[(int)floor(data->cast.hy / UNIT)][(int)floor(data->cast.hx / UNIT)]
			&& data->draw.line[(int)floor(data->cast.hy / UNIT)][(int)floor(data->cast.hx / UNIT)] != '1'
			&& data->draw.line[(int)floor(data->cast.hy / UNIT)][(int)floor(data->cast.hx / UNIT)] != ' '
			&& data->draw.line[(int)floor(data->cast.hy / UNIT)][(int)floor(data->cast.hx / UNIT)] != 0)
		{
			data->cast.hx += data->cast.hx_offs;
			data->cast.hy += data->cast.hy_offs;
		}
		else
			break;
	}
	return (distance(data, data->cast.hx, data->cast.hy));
}

void draw_ray(t_cub *data)
{
	int	pxy[2];
	int	pxy1[2];
	data->cast.ray_ang = data->draw.pa - ONE * 30;
	if (data->cast.ray_ang < 0) data->cast.ray_ang += 2 * M_PI;
	if (data->cast.ray_ang > 2 * M_PI) data->cast.ray_ang -= 2 * M_PI;
	for (int r = 0; r < WIDTH; r++)
	{
		if (ray_casting(data) == 0)
		{
			pxy[0] = data->draw.px;
			pxy[1] = data->draw.py;
			pxy1[0] = data->cast.vx;
			pxy1[1] = data->cast.vy;
			// data->color = 0x57f287;
			check_before_draw(data, pxy, pxy1);
		}
		else if (vertical_ray_casting(data) == 0)
		{
			pxy[0] = data->draw.px;
			pxy[1] = data->draw.py;
			pxy1[0] = data->cast.hx;
			pxy1[1] = data->cast.hy;
			// data->color = 0x57f287;
			check_before_draw(data, pxy, pxy1);
		}
		else if (ray_casting(data) < vertical_ray_casting(data))
		{
			pxy[0] = data->draw.px;
			pxy[1] = data->draw.py;
			pxy1[0] = data->cast.hx;
			pxy1[1] = data->cast.hy;
			// data->color = 0x57f287;
			check_before_draw(data, pxy, pxy1);
		}
		else if (ray_casting(data) > vertical_ray_casting(data))
		{
			pxy[0] = data->draw.px;
			pxy[1] = data->draw.py;
			pxy1[0] = data->cast.vx;
			pxy1[1] = data->cast.vy;
			// data->color = 0x57f287;
			check_before_draw(data, pxy, pxy1);
		}
		data->cast.ray_ang += INCANG;
		printf("ray angle: %f\n", data->cast.ray_ang);
		if (data->cast.ray_ang < 0) data->cast.ray_ang += 2 * M_PI;
		if (data->cast.ray_ang > 2 * M_PI) data->cast.ray_ang -= 2 * M_PI;
	}
}

// void	draw_ray(t_cub *data)
// {
// 	int	pxy[2];
// 	int	pxy1[2];
// 	if (ray_casting(data) == 0)
// 	{
// 		pxy[0] = data->draw.px;
// 		pxy[1] = data->draw.py;
// 		pxy1[0] = data->cast.vx;
// 		pxy1[1] = data->cast.vy;
// 		// data->color = 0x57f287;
// 		check_before_draw(data, pxy, pxy1);
// 	}
// 	else if (vertical_ray_casting(data) == 0)
// 	{
// 		pxy[0] = data->draw.px;
// 		pxy[1] = data->draw.py;
// 		pxy1[0] = data->cast.hx;
// 		pxy1[1] = data->cast.hy;
// 		// data->color = 0x57f287;
// 		check_before_draw(data, pxy, pxy1);
// 	}
// 	else if (ray_casting(data) < vertical_ray_casting(data))
// 	{
// 		pxy[0] = data->draw.px;
// 		pxy[1] = data->draw.py;
// 		pxy1[0] = data->cast.hx;
// 		pxy1[1] = data->cast.hy;
// 		// data->color = 0x57f287;
// 		check_before_draw(data, pxy, pxy1);
// 	}
// 	else if (ray_casting(data) > vertical_ray_casting(data))
// 	{
// 		pxy[0] = data->draw.px;
// 		pxy[1] = data->draw.py;
// 		pxy1[0] = data->cast.vx;
// 		pxy1[1] = data->cast.vy;
// 		// data->color = 0x57f287;
// 		check_before_draw(data, pxy, pxy1);
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:30:05 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/16 15:18:50 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

double	distance(t_cub *data, double x2, double y2)
{
	return (sqrt(((x2 - data->draw.px) * (x2 - data->draw.px))
			+ ((y2 - data->draw.py) * (y2 - data->draw.py))));
}

double	ver_ray_casting(t_cub *data)
{
	if (data->cast.ray_ang > M_PI / 2 && data->cast.ray_ang < 3 * M_PI / 2)
	{
		data->cast.vx = floor(data->draw.px / UNIT) * UNIT - 1;
		data->cast.vy = data->draw.py + (data->draw.px - data->cast.vx)
			* -tan(data->cast.ray_ang);
		data->cast.vx_offs = -UNIT;
		data->cast.vy_offs = -UNIT * tan(data->cast.ray_ang);
	}
	else if (data->cast.ray_ang < M_PI / 2 || data->cast.ray_ang > 3 * M_PI / 2)
	{
		data->cast.vx = floor(data->draw.px / UNIT) * UNIT + UNIT;
		data->cast.vx_offs = UNIT;
		data->cast.vy_offs = UNIT * tan(data->cast.ray_ang);
		data->cast.vy = data->draw.py + (data->draw.px - data->cast.vx)
			* -tan(data->cast.ray_ang);
	}
	else if (data->cast.ray_ang == M_PI / 2 || data->cast.ray_ang == 3 * M_PI / 2)
	{
		data->cast.vx = WIDTH;
		data->cast.vy = HEIGHT;
	}	
	while (data->cast.vx > 0 && data->cast.vy > 0 && data->cast.vy < data->cordt.height
		&& (size_t)floor(data->cast.vx / UNIT) < ft_strlen(data->draw.line[(int)floor(data->cast.vy / UNIT)]))
	{
		if (data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT)]
			&& data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT)] != '1'
			&& data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT)] != ' '
			&& data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT)] != 0)
		{
			if (data->cast.ray_ang > M_PI && data->cast.ray_ang < 3 * M_PI / 2
				&& data->draw.line[(int)floor(data->cast.vy / UNIT) + 1][(int)floor(data->cast.vx / UNIT)] == '1'
				&& data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT) + 1] == '1')
					break;
			else if (data->cast.ray_ang > 3 * M_PI / 2
				&& data->draw.line[(int)floor(data->cast.vy / UNIT) + 1][(int)floor(data->cast.vx / UNIT)] == '1'
				&& data->draw.line[(int)floor(data->cast.vy / UNIT)][(int)floor(data->cast.vx / UNIT) - 1] == '1')
					break;
			else
			{
				data->cast.vx += data->cast.vx_offs;
				data->cast.vy += data->cast.vy_offs;
			}
		}
		else
			break ;
	}
	return (distance(data, data->cast.vx, data->cast.vy));
}

double	hor_ray_casting(t_cub *data)
{
	if (data->cast.ray_ang > M_PI)
	{
		data->cast.hy = floor(data->draw.py / UNIT) * UNIT - 1;
		data->cast.hy_offs = -UNIT;
		data->cast.hx_offs = -UNIT / tan(data->cast.ray_ang);
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
		data->cast.hy = HEIGHT;
		data->cast.hx = WIDTH;
	}

	while (data->cast.hx >= 0 && data->cast.hy >= 0 && data->cast.hy < data->cordt.height
		&& (size_t)floor(data->cast.hx / UNIT) < ft_strlen(data->draw.line[(int)floor(data->cast.hy / UNIT)]))
	{
		if (data->draw.line[(int)floor(data->cast.hy / UNIT)][(int)floor(data->cast.hx / UNIT)]
			&& data->draw.line[(int)floor(data->cast.hy / UNIT)][(int)floor(data->cast.hx / UNIT)] != '1'
			&& data->draw.line[(int)floor(data->cast.hy / UNIT)][(int)floor((data->cast.hx + 1)/ UNIT)] != '1'
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
		check_before_draw(data, pxy, pxy1);
	}
	else if (is_hor == 0)
	{
		pxy[0] = data->draw.px;
		pxy[1] = data->draw.py;
		pxy1[0] = data->cast.vx;
		pxy1[1] = data->cast.vy;
		data->cast.distances[(*i)++] = ver_ray_casting(data);
		check_before_draw(data, pxy, pxy1);
	}
}

void	increment_ray_angle(t_cub *data, int is_increment)
{
	if (!is_increment)
	{	
		data->cast.ray_ang = data->draw.pa - ONE * 30;
		if (data->cast.ray_ang < 0)
			data->cast.ray_ang += 2 * M_PI;
		if (data->cast.ray_ang > 2 * M_PI)
			data->cast.ray_ang -= 2 * M_PI;
	}
	else
	{
		data->cast.ray_ang += INCANG;
		if (data->cast.ray_ang < 0)
			data->cast.ray_ang += 2 * M_PI;
		if (data->cast.ray_ang > 2 * M_PI)
			data->cast.ray_ang -= 2 * M_PI;
	}
}

void	allocate_distance_array(t_cub *data)
{
	if (!data->cast.distances)
	{
		data->cast.distances = malloc(sizeof(double) * WIDTH);
		if (!data->cast.distances)
			return ;
	}
	else
	{
		free(data->cast.distances);
		data->cast.distances = malloc(sizeof(double) * WIDTH);
		if (!data->cast.distances)
			return ;
	}
}

void	draw_ray(t_cub *data)
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
			ray_coordinate(data, &i,  1);
		else
			ray_coordinate(data, &i,  0);
		increment_ray_angle(data, 1);
	}
	// i = -1;
	// while (++i < WIDTH)
	// 	printf("distance = %f\n", data->cast.distances[i]);
	// exit (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:30:05 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/15 21:25:09 by del-yaag         ###   ########.fr       */
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

// while (y_w >= 0 && x_w > 0 && y_w < data->cordt.height && x_w < data->cordt.width
// 		&& data->draw.line[(int)floor(y_w / UNIT)][(int)floor(x_w / UNIT)] != '1'
// 		&& data->draw.line[(int)floor(y_w / UNIT)][(int)floor(x_w / UNIT)] != ' '
// 		&& data->draw.line[(int)floor(y_w / UNIT)][(int)floor(x_w / UNIT)] != 0)
// {
// 	if (ra > M_PI / 2 && ra < M_PI)
// 	{
// 		if (data->draw.line[(int)floor(y_w / UNIT) - 1][(int)floor(x_w / UNIT)] == '1'
// 			&& data->draw.line[(int)floor(y_w / UNIT)][(int)floor(x_w / UNIT) + 1] == '1')
// 			break;
// 	}
// 	else if (ra > M_PI && ra < 3 * M_PI / 2)
// 	{
// 		if (data->draw.line[(int)floor(y_w / UNIT) + 1][(int)floor(x_w / UNIT)] == '1'
// 			&& data->draw.line[(int)floor(y_w / UNIT)][(int)floor(x_w / UNIT) + 1] == '1')
// 			break;
// 	}
// 	else if (ra > 3 * M_PI / 2)
// 	{
// 		if (data->draw.line[(int)floor(y_w / UNIT) + 1][(int)floor(x_w / UNIT)] == '1'
// 			&& data->draw.line[(int)floor(y_w / UNIT)][(int)floor(x_w / UNIT) - 1] == '1')
// 			break;
// 	}
// 	if (ra > 0 && ra < M_PI)
// 	{
// 		y_w += UNIT;
// 		x_w += UNIT / tan(ra);
// 	}
// 	else
// 	{
// 		y_w -= UNIT;
// 		x_w += UNIT / -tan(ra);
// 	}
// }
	
double	vertical_ray_casting(t_cub *data)
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
		data->cast.vx = data->cordt.width;
		data->cast.vy = data->cordt.height;
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

double	ray_casting(t_cub *data)
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
		data->cast.hy = data->cordt.height;
		data->cast.hx = data->cordt.width;
	}

	while (data->cast.ray_ang != 0 && data->cast.ray_ang != M_PI &&
		data->cast.hx >= 0 && data->cast.hy >= 0 && data->cast.hy < data->cordt.height
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
		data->cast.distances[(*i)++] = vertical_ray_casting(data);
		check_before_draw(data, pxy, pxy1);
	}
	else if (is_hor == 0)
	{
		pxy[0] = data->draw.px;
		pxy[1] = data->draw.py;
		pxy1[0] = data->cast.vx;
		pxy1[1] = data->cast.vy;
		data->cast.distances[(*i)++] = ray_casting(data);
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
		if (ray_casting(data) == 0)
			ray_coordinate(data, &i,  0);
		else if (vertical_ray_casting(data) == 0)
			ray_coordinate(data, &i,  1);
		if (ray_casting(data) < vertical_ray_casting(data))
			ray_coordinate(data, &i,  1);
		else if (ray_casting(data) > vertical_ray_casting(data))
			ray_coordinate(data, &i,  0);
		increment_ray_angle(data, 1);
	}
	// i = -1;
	// while (++i < WIDTH)
	// 	printf("distance = %f\n", data->cast.distances[i]);
	// exit (1);
}
// void draw_ray(t_cub *data)
// {
// 	int	pxy[2];
// 	int	pxy1[2];
// 	data->cast.ray_ang = data->draw.pa - ONE * 30;
// 	if (data->cast.ray_ang < 0) data->cast.ray_ang += 2 * M_PI;
// 	if (data->cast.ray_ang > 2 * M_PI) data->cast.ray_ang -= 2 * M_PI;
// 	for (int r = 0; r < WIDTH; r++)
// 	{
// 		if (ray_casting(data) == 0)
// 		{
// 			pxy[0] = data->draw.px;
// 			pxy[1] = data->draw.py;
// 			pxy1[0] = data->cast.vx;
// 			pxy1[1] = data->cast.vy;
// 		}
// 		else if (vertical_ray_casting(data) == 0)
// 		{
// 			pxy[0] = data->draw.px;
// 			pxy[1] = data->draw.py;
// 			pxy1[0] = data->cast.hx;
// 			pxy1[1] = data->cast.hy;
// 		}
// 		else if (ray_casting(data) < vertical_ray_casting(data))
// 		{
// 			pxy[0] = data->draw.px;
// 			pxy[1] = data->draw.py;
// 			pxy1[0] = data->cast.hx;
// 			pxy1[1] = data->cast.hy;
// 		}
// 		else if (ray_casting(data) > vertical_ray_casting(data))
// 		{
// 			pxy[0] = data->draw.px;
// 			pxy[1] = data->draw.py;
// 			pxy1[0] = data->cast.vx;
// 			pxy1[1] = data->cast.vy;
// 		}
// 		data->color = 0x0275d8;
// 		check_before_draw(data, pxy, pxy1);
// 		data->cast.ray_ang += INCANG;
// 		if (data->cast.ray_ang < 0) data->cast.ray_ang += 2 * M_PI;
// 		if (data->cast.ray_ang > 2 * M_PI) data->cast.ray_ang -= 2 * M_PI;
// 	}
// }

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

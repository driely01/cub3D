/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:30:05 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 01:16:14 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_is_ver_wall(t_cub *data)
{
	if (data->cast.ray_ang > M_PI && data->cast.ray_ang < 3 * M_PI / 2
		&& data->draw.line[(int)(data->cast.vy / UNIT) + 1] \
		[(int)(data->cast.vx / UNIT)] == '1'
		&& data->draw.line[(int)(data->cast.vy / UNIT)] \
		[(int)(data->cast.vx / UNIT) + 1] == '1')
		return (0);
	else if (data->cast.ray_ang > M_PI / 2 && data->cast.ray_ang < M_PI
		&& data->draw.line[(int)(data->cast.vy / UNIT) - 1] \
		[(int)(data->cast.vx / UNIT)] == '1'
		&& data->draw.line[(int)(data->cast.vy / UNIT)] \
		[(int)(data->cast.vx / UNIT) + 1] == '1')
		return (0);
	else if (data->cast.ray_ang > 3 * M_PI / 2
		&& data->draw.line[(int)(data->cast.vy / UNIT) + 1] \
		[(int)(data->cast.vx / UNIT)] == '1'
		&& data->draw.line[(int)(data->cast.vy / UNIT)] \
		[(int)(data->cast.vx / UNIT) - 1] == '1')
		return (0);
	else
	{
		data->cast.vx += data->cast.vx_offs;
		data->cast.vy += data->cast.vy_offs;
	}
	return (1);
}

int	check_is_hor_wall(t_cub *data)
{
	if (data->cast.ray_ang > M_PI && data->cast.ray_ang < 3 * M_PI / 2
		&& data->draw.line[(int)(data->cast.hy / UNIT) + 1] \
		[(int)(data->cast.hx / UNIT)] == '1'
		&& data->draw.line[(int)(data->cast.hy / UNIT)] \
		[(int)(data->cast.hx / UNIT) + 1] == '1')
		return (0);
	else if (data->cast.ray_ang > M_PI / 2 && data->cast.ray_ang < M_PI
		&& data->draw.line[(int)(data->cast.hy / UNIT) - 1] \
		[(int)(data->cast.hx / UNIT)] == '1'
		&& data->draw.line[(int)(data->cast.hy / UNIT)] \
		[(int)(data->cast.hx / UNIT) + 1] == '1')
		return (0);
	else if (data->cast.ray_ang > 3 * M_PI / 2
		&& data->draw.line[(int)(data->cast.hy / UNIT) + 1] \
		[(int)(data->cast.hx / UNIT)] == '1'
		&& data->draw.line[(int)(data->cast.hy / UNIT)] \
		[(int)(data->cast.hx / UNIT) - 1] == '1')
		return (0);
	else
	{
		data->cast.hx += data->cast.hx_offs;
		data->cast.hy += data->cast.hy_offs;
	}
	return (1);
}

double	ver_ray_casting(t_cub *data)
{
	data->cast.d_vx = 0;
	data->cast.d_vy = 0;
	vertical_ray_equation(data);
	while (data->cast.vx > 0 && data->cast.vy > 0
		&& data->cast.vy < data->cordt.height
		&& (data->cast.vx / UNIT) < \
		ft_strlen(data->draw.line[(int)(data->cast.vy / UNIT)]))
	{
		if (data->draw.line[(int)(data->cast.vy / UNIT)] \
		[(int)(data->cast.vx / UNIT)]
			&& data->draw.line[(int)(data->cast.vy / UNIT)] \
			[(int)(data->cast.vx / UNIT)] != '1'
			&& data->draw.line[(int)(data->cast.vy / UNIT)] \
			[(int)(data->cast.vx / UNIT)] != ' '
			&& data->draw.line[(int)(data->cast.vy / UNIT)] \
			[(int)(data->cast.vx / UNIT)] != 0)
		{
			door_ver_coordinates(data);
			if (!check_is_ver_wall(data))
				break ;
		}
		else
			break ;
	}
	return (distance(data, data->cast.vx, data->cast.vy));
}

double	hor_ray_casting(t_cub *data)
{
	data->cast.d_hx = 0;
	data->cast.d_hx = 0;
	horizontal_ray_equation(data);
	while (data->cast.hx >= 0 && data->cast.hy >= 0
		&& data->cast.hy < data->cordt.height
		&& (data->cast.hx / UNIT) < \
		ft_strlen(data->draw.line[(int)(data->cast.hy / UNIT)]))
	{
		if (data->draw.line[(int)(data->cast.hy / UNIT)] \
			[(int)(data->cast.hx / UNIT)]
			&& data->draw.line[(int)(data->cast.hy / UNIT)] \
			[(int)(data->cast.hx / UNIT)] != '1'
			&& data->draw.line[(int)(data->cast.hy / UNIT)] \
			[(int)(data->cast.hx / UNIT)] != ' '
			&& data->draw.line[(int)(data->cast.hy / UNIT)] \
			[(int)(data->cast.hx / UNIT)] != 0)
		{
			door_hor_coordinates(data);
			if (!check_is_hor_wall(data))
				break ;
		}
		else
			break ;
	}
	return (distance(data, data->cast.hx, data->cast.hy));
}

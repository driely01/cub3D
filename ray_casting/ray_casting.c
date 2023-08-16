/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 14:30:05 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/16 15:55:57 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_is_ver_wall(t_cub *data)
{
	if (data->cast.ray_ang > M_PI && data->cast.ray_ang < 3 * M_PI / 2
		&& data->draw.line[(int)floor(data->cast.vy / UNIT) + 1] \
		[(int)floor(data->cast.vx / UNIT)] == '1'
		&& data->draw.line[(int)floor(data->cast.vy / UNIT)] \
		[(int)floor(data->cast.vx / UNIT) + 1] == '1')
		return (0);
	else if (data->cast.ray_ang > 3 * M_PI / 2
		&& data->draw.line[(int)floor(data->cast.vy / UNIT) + 1] \
		[(int)floor(data->cast.vx / UNIT)] == '1'
		&& data->draw.line[(int)floor(data->cast.vy / UNIT)] \
		[(int)floor(data->cast.vx / UNIT) - 1] == '1')
		return (0);
	else
	{
		data->cast.vx += data->cast.vx_offs;
		data->cast.vy += data->cast.vy_offs;
	}
	return (1);
}

double	ver_ray_casting(t_cub *data)
{
	vertical_ray_equation(data);
	while (data->cast.vx > 0 && data->cast.vy > 0
		&& data->cast.vy < data->cordt.height
		&& (size_t)floor(data->cast.vx / UNIT) < \
		ft_strlen(data->draw.line[(int)floor(data->cast.vy / UNIT)]))
	{
		if (data->draw.line[(int)floor(data->cast.vy / UNIT)] \
			[(int)floor(data->cast.vx / UNIT)]
			&& data->draw.line[(int)floor(data->cast.vy / UNIT)] \
			[(int)floor(data->cast.vx / UNIT)] != '1'
			&& data->draw.line[(int)floor(data->cast.vy / UNIT)] \
			[(int)floor(data->cast.vx / UNIT)] != ' '
			&& data->draw.line[(int)floor(data->cast.vy / UNIT)] \
			[(int)floor(data->cast.vx / UNIT)] != 0)
		{
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
	horizontal_ray_equation(data);
	while (data->cast.hx >= 0 && data->cast.hy >= 0
		&& data->cast.hy < data->cordt.height
		&& (size_t)floor(data->cast.hx / UNIT) < \
		ft_strlen(data->draw.line[(int)floor(data->cast.hy / UNIT)]))
	{
		if (data->draw.line[(int)floor(data->cast.hy / UNIT)] \
			[(int)floor(data->cast.hx / UNIT)]
			&& data->draw.line[(int)floor(data->cast.hy / UNIT)] \
			[(int)floor(data->cast.hx / UNIT)] != '1'
			&& data->draw.line[(int)floor(data->cast.hy / UNIT)] \
			[(int)floor((data->cast.hx + 1) / UNIT)] != '1'
			&& data->draw.line[(int)floor(data->cast.hy / UNIT)] \
			[(int)floor(data->cast.hx / UNIT)] != ' '
			&& data->draw.line[(int)floor(data->cast.hy / UNIT)] \
			[(int)floor(data->cast.hx / UNIT)] != 0)
		{
			data->cast.hx += data->cast.hx_offs;
			data->cast.hy += data->cast.hy_offs;
		}
		else
			break ;
	}
	return (distance(data, data->cast.hx, data->cast.hy));
}
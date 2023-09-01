/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_silde.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:54:01 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 01:15:13 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	backward_slid(t_cub *data, double prevpx, double prevpy)
{
	if (data->draw.line[(int)floor(data->draw.py / UNIT)] \
			[(int)floor(prevpx / UNIT)] != '1'
		&& check_door(data, prevpx, data->draw.py))
		data->draw.px -= data->draw.pdx;
	else if (data->draw.line[(int)floor(prevpy / UNIT)] \
		[(int)floor(data->draw.px / UNIT)] != '1'
		&& check_door(data, data->draw.px, prevpy))
		data->draw.py -= data->draw.pdy;
}

void	forward_slid(t_cub *data, double nextpx, double nextpy)
{
	if (data->draw.line[(int)floor(data->draw.py / UNIT)] \
			[(int)floor(nextpx / UNIT)] != '1'
		&& check_door(data, nextpx, data->draw.py))
		data->draw.px += data->draw.pdx;
	else if (data->draw.line[(int)floor(nextpy / UNIT)] \
		[(int)floor(data->draw.px / UNIT)] != '1'
		&& check_door(data, data->draw.px, nextpy))
		data->draw.py += data->draw.pdy;
}

void	right_slide_wall(t_cub *data, double prevpx, double prevpy)
{
	if (data->draw.line[(int)floor(data->draw.py / UNIT)] \
		[(int)floor(prevpx / UNIT)] != '1'
		&& check_door(data, prevpx, data->draw.py))
	{
		if (data->draw.forward || data->draw.backward)
			data->draw.px -= sin(M_PI - data->draw.pa);
		else
			data->draw.px -= sin(M_PI - data->draw.pa) * RAY;
	}
	else if (data->draw.line[(int)floor(prevpy / UNIT)] \
		[(int)floor(data->draw.px / UNIT)] != '1'
		&& check_door(data, data->draw.px, prevpy))
	{
		if (data->draw.forward || data->draw.backward)
			data->draw.py -= cos(M_PI - data->draw.pa);
		else
			data->draw.py -= cos(M_PI - data->draw.pa) * RAY;
	}
}

void	left_slide_wall(t_cub *data, double nextpx, double nextpy)
{
	if (data->draw.line[(int)floor(data->draw.py / UNIT)] \
		[(int)floor(nextpx / UNIT)] != '1'
		&& check_door(data, nextpx, data->draw.py))
	{
		if (data->draw.forward || data->draw.backward)
			data->draw.px += sin(M_PI - data->draw.pa);
		else
			data->draw.px += sin(M_PI - data->draw.pa) * RAY;
	}
	else if (data->draw.line[(int)floor(nextpy / UNIT)] \
		[(int)floor(data->draw.px / UNIT)] != '1'
		&& check_door(data, data->draw.px, nextpy))
	{
		if (data->draw.forward || data->draw.backward)
			data->draw.py += cos(M_PI - data->draw.pa);
		else
			data->draw.py += cos(M_PI - data->draw.pa) * RAY;
	}
}

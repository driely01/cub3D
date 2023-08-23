/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_rotations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:34:43 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/23 18:39:49 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	move_backward(t_cub *data)
{
	double	prevpx;
	double	prevpy;

	prevpx = data->draw.px - data->draw.pdx * 6;
	prevpy = data->draw.py - data->draw.pdy * 6;
	if (data->draw.backward == 1)
	{
		if (data->draw.line[(int)floor(prevpy / UNIT)] \
		[(int)floor(data->draw.px / UNIT)] != '1'
			&& data->draw.line[(int)floor(data->draw.py / UNIT)] \
			[(int)floor(prevpx / UNIT)] != '1'
			&& data->draw.line[(int)floor(prevpy / UNIT)] \
			[(int)floor(prevpx / UNIT)] != '1')
		{
			data->draw.px -= data->draw.pdx;
			data->draw.py -= data->draw.pdy;
		}
		else if (data->draw.line[(int)floor(data->draw.py / UNIT)] \
			[(int)floor(prevpx / UNIT)] != '1')
			data->draw.px -= data->draw.pdx;
		else if (data->draw.line[(int)floor(prevpy / UNIT)] \
		[(int)floor(data->draw.px / UNIT)] != '1')
			data->draw.py -= data->draw.pdy;
	}
}

void	straight_move(t_cub *data)
{
	double	nextpx;
	double	nextpy;

	nextpx = data->draw.px + data->draw.pdx * 6;
	nextpy = data->draw.py + data->draw.pdy * 6;
	if (data->draw.forward == 1)
	{
		if (data->draw.line[(int)floor(nextpy / UNIT)] \
		[(int)floor(data->draw.px / UNIT)] != '1'
			&& data->draw.line[(int)floor(data->draw.py / UNIT)] \
			[(int)floor(nextpx / UNIT)] != '1'
			&& data->draw.line[(int)floor(nextpy / UNIT)] \
			[(int)floor(nextpx / UNIT)] != '1')
		{
			data->draw.px += data->draw.pdx;
			data->draw.py += data->draw.pdy;
		}
		else if (data->draw.line[(int)floor(data->draw.py / UNIT)] \
			[(int)floor(nextpx / UNIT)] != '1')
			data->draw.px += data->draw.pdx;
		else if (data->draw.line[(int)floor(nextpy / UNIT)] \
		[(int)floor(data->draw.px / UNIT)] != '1')
			data->draw.py += data->draw.pdy;
	}
	move_backward(data);
}

void	mouse_rot(t_cub *data)
{
	if (data->draw.rotleft == 2)
	{
		data->draw.pa += (-atan(data->draw.xdistance))
			* M_PI * data->draw.rotangl * 0.001;
		if (data->draw.pa < 0)
			data->draw.pa += 2 * M_PI;
		if (data->draw.pa > 2 * M_PI)
			data->draw.pa -= 2 * M_PI;
		data->draw.pdx = cos(data->draw.pa) * RAY;
		data->draw.pdy = sin(data->draw.pa) * RAY;
		data->draw.rotleft = 0;
	}
}

void	move_rotate_player(t_cub *data)
{
	straight_move(data);
	lateral_move(data);
	mouse_rot(data);
	if (data->draw.rotleft == 1)
	{
		data->draw.pa -= ANGLE;
		if (data->draw.pa < 0)
			data->draw.pa += 2 * M_PI;
		data->draw.pdx = cos(data->draw.pa) * RAY;
		data->draw.pdy = sin(data->draw.pa) * RAY;
	}
	if (data->draw.rotright == 1)
	{
		data->draw.pa += ANGLE;
		if (data->draw.pa > 2 * M_PI)
			data->draw.pa -= 2 * M_PI;
		data->draw.pdx = cos(data->draw.pa) * RAY;
		data->draw.pdy = sin(data->draw.pa) * RAY;
	}
}

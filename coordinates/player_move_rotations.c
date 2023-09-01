/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_rotations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:34:43 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 01:14:15 by amoukhle         ###   ########.fr       */
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
			[(int)floor(prevpx / UNIT)] != '1'
			&& check_door(data, prevpx, prevpy))
		{
			data->draw.px -= data->draw.pdx;
			data->draw.py -= data->draw.pdy;
		}
		else
			forward_slid(data, prevpx, prevpy);
	}
}

int	check_door(t_cub *data, double nextpx, double nextpy)
{
	t_door	*p;

	if (data->draw.line[(int)floor(nextpy / UNIT)] \
		[(int)floor(nextpx / UNIT)] == 'D')
	{
		p = data->doors;
		while (p)
		{
			if (p->i == (int)floor(nextpy / UNIT)
				&& p->j == (int)floor(nextpx / UNIT))
				break ;
			p = p->next;
		}
		if (p->status == 0)
			return (0);
	}
	return (1);
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
			[(int)floor(nextpx / UNIT)] != '1'
			&& check_door(data, nextpx, nextpy))
		{
			data->draw.px += data->draw.pdx;
			data->draw.py += data->draw.pdy;
		}
		else
			forward_slid(data, nextpx, nextpy);
	}
	move_backward(data);
}

void	mouse_rot(t_cub *data)
{
	if (data->draw.rotleft == 2)
	{
		data->draw.pa += (-atan(data->draw.xdistance))
			* M_PI * data->draw.rotangl * 0.0009;
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

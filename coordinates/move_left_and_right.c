/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left_and_right.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 16:01:38 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/13 12:01:24 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	lateral_move(t_cub *data)
{
	if (data->draw.moveleft == 1)
		move_left_and_check(data);
	if (data->draw.moveright == 1)
		move_right_end_check(data);
}

void	move_left_and_check(t_cub *data)
{
	double	nextpx;
	double	nextpy;

	nextpx = data->draw.px + sin(M_PI - data->draw.pa) * 1.5;
	nextpy = data->draw.py + cos(M_PI - data->draw.pa) * 1.5;
	if (data->draw.line[(int)floor(nextpy / UNIT)] \
	[(int)floor(data->draw.px / UNIT)] != '1'
		&& data->draw.line[(int)floor(data->draw.py / UNIT)] \
		[(int)floor(nextpx / UNIT)] != '1')
	{
		if (data->draw.forward || data->draw.backward)
		{
			data->draw.px += sin(M_PI - data->draw.pa);
			data->draw.py += cos(M_PI - data->draw.pa);
		}
		else
		{
			data->draw.px += sin(M_PI - data->draw.pa) * 1.5;
			data->draw.py += cos(M_PI - data->draw.pa) * 1.5;
		}
	}
}

void	move_right_end_check(t_cub *data)
{
	double	prevpx;
	double	prevpy;

	prevpx = data->draw.px - sin(M_PI - data->draw.pa) * 1.5;
	prevpy = data->draw.py - cos(M_PI - data->draw.pa) * 1.5;
	if (data->draw.line[(int)floor(prevpy / UNIT)] \
	[(int)floor(data->draw.px / UNIT)] != '1'
		&& data->draw.line[(int)floor(data->draw.py / UNIT)] \
		[(int)floor(prevpx / UNIT)] != '1')
	{
		if (data->draw.forward || data->draw.backward)
		{
			data->draw.px -= sin(M_PI - data->draw.pa);
			data->draw.py -= cos(M_PI - data->draw.pa);
		}
		else
		{
			data->draw.px -= sin(M_PI - data->draw.pa) * 1.5;
			data->draw.py -= cos(M_PI - data->draw.pa) * 1.5;
		}
	}
}

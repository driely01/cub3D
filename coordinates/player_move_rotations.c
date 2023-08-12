/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_rotations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:34:43 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/12 16:02:04 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    straight_move(t_cub *data)
{
	double nextpx;
	double nextpy;
	double prevpx;
	double prevpy;

	nextpx = data->draw.px + data->draw.pdx;
	nextpy = data->draw.py + data->draw.pdy;
	prevpx = data->draw.px - data->draw.pdx;
	prevpy = data->draw.py - data->draw.pdy;

	if (data->draw.forward == 1)
	{
		if (data->draw.line[(int)floor(nextpy / UNIT)][(int)floor(data->draw.px / UNIT)] != '1'
		&& data->draw.line[(int)floor(data->draw.py / UNIT)][(int)floor(nextpx / UNIT)] != '1')
		{
			data->draw.px += data->draw.pdx;
			data->draw.py += data->draw.pdy;
		}
	}
	if (data->draw.backward == 1)
	{
		if (data->draw.line[(int)floor(prevpy / UNIT)][(int)floor(data->draw.px / UNIT)] != '1'
		&& data->draw.line[(int)floor(data->draw.py / UNIT)][(int)floor(prevpx / UNIT)] != '1')
		{
			data->draw.px -= data->draw.pdx;
			data->draw.py -= data->draw.pdy;
		}
	}
}

void move_rotate_player(t_cub *data)
{
    straight_move(data);
    lateral_move(data);
    if (data->draw.rotleft == 1)
    {
        data->draw.pa -= 0.059;
        if (data->draw.pa < 0)
            data->draw.pa += 2 * M_PI;
        data->draw.pdx = cos(data->draw.pa) * 1.5;
        data->draw.pdy = sin(data->draw.pa) * 1.5;
    }
    if (data->draw.rotright == 1)
    {
        data->draw.pa += 0.059;
        if (data->draw.pa > 2 * M_PI)
            data->draw.pa -= 2 * M_PI;
        data->draw.pdx = cos(data->draw.pa) * 1.5;
        data->draw.pdy = sin(data->draw.pa) * 1.5;
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:10:14 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/11 20:39:34 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int destroy(t_cub *data)
{
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit (0);
    return (0);
}

int movement(int code, t_cub *data)
{
    double nextpx;
    double nextpy;
    double prevpx;
    double prevpy;

    nextpx = data->draw.px + data->draw.pdx;
    nextpy = data->draw.py + data->draw.pdy;
    prevpx = data->draw.px - data->draw.pdx;
    prevpy = data->draw.py - data->draw.pdy;
    
    if (code == ESC)
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit (0);
    }
    else if (code == KEY_W)
    {
        if (data->draw.line[(int)floor(nextpy / UNIT)][(int)floor(data->draw.px / UNIT)] != '1'
            && data->draw.line[(int)floor(data->draw.py / UNIT)][(int)floor(nextpx / UNIT)] != '1')
        {
            data->draw.px += data->draw.pdx;
            data->draw.py += data->draw.pdy;
            draw_move_player_2d(data);
        }
    }
    else if (code == KEY_S)
    {
        if (data->draw.line[(int)floor(prevpy / UNIT)][(int)floor(data->draw.px / UNIT)] != '1'
            && data->draw.line[(int)floor(data->draw.py / UNIT)][(int)floor(prevpx / UNIT)] != '1')
        {
            data->draw.px -= data->draw.pdx;
            data->draw.py -= data->draw.pdy;
            draw_move_player_2d(data);
        }
    }
    else if (code == LEFT)
    {
        data->draw.pa -= 0.05;
        if (data->draw.pa < 0)
            data->draw.pa += 2 * M_PI;
        data->draw.pdx = cos(data->draw.pa) * 5;
        data->draw.pdy = sin(data->draw.pa) * 5;
        draw_move_player_2d(data);
    }
    else if (code == RIGHT)
    {
        data->draw.pa += 0.05;
        if (data->draw.pa > 2 * M_PI)
            data->draw.pa -= 2 * M_PI;
        data->draw.pdx = cos(data->draw.pa) * 5;
        data->draw.pdy = sin(data->draw.pa) * 5;
        draw_move_player_2d(data);
    }
    else
        return (0);
    return (0);
}
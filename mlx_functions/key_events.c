/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:10:14 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/09 20:22:37 by del-yaag         ###   ########.fr       */
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
    if (code == ESC)
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit (0);
    }
    else if (code == KEY_W)
    {
        if (data->draw.py1 > 0)
        {
            data->draw.py1 -= 5;
            data->draw.py2 -= 5;
            printf("p(%d, %d)\n", data->draw.px1, data->draw.py1);
            printf("p(%d, %d)\n", data->draw.px2, data->draw.py2);
            draw_move_player_2d(data);
        }
    }
    else if (code == KEY_S)
    {
        if (data->draw.py2 <= data->cordt.height)
        {
            data->draw.py1 += 5;
            data->draw.py2 += 5;
            printf("p(%d, %d)\n", data->draw.px1, data->draw.py1);
            printf("p(%d, %d)\n", data->draw.px2, data->draw.py2);
            draw_move_player_2d(data);
        }
    }
    else if (code == KEY_A)
    {
        if (data->draw.px1 > 0)
        {
            data->draw.px1 -= 5;
            data->draw.px2 -= 5;
            printf("p(%d, %d)\n", data->draw.px1, data->draw.py1);
            printf("p(%d, %d)\n", data->draw.px2, data->draw.py2);
            draw_move_player_2d(data);
        }
    }
    else if (code == KEY_D)
    {
        if (data->draw.px2 <= data->cordt.width)
        {
            data->draw.px1 += 5;
            data->draw.px2 += 5;
            printf("p(%d, %d)\n", data->draw.px1, data->draw.py1);
            printf("p(%d, %d)\n", data->draw.px2, data->draw.py2);
            draw_move_player_2d(data);
        }
    }
    else
        return (0);
    return (0);
}
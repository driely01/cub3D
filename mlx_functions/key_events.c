/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:10:14 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/10 20:37:54 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int destroy(t_cub *data)
{
    mlx_destroy_window(data->mlx, data->mlx_win);
    exit (0);
    return (0);
}

// int movement(int code, t_cub *data)
// {
//     int up;
//     int down;
//     int left;
//     int right;

//     up = data->draw.py - 5;
//     down = data->draw.py + 5;
//     left = data->draw.px - 5;
//     right = data->draw.px + 5;
    
//     if (code == ESC)
//     {
//         mlx_destroy_window(data->mlx, data->mlx_win);
//         exit (0);
//     }
//     else if (code == KEY_W)
//     {
//         printf("%d, %d\n", (int)data->draw.px / UNIT, (int)up / UNIT);
//         if (data->draw.py > 0)
//         {
//             data->draw.py -= 5;
//             printf("p(%d, %d)\n", data->draw.px, data->draw.py);
//             draw_move_player_2d(data);
//         }
//     }
//     else if (code == KEY_S)
//     {
//         if (data->draw.py <= data->cordt.height)
//         {
//             data->draw.py += 5;
//             printf("p(%d, %d)\n", data->draw.px, data->draw.py);
//             draw_move_player_2d(data);
//         }
//     }
//     else if (code == KEY_A)
//     {
//         if (data->draw.px > 0)
//         {
//             data->draw.px -= 5;
//             printf("p(%d, %d)\n", data->draw.px, data->draw.py);
//             draw_move_player_2d(data);
//         }
//     }
//     else if (code == KEY_D)
//     {
//         if (data->draw.px <= data->cordt.width)
//         {
//             data->draw.px += 5;
//             printf("p(%d, %d)\n", data->draw.px, data->draw.py);
//             draw_move_player_2d(data);
//         }
//     }
//     else
//         return (0);
//     return (0);
// }
int movement(int code, t_cub *data)
{

    mlx_destroy_image(data->mlx, data->img);
    data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
    data->addr = mlx_get_data_addr(data->img, &data->bits_per_pixel,
            &data->line_lenght, &data->endian);
    if (code == ESC)
    {
        mlx_destroy_window(data->mlx, data->mlx_win);
        exit (0);
    }
    else if (code == KEY_W)
    {
        data->rot.px += data->rot.pdx;
        data->rot.py += data->rot.pdy;
    }
    else if (code == KEY_S)
    {
        data->rot.px -= data->rot.pdx;
        data->rot.py -= data->rot.pdy;
    }
    else if (code == KEY_A)
    {
        data->rot.pa -= 0.1;
        if (data->rot.pa < 0)
            data->rot.pa += 2 * PI;
        data->rot.pdx = cos(data->rot.pa) * 5;
        data->rot.pdy = sin(data->rot.pa) * 5;
    }
    else if (code == KEY_D)
    {
        data->rot.pa += 0.1;
        if (data->rot.pa > 2 * PI)
            data->rot.pa -= 2 * PI;
        data->rot.pdx = cos(data->rot.pa) * 5;
        data->rot.pdy = sin(data->rot.pa) * 5;
    }
    else
        return (0);
    data->color = 0xffffff;
    check_before_draw(data, data->rot.px, data->rot.py, data->rot.px + data->rot.pdx * 50, data->rot.py + data->rot.pdy * 50);
    mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
    return (0);
}
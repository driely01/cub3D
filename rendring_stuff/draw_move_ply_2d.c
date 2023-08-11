/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move_ply_2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:51:49 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/11 15:51:15 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    initail_and_fill_player(t_cub *img, int i, int j)
{
    img->draw.x1 = j * UNIT;
    img->draw.x2 = j * UNIT + UNIT;
    img->draw.y1 = i * UNIT;
    img->draw.y2 = i * UNIT + UNIT;
    img->color = 0xffffff;
    if (img->draw.line[i][j] == '0')
    {
        img->color = 0x23272a;
        cub_draw(img);
    }
    else if (img->draw.line[i][j] == '1')
    {
        img->color = 0xffffff;
        cub_draw(img);
    }
    else if (img->draw.line[i][j] == 'N')
    {
        img->color = 0x23272a;
        cub_draw(img);
    }
    else
        img->color = 0x000000;
}

int    draw_move_player_2d(t_cub *img)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
	mlx_destroy_image(img->mlx, img->img);
	img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
            &img->line_lenght, &img->endian);
    while (img->draw.line[i] && img->draw.line[i][j])
    {
        while (img->draw.line[i] && img->draw.line[i][j])
        {
            initail_and_fill_player(img, i, j);
            j++;
        }
        j = 0;
        i++;
    }
	player_draw(img);
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
    return (1);
}

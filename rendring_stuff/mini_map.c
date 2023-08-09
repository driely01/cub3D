/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:26:48 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/09 15:53:46 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    initial_player_coordinate(t_cub *img)
{
    img->draw.py1 = img->draw.y1 + (UNIT / 4);
    img->draw.py2 = img->draw.y2  - (UNIT / 4);
    img->draw.px1 = img->draw.x1 + (UNIT / 4);
    img->draw.px2 = img->draw.x2  - (UNIT / 4);
}

void    initail_and_fill(t_cub *img, int i, int j)
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
        initial_player_coordinate(img);
        player_draw(img);
    }
    else
        img->color = 0x000000;
}

int    draw_mini_map(t_cub *img)
{
    int     i;
    int     j;

    i = 0;
    j = 0;
    if (!img->draw.line)
        return (0);
    while (img->draw.line[i] && img->draw.line[i][j])
    {
        while (img->draw.line[i] && img->draw.line[i][j])
        {
            initail_and_fill(img, i, j);
            j++;
        }
        j = 0;
        i++;
    }
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
    printf("%p\n", img->draw.line);
    return (1);
}
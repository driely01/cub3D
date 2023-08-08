/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:26:48 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 15:29:09 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    initail_and_fill(t_cub *img, char **line, int i, int j)
{
    img->draw.x1 = j * UNIT;
    img->draw.x2 = j * UNIT + UNIT;
    img->draw.y1 = i * UNIT;
    img->draw.y2 = i * UNIT + UNIT;
    img->color = 0xffffff;
    if (line[i][j] == '0')
    {
        img->color = 0x23272a;
        cub_draw(img);
    }
    else if (line[i][j] == '1')
    {
        img->color = 0xffffff;
        cub_draw(img);
    }
    else if (line[i][j] == 'N')
    {
        img->color = 0x23272a;
        cub_draw(img);
        img->draw.py1 = img->draw.y1;
        img->draw.py2 = img->draw.y2;
        img->draw.y1 = img->draw.py1 - UNIT;
        img->draw.y2 = img->draw.py1;
        img->color = 0x57f287;
        cub_draw(img);
    }
    else
        img->color = 0x000000;
}

int    draw_mini_map(t_cub *img)
{
    char **line;
    int     i;
    int     j;

    i = 0;
    j = 0;
    line = fill_map_array();
    if (!line)
        return (0);
    while (line[i] && line[i][j])
    {
        while (line[i] && line[i][j])
        {
            initail_and_fill(img, line, i, j);
            j++;
        }
        j = 0;
        i++;
    }
    mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
    return (1);
}

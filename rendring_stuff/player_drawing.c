/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:32:08 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/11 13:46:22 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    player_draw(t_cub *data)
{
    int i;
    int j;

    i = -data->draw.pr;
    j = -data->draw.pr;
    while (i <= data->draw.pr)
    {
        j = -data->draw.pr;
        while (j < data->draw.pr)
        {
            if (i * i + j * j <= data->draw.pr * data->draw.pr)
                my_put_pixel(data, data->draw.px + j, data->draw.py + i, 0x57f287);
            j++;
        }
        i++;
    }
    data->color = 0x57f287;
    check_before_draw(data, data->draw.px, data->draw.py, data->draw.px + data->draw.pdx * 5,
    data->draw.py + data->draw.pdy * 5);
}
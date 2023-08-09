/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:32:08 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 22:07:32 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    player_draw(t_cub *data)
{
    int i;
    int j;

    i = data->draw.px1;
    j = data->draw.py1;

    while (j <= data->draw.py2)
    {
        while (i <= data->draw.px2)
        {
            data->color = 0x57f287;
            my_put_pixel(data, i, j, data->color);
            i++;
        }
        i = data->draw.px1;
        j++;
    }
}
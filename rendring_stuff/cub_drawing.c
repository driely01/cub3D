/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:22:03 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 13:56:49 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    cub_draw(t_cub *data)
{
    int i;
    int j;

    i = data->draw.x1;
    j = data->draw.y1;

    while (j <= data->draw.y2)
    {
        while (i <= data->draw.x2)
        {
            if (i == data->draw.x1 || j == data->draw.y1 || i == data->draw.x2 || j == data->draw.y2)
            {
                data->border_color = 0xed4245;
                my_put_pixel(data, i, j, data->border_color);
            }
            else
                my_put_pixel(data, i, j, data->color);
            i++;
        }
        i = data->draw.x1;
        j++;
    }
}
// void    cub_draw(t_cub *data, int x1, int y1, int x2, int y2)
// {
//     int i;
//     int j;

//     i = x1;
//     j = y1;

//     while (j <= y2)
//     {
//         while (i <= x2)
//         {
//             if (i == x1 || j == y1 || i == x2 || j == y2)
//             {
//                 data->border_color = 0xed4245;
//                 my_put_pixel(data, i, j, data->border_color);
//             }
//             else
//                 my_put_pixel(data, i, j, data->color);
//             i++;
//         }
//         i = x1;
//         j++;
//     }
// }

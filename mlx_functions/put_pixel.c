/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:26:13 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/10 18:26:09 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void my_put_pixel(t_cub *data, int x, int y, int color)
{
    char    *dst;

    if (x < WIDTH && y < HEIGHT)
    {
        dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
        *(unsigned int*)dst = color;
    }
}

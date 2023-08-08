/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils_fn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:39:11 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 13:43:45 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int ft_abs(int number)
{
    if (number < 0)
        return (-number);
    return (number);
}

void    check_before_draw(t_cub *data, int x1, int y1, int x2, int y2)
{
    if (ft_abs(x2 - x1) > ft_abs(y2 - y1))
    {
        if (x1 > x2)
            bresenham_x_axis(data, x2, y2, x1, y1);
        else
            bresenham_x_axis(data, x1, y1, x2, y2);
    }
    else
    {
        if (y1 > y2)
            bresenham_y_axis(data, x2, y2, x1, y1);
        else
            bresenham_y_axis(data, x1, y1, x2, y2);
    }
}

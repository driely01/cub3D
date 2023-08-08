/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:40:01 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 13:43:39 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    check_dy(int *y, int dy, int dx, int *p)
{
    if (dy < 0)
    {
        if (*p > 0)
        {
            *p = *p - 2 * dx;
            (*y)--;
        }
        *p = *p - 2 * dy;
    }
    else
    {
        if (*p > 0)
        {
            *p = *p - 2 * dx;
            (*y)++;
        }
        *p = *p + 2 * dy;
    }
}

void    bresenham_x_axis(t_cub *data, int x1, int y1, int x2, int y2)
{
    int     x;
    int     y;
    int     dx;
    int     dy;
    int     p;

    
    x = x1;
    y = y1;
    
    dx = x2 - x1;
    dy = y2 - y1;

    if (dy < 0)
        p = 2 * (-dy) - dx;
    else
        p = 2 * dy - dx;
    
    while (x <= x2)
    {
        printf("point(%d, %d)\n", x, y);
        my_put_pixel(data, x, y, data->color);
        x++;
        check_dy(&y, dy, dx, &p);
    }
}

void    check_dx(int *x, int dx, int dy, int *p)
{
    if (dx < 0)
    {
        if (*p > 0)
        {
            *p = *p - 2 * dy;
            (*x)--;
        }
        *p = *p - 2 * dx;
    }
    else
    {
        if (*p > 0)
        {
            *p = *p - 2 * dy;
            (*x)++;
        }
        *p = *p + 2 * dx;
    }
}

void    bresenham_y_axis(t_cub *data, int x1, int y1, int x2, int y2)
{
    int     x;
    int     y;
    int     dx;
    int     dy;
    int     p;
    
    x = x1;
    y = y1;
    
    dx = x2 - x1;
    dy = y2 - y1;

    if (dx < 0)
        p = 2 * (-dx) - dy;
    else
        p = 2 * dx - dy;

    while (y <= y2)
    {
        printf("point(%d, %d)\n", x, y);
        my_put_pixel(data, x, y, data->color);
        y++;
        check_dx(&x, dx, dy, &p);
    }
}

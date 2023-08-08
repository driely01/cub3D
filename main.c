/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:55:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 15:26:10 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    init_win_put_img(t_cub *img, int choice)
{
    if (choice == 1)
    {
        img->mlx = mlx_init();
        img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Cub3D");
        img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
        img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_lenght, &img->endian);
    }
    else if (choice == 2)
        mlx_loop(img->mlx);
}

int main(void)
{
    t_cub   img;

    init_win_put_img(&img, 1);
    if (!draw_mini_map(&img))
        return (1);
    init_win_put_img(&img, 2);
    return (0);
}


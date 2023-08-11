/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:08:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/11 18:13:47 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int drawing_all_things(t_cub *img)
// {
//     img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
//     img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_lenght, &img->endian);
    
//     if (!draw_move_player_2d(img))
//     {
//         printf("there is no map\n");
//         return (0);
//     }
//     mlx_clear_window(img->mlx, img->mlx_win);
//     mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
//     mlx_destroy_image(img->mlx, img->img);
//     return (1);
// }

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
    {
        mlx_hook(img->mlx_win, 17, 0, destroy, img);
        mlx_hook(img->mlx_win, 2, 0, movement, img);
        // mlx_loop_hook(img->mlx, drawing_all_things, img);
        mlx_loop(img->mlx);
    }
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:08:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/18 22:10:20 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	destroy_init_img(t_cub *img, int choice)
{
	if (choice == 1)
	{
		mlx_destroy_image(img->mlx, img->img);
		img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
				&img->line_lenght, &img->endian);
		mlx_destroy_image(img->mlx, img->map.img);
		img->map.img = mlx_new_image(img->mlx, 300, 300);
		img->map.addr = mlx_get_data_addr(img->map.img,
				&img->map.bits_per_pixel,
				&img->map.line_lenght, &img->map.endian);
	}
	else if (choice == 2)
	{
		mlx_put_image_to_window(img->mlx, img->mlx_win, img->img, 0, 0);
		mlx_put_image_to_window(img->mlx, img->mlx_win,
			img->map.img, 0, 0);
	}
}

void	init_win_put_img(t_cub *img, int choice)
{
	if (choice == 1)
	{
		img->mlx = mlx_init();
		img->mlx_win = mlx_new_window(img->mlx, WIDTH, HEIGHT, "Cub3D");
		img->img = mlx_new_image(img->mlx, WIDTH, HEIGHT);
		img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
				&img->line_lenght, &img->endian);
		img->map.img = mlx_new_image(img->mlx, 300, 300);
		img->map.addr = mlx_get_data_addr(img->map.img,
				&img->map.bits_per_pixel,
				&img->map.line_lenght, &img->map.endian);
	}
	else if (choice == 2)
	{
		mlx_hook(img->mlx_win, 17, 0, destroy, img);
		mlx_hook(img->mlx_win, 2, 0, key_press, img);
		mlx_hook(img->mlx_win, 3, 0, key_release, img);
		mlx_loop_hook(img->mlx, drawing_all_things, img);
		mlx_loop(img->mlx);
	}
}

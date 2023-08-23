/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:08:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/23 22:01:51 by del-yaag         ###   ########.fr       */
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

void	init_textures(t_cub *img)
{
	img->text.up_img = mlx_xpm_file_to_image(img->mlx,
			"textures/bb/bb1.xpm",
			&img->text.up_width, &img->text.up_height);
	img->text.down_img = mlx_xpm_file_to_image(img->mlx,
			"textures/bb/bb2.xpm",
			&img->text.down_width, &img->text.down_height);
	img->text.right_img = mlx_xpm_file_to_image(img->mlx,
			"textures/bb/bb3.xpm",
			&img->text.right_width, &img->text.right_height);
	img->text.left_img = mlx_xpm_file_to_image(img->mlx,
			"textures/bb/bb4.xpm",
			&img->text.left_width, &img->text.left_height);
	img->text.up_add = mlx_get_data_addr(img->text.up_img,
			&img->text.up_bits_per_pixel, &img->text.up_line_lenght,
			&img->text.up_endian);
	img->text.down_add = mlx_get_data_addr(img->text.down_img,
			&img->text.down_bits_per_pixel, &img->text.down_line_lenght,
			&img->text.down_endian);
	img->text.right_add = mlx_get_data_addr(img->text.right_img,
			&img->text.right_bits_per_pixel, &img->text.right_line_lenght,
			&img->text.right_endian);
	img->text.left_add = mlx_get_data_addr(img->text.left_img,
			&img->text.left_bits_per_pixel, &img->text.left_line_lenght,
			&img->text.left_endian);
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
		init_textures(img);
	}
	else if (choice == 2)
	{
		mlx_hook(img->mlx_win, 17, 0, destroy, img);
		mlx_hook(img->mlx_win, 2, 0, key_press, img);
		mlx_hook(img->mlx_win, 3, 0, key_release, img);
		mlx_hook(img->mlx_win, 6, 0, mouse_move, img);
		mlx_loop_hook(img->mlx, drawing_all_things, img);
		mlx_loop(img->mlx);
	}
}

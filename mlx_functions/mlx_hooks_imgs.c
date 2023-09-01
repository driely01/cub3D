/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:08:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 14:46:25 by del-yaag         ###   ########.fr       */
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
		img->map.img = mlx_new_image(img->mlx, img->map.width, img->map.height);
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

void	init_add_textures(t_cub *img)
{
	img->text.so_add = mlx_get_data_addr(img->text.so_img,
			&img->text.so_bits_per_pixel, &img->text.so_line_lenght,
			&img->text.so_endian);
	img->text.no_add = mlx_get_data_addr(img->text.no_img,
			&img->text.no_bits_per_pixel, &img->text.no_line_lenght,
			&img->text.no_endian);
	img->text.ea_add = mlx_get_data_addr(img->text.ea_img,
			&img->text.ea_bits_per_pixel, &img->text.ea_line_lenght,
			&img->text.ea_endian);
	img->text.we_add = mlx_get_data_addr(img->text.we_img,
			&img->text.we_bits_per_pixel, &img->text.we_line_lenght,
			&img->text.we_endian);
	img->text.door_add = mlx_get_data_addr(img->text.door_img,
			&img->text.door_bits_per_pixel, &img->text.door_line_lenght,
			&img->text.door_endian);
}

void	init_textures(t_cub *img)
{
	img->text.so_img = mlx_xpm_file_to_image(img->mlx,
			img->text.so,
			&img->text.so_width, &img->text.so_height);
	img->text.no_img = mlx_xpm_file_to_image(img->mlx,
			img->text.no,
			&img->text.no_width, &img->text.no_height);
	img->text.ea_img = mlx_xpm_file_to_image(img->mlx,
			img->text.ea,
			&img->text.ea_width, &img->text.ea_height);
	img->text.we_img = mlx_xpm_file_to_image(img->mlx,
			img->text.we,
			&img->text.we_width, &img->text.we_height);
	img->text.door_img = mlx_xpm_file_to_image(img->mlx,
			"textures/door/door.xpm",
			&img->text.door_width, &img->text.door_height);
	protect_img_textures(img);
	init_add_textures(img);
}

void	destroy_texture(t_cub *data)
{
	mlx_destroy_image(data->mlx, data->text.so_img);
	mlx_destroy_image(data->mlx, data->text.no_img);
	mlx_destroy_image(data->mlx, data->text.we_img);
	mlx_destroy_image(data->mlx, data->text.ea_img);
	mlx_destroy_image(data->mlx, data->text.door_img);
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
		mlx_hook(img->mlx_win, 6, 0, mouse_move, img);
		mlx_loop_hook(img->mlx, drawing_all_things, img);
		mlx_loop(img->mlx);
	}
}

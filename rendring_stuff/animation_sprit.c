/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_sprit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:46:46 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 02:11:48 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	coordinate_animation_part_two(t_cub *data, int *ptr)
{
	if (*ptr == 12)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr7.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 14)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr8.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 16)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr9.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 18)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr10.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 20)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr11.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 22)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr12.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 24)
	{
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr13.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
		*ptr = 0;
	}
	protect_img_sprit_tr(data);
}

void	coordinate_animation(t_cub *data, int *ptr)
{
	if (*ptr == 0)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr1.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 2)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr2.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 4)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr3.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 6)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr4.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 8)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr5.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	if (*ptr == 10)
		data->fire.fire_img = mlx_xpm_file_to_image(data->mlx, "sprit/tr6.xpm",
				&data->fire.fire_width, &data->fire.fire_height);
	coordinate_animation_part_two(data, ptr);
	data->fire.fire_addr = mlx_get_data_addr(data->fire.fire_img,
			&data->fire.fire_bits_per_pixel, &data->fire.fire_line_lenght,
			&data->fire.fire_endian);
}

void	draw_fire_animation(t_cub *data, int r)
{
	double			wall_height;
	double			step;
	unsigned int	*color;
	int				i;
	double			next_step;

	wall_height = HEIGHT - (HEIGHT / 4);
	step = (data->fire.fire_height - 100) / wall_height;
	next_step = 0;
	if (r >= WIDTH / 4)
	{
		i = HEIGHT / 4;
		while (i < HEIGHT)
		{
			color = (unsigned int *)data->fire.fire_addr + (r - (WIDTH / 4))
				* data->fire.fire_width / (WIDTH - (WIDTH / 4))
				+ (int)next_step * data->fire.fire_width;
			if ((int)(*color) != -16777216)
				my_put_pixel(data, r, i, *color);
			next_step += step;
			i++;
		}
	}
}

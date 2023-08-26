/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_sprit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/25 15:46:46 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/25 19:20:41 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	coordinate_animation_part_two(t_cub *data, int *ptr)
{
	if (*ptr == 8)
		data->fire_img = mlx_xpm_file_to_image(data->mlx, "maps/f5.xpm",
				&data->fire_width, &data->fire_height);
	if (*ptr == 10)
		data->fire_img = mlx_xpm_file_to_image(data->mlx, "maps/f6.xpm",
				&data->fire_width, &data->fire_height);
	if (*ptr == 12)
		data->fire_img = mlx_xpm_file_to_image(data->mlx, "maps/f7.xpm",
				&data->fire_width, &data->fire_height);
	if (*ptr == 14)
		data->fire_img = mlx_xpm_file_to_image(data->mlx, "maps/f8.xpm",
				&data->fire_width, &data->fire_height);
	if (*ptr == 16)
	{
		data->fire_img = mlx_xpm_file_to_image(data->mlx, "maps/f9.xpm",
				&data->fire_width, &data->fire_height);
		*ptr = 0;
	}
}

void	coordinate_animation(t_cub *data, int *ptr)
{
	if (*ptr == 0)
		data->fire_img = mlx_xpm_file_to_image(data->mlx, "maps/f1.xpm",
				&data->fire_width, &data->fire_height);
	if (*ptr == 2)
		data->fire_img = mlx_xpm_file_to_image(data->mlx, "maps/f2.xpm",
				&data->fire_width, &data->fire_height);
	if (*ptr == 4)
		data->fire_img = mlx_xpm_file_to_image(data->mlx, "maps/f3.xpm",
				&data->fire_width, &data->fire_height);
	if (*ptr == 6)
		data->fire_img = mlx_xpm_file_to_image(data->mlx, "maps/f4.xpm",
				&data->fire_width, &data->fire_height);
	coordinate_animation_part_two(data, ptr);
	data->fire_addr = mlx_get_data_addr(data->fire_img,
			&data->fire_bits_per_pixel, &data->fire_line_lenght,
			&data->fire_endian);
}

void	draw_fire_animation(t_cub *data, int r)
{
	double			wall_height;
	double			step;
	unsigned int	*color;
	int				i;
	double			next_step;

	wall_height = HEIGHT - (HEIGHT / 4);
	step = (data->fire_height - 200) / wall_height;
	next_step = 0;
	if (r >= WIDTH / 4)
	{
		i = HEIGHT / 4;
		while (i < HEIGHT)
		{
			color = (unsigned int *)data->fire_addr + (r - (WIDTH / 4))
				* data->fire_width / (WIDTH - (WIDTH / 4))
				+ (int)next_step * data->fire_width;
			if ((int)(*color) != -16777216)
				my_put_pixel(data, r, i, *color);
			next_step += step;
			i++;
		}
	}
}

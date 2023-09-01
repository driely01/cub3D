/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_fire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:17:48 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 02:13:12 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	coordinate_animation_part_troch_two(t_cub *data, int *ptr)
{
	if (*ptr == 8)
		data->torch.torch_img = mlx_xpm_file_to_image(data->mlx, "sprit/f5.xpm",
				&data->torch.torch_width, &data->torch.torch_height);
	if (*ptr == 10)
		data->torch.torch_img = mlx_xpm_file_to_image(data->mlx, "sprit/f6.xpm",
				&data->torch.torch_width, &data->torch.torch_height);
	if (*ptr == 12)
		data->torch.torch_img = mlx_xpm_file_to_image(data->mlx, "sprit/f7.xpm",
				&data->torch.torch_width, &data->torch.torch_height);
	if (*ptr == 14)
		data->torch.torch_img = mlx_xpm_file_to_image(data->mlx, "sprit/f8.xpm",
				&data->torch.torch_width, &data->torch.torch_height);
	if (*ptr == 16)
	{
		data->torch.torch_img = mlx_xpm_file_to_image(data->mlx, "sprit/f9.xpm",
				&data->torch.torch_width, &data->torch.torch_height);
		*ptr = 0;
	}
	protect_img_sprit_f(data);
}

void	coordinate_animation_torch(t_cub *data, int *ptr)
{
	if (*ptr == 0)
		data->torch.torch_img = mlx_xpm_file_to_image(data->mlx, "sprit/f1.xpm",
				&data->torch.torch_width, &data->torch.torch_height);
	if (*ptr == 2)
		data->torch.torch_img = mlx_xpm_file_to_image(data->mlx, "sprit/f2.xpm",
				&data->torch.torch_width, &data->torch.torch_height);
	if (*ptr == 4)
		data->torch.torch_img = mlx_xpm_file_to_image(data->mlx, "sprit/f3.xpm",
				&data->torch.torch_width, &data->torch.torch_height);
	if (*ptr == 6)
		data->torch.torch_img = mlx_xpm_file_to_image(data->mlx, "sprit/f4.xpm",
				&data->torch.torch_width, &data->torch.torch_height);
	coordinate_animation_part_troch_two(data, ptr);
	data->torch.torch_addr = mlx_get_data_addr(data->torch.torch_img,
			&data->torch.torch_bits_per_pixel, &data->torch.torch_line_lenght,
			&data->torch.torch_endian);
}

void	destroy_torch_and_fire(t_cub *data, int ptr)
{
	if (ptr % 2 == 0)
	{
		mlx_destroy_image(data->mlx, data->torch.torch_img);
		mlx_destroy_image(data->mlx, data->fire.fire_img);
	}
}

void	draw_torch_animation(t_cub *data, int r)
{
	double			wall_height;
	double			step;
	unsigned int	*color;
	int				i;
	double			next_step;

	wall_height = HEIGHT - (HEIGHT / 4);
	step = (data->torch.torch_height - 100) / wall_height;
	next_step = 0;
	if (r >= WIDTH / 4)
	{
		i = HEIGHT / 4;
		while (i < HEIGHT)
		{
			color = (unsigned int *)data->torch.torch_addr + (r - (WIDTH / 4))
				* data->torch.torch_width / (WIDTH - (WIDTH / 4))
				+ (int)next_step * data->torch.torch_width;
			if ((int)(*color) != -16777216)
				my_put_pixel(data, r, i, *color);
			next_step += step;
			i++;
		}
	}
}

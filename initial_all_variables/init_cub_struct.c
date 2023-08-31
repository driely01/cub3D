/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub_struct.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 11:55:52 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/31 01:51:20 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initial_cub_struct(t_cub *data)
{
	data->img = NULL;
	data->addr = NULL;
	data->bits_per_pixel = 0;
	data->line_lenght = 0;
	data->endian = 0;
	data->color = 0;
	data->border_color = 0;
	data->mlx = NULL;
	data->mlx_win = NULL;
	data->sprit1 = 1;
	data->sprit2 = 0;
	data->player = 0;
	data->doors = NULL;
}

void	initial_fire_struct(t_cub *data)
{
	data->fire.fire_img = NULL;
	data->fire.fire_addr = NULL;
	data->fire.fire_width = 0;
	data->fire.fire_height = 0;
	data->fire.fire_bits_per_pixel = 0;
	data->fire.fire_line_lenght = 0;
	data->fire.fire_endian = 0;
}

void	initial_torch_struct(t_cub *data)
{
	data->torch.torch_img = NULL;
	data->torch.torch_addr = NULL;
	data->torch.torch_width = 0;
	data->torch.torch_height = 0;
	data->torch.torch_bits_per_pixel = 0;
	data->torch.torch_line_lenght = 0;
	data->torch.torch_endian = 0;
}

void	initial_map_struct(t_cub *data)
{
	data->map.addr = NULL;
	data->map.bits_per_pixel = 0;
	data->map.line_lenght = 0;
	data->map.endian = 0;
	data->map.img = 0;
	data->map.height = HEIGHT / 5;
	data->map.width = WIDTH / 6;
}

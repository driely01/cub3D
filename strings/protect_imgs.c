/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   protect_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 02:01:06 by amoukhle          #+#    #+#             */
/*   Updated: 2023/09/01 02:20:47 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	protect_img_textures(t_cub *img)
{
	if (!img->text.door_img || !img->text.we_img || !img->text.ea_img
		|| !img->text.no_img || !img->text.so_img)
	{
		write(2, "Error\n", 6);
		write (2, "Invalid texture wall/door\n", 26);
		free_double(img->draw.line);
		free_texture(img);
		free_doors(img->doors);
		exit(1);
	}
}

void	protect_img_sprit_f(t_cub *data)
{
	if (!data->torch.torch_img)
	{
		write(2, "Error\n", 6);
		write (2, "Invalid texture sprite fire\n", 28);
		free_double(data->draw.line);
		free_texture(data);
		free_doors(data->doors);
		exit(1);
	}
}

void	protect_img_sprit_tr(t_cub *data)
{
	if (!data->fire.fire_img)
	{
		write(2, "Error\n", 6);
		write (2, "Invalid texture sprite torch\n", 29);
		free_double(data->draw.line);
		free_texture(data);
		free_doors(data->doors);
		exit(1);
	}
}

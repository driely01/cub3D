/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:10:03 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/29 14:34:53 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initial_textures(t_cub *data)
{
	data->text.no_add = NULL;
	data->text.no_img = NULL;
	data->text.we_add = NULL;
	data->text.we_img = NULL;
	data->text.ea_add = NULL;
	data->text.ea_img = NULL;
	data->text.so_add = NULL;
	data->text.so_img = NULL;
	data->text.color = NULL;
	data->text.no = NULL;
	data->text.so = NULL;
	data->text.we = NULL;
	data->text.ea = NULL;
	data->text.f = NULL;
	data->text.c = NULL;
}

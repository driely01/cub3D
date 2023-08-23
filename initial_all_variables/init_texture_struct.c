/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 17:10:03 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/23 17:22:28 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initial_textures(t_cub *data)
{
	data->text.down_add = NULL;
	data->text.down_img = NULL;
	data->text.left_add = NULL;
	data->text.left_img = NULL;
	data->text.right_add = NULL;
	data->text.right_img = NULL;
	data->text.up_add = NULL;
	data->text.up_img = NULL;
	data->text.color = NULL;
}

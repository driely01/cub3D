/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initial_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:03:35 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/27 14:17:06 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	init_all_structrs(t_cub *data)
{
	initial_cub_struct(data);
	initial_cast_vars(data);
	initial_drawing_vars(data);
	initial_textures(data);
	initial_fire_struct(data);
	initial_torch_struct(data);
	initial_map_struct(data);
}

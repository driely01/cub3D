/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_after_rot_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:39:56 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/31 19:22:25 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	drawing_all_things(t_cub *img)
{
	static int	ptr;

	destroy_init_img(img, 1);
	coordinate_animation_torch(img, &ptr);
	coordinate_animation(img, &ptr);
	ptr++;
	init_textures(img);
	move_rotate_player(img);
	draw_casted_rays(img);
	draw_custom_map(img);
	destroy_texture(img);
	destroy_torch_and_fire(img, ptr);
	destroy_init_img(img, 2);
	return (1);
}

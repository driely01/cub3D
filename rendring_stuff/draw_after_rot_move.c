/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_after_rot_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:39:56 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/18 20:46:06 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	drawing_all_things(t_cub *img)
{
	destroy_init_img(img, 1);
	move_rotate_player(img);
	draw_casted_rays(img);
	draw_custom_map(img);
	destroy_init_img(img, 2);
	return (1);
}

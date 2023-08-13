/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_after_rot_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 15:39:56 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/12 18:56:17 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	drawing_all_things(t_cub *img)
{
	destroy_init_img(img, 1);
	move_rotate_player(img);
	draw_move_player_2d(img);
	destroy_init_img(img, 2);
	return (1);
}

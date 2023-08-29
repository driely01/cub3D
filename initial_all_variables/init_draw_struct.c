/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:51:27 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/29 14:33:20 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	init_drawing(t_cub *data)
{
	data->draw.posy = 0;
	data->draw.endx = 0;
	data->draw.endy = 0;
	data->draw.prevx = 0;
	data->draw.xdistance = 0;
	data->draw.rotangl = 0;
	data->draw.px1 = 0;
	data->draw.py1 = 0;
	data->draw.px = 0;
	data->draw.py = 0;
	data->draw.pr = 0;
	data->draw.pdx = 0;
	data->draw.pdy = 0;
	data->draw.pa = 0;
}

void	initial_drawing_vars(t_cub *data)
{
	data->draw.line = NULL;
	data->draw.x1 = 0;
	data->draw.x2 = 0;
	data->draw.y1 = 0;
	data->draw.y2 = 0;
	data->draw.forward = 0;
	data->draw.backward = 0;
	data->draw.moveleft = 0;
	data->draw.moveright = 0;
	data->draw.rotleft = 0;
	data->draw.rotright = 0;
	data->draw.height = 0;
	data->draw.posx = 0;
	init_drawing(data);
}

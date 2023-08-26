/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_events.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/19 11:53:07 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/23 16:42:48 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	mouse_move(int x, int y, t_cub *data)
{
	data->draw.rotangl = x - data->draw.prevx;
	data->draw.prevx = x;
	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		data->draw.xdistance = x - data->draw.px;
		data->draw.rotleft = 2;
	}
	return (1);
}

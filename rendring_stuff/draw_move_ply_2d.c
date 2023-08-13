/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_move_ply_2d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:51:49 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/12 18:57:03 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initail_and_fill_player(t_cub *img, int i, int j)
{
	img->draw.x1 = j * UNIT;
	img->draw.x2 = j * UNIT + UNIT;
	img->draw.y1 = i * UNIT;
	img->draw.y2 = i * UNIT + UNIT;
	if (img->draw.line[i][j] == '1')
	{
		img->color = 0xffffff;
		cub_draw(img);
	}
	else if (img->draw.line[i][j] == 'N' || img->draw.line[i][j] == 'S'
	|| img->draw.line[i][j] == 'W' || img->draw.line[i][j] == 'E'
	|| img->draw.line[i][j] == '0')
		border_cub_draw(img);
}

void	draw_move_player_2d(t_cub *img)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (img->draw.line[i] && img->draw.line[i][j])
	{
		while (img->draw.line[i] && img->draw.line[i][j])
		{
			initail_and_fill_player(img, i, j);
			j++;
		}
		j = 0;
		i++;
	}
	player_draw(img);
}

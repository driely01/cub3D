/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 15:26:48 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 01:37:47 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	initial_player_coordinate(t_cub *img)
{
	img->draw.pr = 6;
	img->draw.py = img->draw.y1 + (UNIT / 2);
	img->draw.px = img->draw.x1 + (UNIT / 2);
	img->draw.pdx = cos(img->draw.pa) * RAY;
	img->draw.pdy = sin(img->draw.pa) * RAY;
}

void	initail_and_fill(t_cub *img, int i, int j)
{
	img->draw.x1 = j * UNIT;
	img->draw.x2 = j * UNIT + UNIT;
	img->draw.y1 = i * UNIT;
	img->draw.y2 = i * UNIT + UNIT;
	if (img->draw.line[i][j] == 'N')
	{
		img->draw.pa = 3 * M_PI / 2;
		initial_player_coordinate(img);
	}
	else if (img->draw.line[i][j] == 'S')
	{
		img->draw.pa = M_PI / 2;
		initial_player_coordinate(img);
	}
	else if (img->draw.line[i][j] == 'E')
	{
		img->draw.pa = 0;
		initial_player_coordinate(img);
	}
	else if (img->draw.line[i][j] == 'W')
	{
		img->draw.pa = M_PI;
		initial_player_coordinate(img);
	}
}

void	draw_mini_map(t_cub *img)
{
	int	i;
	int	j;

	i = 0;
	while (img->draw.line[i])
	{
		j = 0;
		while (img->draw.line[i][j])
		{
			initail_and_fill(img, i, j);
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_drawing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 21:32:08 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/27 23:08:19 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	player_draw(t_cub *data)
{
	int	i;
	int	j;
	int	pxy[2];
	int	pxy1[2];

	i = -data->draw.pr;
	j = -data->draw.pr;
	pxy[0] = data->draw.px1;
	pxy[1] = data->draw.py1;
	pxy1[0] = pxy[0] + data->draw.pdx / 2;
	pxy1[1] = pxy[1] + data->draw.pdy / 2;
	while (i <= data->draw.pr)
	{
		j = -data->draw.pr;
		while (j < data->draw.pr)
		{
			if (i * i + j * j <= data->draw.pr * data->draw.pr)
				put_map_pixel(data, data->draw.px1 + j, data->draw.py1 + i,
					0x822129);
			j++;
		}
		i++;
	}
	data->color = 0x822129;
	check_before_draw(data, pxy, pxy1);
}

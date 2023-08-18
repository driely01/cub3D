/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_drawing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 10:22:03 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/17 16:01:30 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	cub_draw(t_cub *data)
{
	int	i;
	int	j;

	i = data->draw.x1;
	j = data->draw.y1;
	while (j <= data->draw.y2)
	{
		while (i <= data->draw.x2)
		{
			if (i == data->draw.x1 || j == data->draw.y1 || i == data->draw.x2
				|| j == data->draw.y2)
			{
				data->border_color = 0x292b2c;
				my_put_pixel(data, i, j, data->border_color);
			}
			else
				my_put_pixel(data, i, j, data->color);
			i++;
		}
		i = data->draw.x1;
		j++;
	}
}

void	border_cub_draw(t_cub *data)
{
	int	i;
	int	j;

	i = data->draw.x1;
	j = data->draw.y1;
	while (j <= data->draw.y2)
	{
		while (i <= data->draw.x2)
		{
			if (i == data->draw.x1 || j == data->draw.y1 || i == data->draw.x2
				|| j == data->draw.y2)
			{
				data->border_color = 0x0275d8;
				my_put_pixel(data, i, j, data->border_color);
			}
			i++;
		}
		i = data->draw.x1;
		j++;
	}
}

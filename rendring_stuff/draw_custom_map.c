/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_custom_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:51:49 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/18 22:04:34 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_x_y(t_cub *data)
{
	if (data->draw.py < 150)
		data->draw.py1 = data->draw.py;
	else
		data->draw.py1 = 150;
	if (data->draw.px < 150)
		data->draw.px1 = data->draw.px;
	else 
		data->draw.px1 = 150;
	data->draw.posx = data->draw.px - 150;
	data->draw.posy = data->draw.py - 150;
	data->draw.endx = data->draw.px + 150;
	data->draw.endy = data->draw.py + 150;
	if (data->draw.posx < 0)
		data->draw.posx = 0;
	if (data->draw.posy < 0)
		data->draw.posy = 0;
	if (data->draw.endx < 300)
		data->draw.endx = 300;
	if (data->draw.endy < 300)
		data->draw.endy = 300;
}

void	check_and_draw_map(t_cub *img, int x, int y)
{
	if ((int)(img->draw.posy / UNIT) < img->draw.height
		&& ((int)(img->draw.posx / UNIT))
		< ft_strlen(img->draw.line[(int)(img->draw.posy / UNIT)])
		&& img->draw.line[(int)(img->draw.posy / UNIT)] \
		[(int)(img->draw.posx / UNIT)] == '1')
		put_map_pixel(img, x, y, 0x639d9f);
	else
		put_map_pixel(img, x, y, 0x046473);
	img->draw.posx++;
}

void	draw_custom_map(t_cub *img)
{
	int	x;
	int	y;
	int	posx;

	x = 0;
	y = 0;
	get_x_y(img);
	posx = img->draw.posx;
	while (img->draw.posy < img->draw.endy)
	{
		while (img->draw.posx < img->draw.endx)
		{
			check_and_draw_map(img, x, y);
			x++;
		}
		x = 0;
		y++;
		img->draw.posx = posx;
		img->draw.posy++;
	}
	player_draw(img);
}

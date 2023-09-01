/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_custom_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 09:51:49 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 14:47:05 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_x_y(t_cub *data)
{
	if (data->draw.py / COEFF < data->map.height / 2)
		data->draw.py1 = data->draw.py / COEFF;
	else
		data->draw.py1 = data->map.height / 2;
	if (data->draw.px / COEFF < data->map.width / 2)
		data->draw.px1 = data->draw.px / COEFF;
	else 
		data->draw.px1 = data->map.width / 2;
	data->draw.posx = data->draw.px / COEFF - data->map.width / 2;
	data->draw.posy = data->draw.py / COEFF - data->map.height / 2;
	data->draw.endx = data->draw.px / COEFF + data->map.width / 2;
	data->draw.endy = data->draw.py / COEFF + data->map.height / 2;
	if (data->draw.posx < 0)
		data->draw.posx = 0;
	if (data->draw.posy < 0)
		data->draw.posy = 0;
	if (data->draw.endx < data->map.width)
		data->draw.endx = data->map.width;
	if (data->draw.endy < data->map.height)
		data->draw.endy = data->map.height;
}

void	check_and_draw_map(t_cub *img, int x, int y)
{
	if ((int)(img->draw.posy / (UNIT / COEFF)) < img->draw.height
		&& ((int)(img->draw.posx / (UNIT / COEFF)))
		< ft_strlen(img->draw.line[(int)(img->draw.posy / (UNIT / COEFF))])
		&& img->draw.line[(int)(img->draw.posy / (UNIT / COEFF))] \
		[(int)(img->draw.posx / (UNIT / COEFF))] == '1')
		put_map_pixel(img, x, y, 0xc65a1d);
	else if ((int)(img->draw.posy / (UNIT / COEFF)) < img->draw.height
		&& ((int)(img->draw.posx / (UNIT / COEFF)))
		< ft_strlen(img->draw.line[(int)(img->draw.posy / (UNIT / COEFF))])
		&& img->draw.line[(int)(img->draw.posy / (UNIT / COEFF))] \
		[(int)(img->draw.posx / (UNIT / COEFF))] == 'D')
		put_map_pixel(img, x, y, 0x6e8434);
	else
		put_map_pixel(img, x, y, 0xc89f40);
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

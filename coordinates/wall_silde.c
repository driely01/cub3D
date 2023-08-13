/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_silde.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/13 13:54:01 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/13 13:55:29 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	right_slide_wall(t_cub *data, double prevpx, double prevpy)
{
	if (data->draw.line[(int)floor(data->draw.py / UNIT)] \
		[(int)floor(prevpx / UNIT)] != '1')
	{
		if (data->draw.forward || data->draw.backward)
			data->draw.px -= sin(M_PI - data->draw.pa);
		else
			data->draw.px -= sin(M_PI - data->draw.pa) * RAY;
	}
	else if (data->draw.line[(int)floor(prevpy / UNIT)] \
		[(int)floor(data->draw.px / UNIT)] != '1')
	{
		if (data->draw.forward || data->draw.backward)
			data->draw.py -= cos(M_PI - data->draw.pa);
		else
			data->draw.py -= cos(M_PI - data->draw.pa) * RAY;
	}
}

void	left_slide_wall(t_cub *data, double nextpx, double nextpy)
{
	if (data->draw.line[(int)floor(data->draw.py / UNIT)] \
		[(int)floor(nextpx / UNIT)] == '0')
	{
		if (data->draw.forward || data->draw.backward)
			data->draw.px += sin(M_PI - data->draw.pa);
		else
			data->draw.px += sin(M_PI - data->draw.pa) * RAY;
	}
	else if (data->draw.line[(int)floor(nextpy / UNIT)] \
		[(int)floor(data->draw.px / UNIT)] == '0')
	{
		if (data->draw.forward || data->draw.backward)
			data->draw.py += cos(M_PI - data->draw.pa);
		else
			data->draw.py += cos(M_PI - data->draw.pa) * RAY;
	}
}

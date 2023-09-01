/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:10:14 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 01:32:09 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy(t_cub *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
	free_doors(data->doors);
	free_double(data->draw.line);
	free_texture(data);
	exit(0);
	return (0);
}

void	animation_event(t_cub *data)
{
	if (data->sprit2 == 1)
	{
		data->sprit2 = 0;
		data->sprit1 = 1;
	}
	else if (data->sprit1 == 1)
	{
		data->sprit1 = 0;
		data->sprit2 = 1;
	}
}

void	open_close_door(t_cub *data)
{
	if (data->draw.line[(int)(data->draw.py / UNIT) + 1] \
		[(int)(data->draw.px / UNIT)] == 'D')
		get_door(data, (int)(data->draw.px / UNIT),
			(int)(data->draw.py / UNIT) + 1);
	if (data->draw.line[(int)(data->draw.py / UNIT) - 1] \
		[(int)(data->draw.px / UNIT)] == 'D')
		get_door(data, (int)(data->draw.px / UNIT),
			(int)(data->draw.py / UNIT) - 1);
	if (data->draw.line[(int)(data->draw.py / UNIT)] \
		[(int)(data->draw.px / UNIT) + 1] == 'D')
		get_door(data, (int)(data->draw.px / UNIT) + 1,
			(int)(data->draw.py / UNIT));
	if (data->draw.line[(int)(data->draw.py / UNIT)] \
		[(int)(data->draw.px / UNIT) - 1] == 'D')
		get_door(data, (int)(data->draw.px / UNIT) - 1,
			(int)(data->draw.py / UNIT));
}

int	key_press(int keycode, t_cub *data)
{
	if (keycode == ESC)
		destroy(data);
	else if (keycode == KEY_W)
		data->draw.forward = 1;
	else if (keycode == KEY_S)
		data->draw.backward = 1;
	else if (keycode == KEY_A)
		data->draw.moveleft = 1;
	else if (keycode == KEY_D)
		data->draw.moveright = 1;
	else if (keycode == LEFT)
		data->draw.rotleft = 1;
	else if (keycode == RIGHT)
		data->draw.rotright = 1;
	else if (keycode == TAB)
		animation_event(data);
	else if (keycode == SPACE)
		open_close_door(data);
	else
		return (0);
	return (1);
}

int	key_release(int keycode, t_cub *data)
{
	if (keycode == KEY_W)
		data->draw.forward = 0;
	else if (keycode == KEY_S)
		data->draw.backward = 0;
	else if (keycode == KEY_A)
		data->draw.moveleft = 0;
	else if (keycode == KEY_D)
		data->draw.moveright = 0;
	else if (keycode == LEFT)
		data->draw.rotleft = 0;
	else if (keycode == RIGHT)
		data->draw.rotright = 0;
	else
		return (0);
	return (1);
}

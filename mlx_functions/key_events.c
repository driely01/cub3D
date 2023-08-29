/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:10:14 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/27 13:51:05 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	destroy(t_cub *data)
{
	mlx_destroy_window(data->mlx, data->mlx_win);
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

int	key_press(int keycode, t_cub *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx, data->mlx_win);
		exit(0);
	}
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

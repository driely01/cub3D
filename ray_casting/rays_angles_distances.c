/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_angles_distances.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 15:53:37 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/16 16:07:58 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	increment_ray_angle(t_cub *data, int is_increment)
{
	if (!is_increment)
	{
		data->cast.ray_ang = data->draw.pa - ONE * 30;
		if (data->cast.ray_ang < 0)
			data->cast.ray_ang += 2 * M_PI;
		if (data->cast.ray_ang > 2 * M_PI)
			data->cast.ray_ang -= 2 * M_PI;
	}
	else
	{
		data->cast.ray_ang += data->cast.angl_inc;
		if (data->cast.ray_ang < 0)
			data->cast.ray_ang += 2 * M_PI;
		if (data->cast.ray_ang > 2 * M_PI)
			data->cast.ray_ang -= 2 * M_PI;
	}
}

void	allocate_distance_array(t_cub *data)
{
	if (!data->cast.distances)
	{
		data->cast.distances = malloc(sizeof(double) * WIDTH);
		if (!data->cast.distances)
			return ;
	}
	else
	{
		free(data->cast.distances);
		data->cast.distances = malloc(sizeof(double) * WIDTH);
		if (!data->cast.distances)
			return ;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham_utils_fn.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:39:11 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/13 11:22:42 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_abs(int number)
{
	if (number < 0)
		return (-number);
	return (number);
}

void	check_before_draw(t_cub *data, int *pxy, int *pxy1)
{
	if (ft_abs(pxy1[0] - pxy[0]) > ft_abs(pxy1[1] - pxy[1]))
	{
		if (pxy[0] > pxy1[0])
			bresenham_x_axis(data, pxy1, pxy);
		else
			bresenham_x_axis(data, pxy, pxy1);
	}
	else
	{
		if (pxy[1] > pxy1[1])
			bresenham_y_axis(data, pxy1, pxy);
		else
			bresenham_y_axis(data, pxy, pxy1);
	}
}

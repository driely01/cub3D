/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:55:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/15 16:53:21 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	initial_vars(t_cub *data)
{
	data->draw.forward = 0;
	data->draw.backward = 0;
	data->draw.moveleft = 0;
	data->draw.moveright = 0;
	data->draw.rotleft = 0;
	data->draw.rotright = 0;
}

void	initial_cast_vars(t_cub *data, char *str)
{
	data->cast.hx = 0;
	data->cast.hy = 0;
	data->cast.hx_offs = 0;
	data->cast.hy_offs = 0;
	data->cast.vx = 0;
	data->cast.vy = 0;
	data->cast.vx_offs = 0;
	data->cast.vy_offs = 0;
	data->cast.lenght = count_lines_map(str);
	data->cast.distances = NULL;
}

int	main(int argc, char **argv)
{
	t_cub	img;

	if (argc == 2)
	{
		if (!check_file_name(argv[1]))
			return (printf("invalid file\n"), 1);
		fill_map_array(&img, argv[1]);
		img.cordt.width = find_tall_line(&img) * UNIT;
		img.cordt.height = count_lines_map(argv[1]) * UNIT;
		initial_cast_vars(&img, argv[1]);
		initial_vars(&img);
		init_win_put_img(&img, 1);
		if (!draw_mini_map(&img))
		{
			printf("there is no map\n");
			return (1);
		}
		init_win_put_img(&img, 2);
	}
	else
		printf("no file entered\n");
	return (0);
}

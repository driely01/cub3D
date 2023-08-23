/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:55:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/23 17:56:19 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub	img;

	if (argc == 2)
	{
		initial_drawing_vars(&img);
		initial_cast_vars(&img);
		initial_textures(&img);
		if (!check_file_name(argv[1]))
			return (printf("invalid file\n"), 1);
		fill_map_array(&img, argv[1]);
		img.cordt.width = find_tall_line(&img) * UNIT;
		img.cordt.height = count_lines_map(argv[1]) * UNIT;
		img.draw.height = count_lines_map(argv[1]);
		img.cast.lenght = count_lines_map(argv[1]);
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

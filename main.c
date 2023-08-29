/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:55:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/29 16:13:42 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parsing(char **argv, t_cub *img)
{
	if (!check_file_name(argv[1]))
	{
		write(2, "Error\n", 6);
		write(2, "invalid file\n", 13);
		exit (1);
	}
	if (!check_texture(argv[1], img))
	{
		write(2, "Error\n", 6);
		write(2, "invalid path of texture\n", 24);
		exit(1);
	}
	check_map(argv[1], img);
}

int	main(int argc, char **argv)
{
	t_cub	img;

	if (argc == 2)
	{
		init_all_structrs(&img);
		parsing(argv, &img);
		img.cordt.width = find_tall_line(&img) * UNIT;
		img.cordt.height = count_lines_map(argv[1]) * UNIT;
		img.draw.height = count_lines_map(argv[1]);
		img.cast.lenght = count_lines_map(argv[1]);
		init_win_put_img(&img, 1);
		draw_mini_map(&img);
		init_win_put_img(&img, 2);
	}
	else
		printf("no file entered\n");
	return (0);
}

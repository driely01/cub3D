/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:55:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 01:26:17 by amoukhle         ###   ########.fr       */
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

void	get_door(t_cub *data, int x, int y)
{
	t_door	*p;

	p = data->doors;
	while (p)
	{
		if (p->i == y && p->j == x)
			break ;
		p = p->next;
	}
	if (p->status == 0)
		p->status = 1;
	else
		p->status = 0;
}

void	all_doors(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->draw.line[i])
	{
		j = 0;
		while (data->draw.line[i][j])
		{
			if (data->draw.line[i][j] == 'D')
				add_door(&data->doors, new_door(i, j));
			j++;
		}
		i++;
	}
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
		all_doors(&img);
		init_win_put_img(&img, 1);
		draw_mini_map(&img);
		init_win_put_img(&img, 2);
	}
	else
	{
		write(2, "Error\n", 6);
		write(2, "no file entered\n", 16);
		exit(1);
	}
	return (0);
}

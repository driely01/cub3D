/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:55:59 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/31 02:23:11 by amoukhle         ###   ########.fr       */
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

t_door	*new_door(int i, int j)
{
	t_door *new;

	new = (t_door *)malloc(sizeof(t_door));
	if (!new)
		print_error_malloc();
	new->i = i;
	new->j = j;
	new->status = 0;
	new->next = NULL;
	return (new);
}

void	add_door(t_door **s_door, t_door *s_new)
{
	t_door	*p;

	if (!*s_door)
	{
		*s_door = s_new;
		return ;
	}
	p = *s_door;
	while (p->next)
		p = p->next;
	p->next = s_new;
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

void	print_struct(t_cub *data)
{
	t_door *p;

	p = data->doors;
	while (p)
	{
		printf("x: %d y: %d\n",p->j, p->i);
		p = p->next;
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
		// print_struct
		// print_struct(&img);
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

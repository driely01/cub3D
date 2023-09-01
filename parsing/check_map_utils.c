/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:18:11 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/31 00:56:10 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_map_is_empty(t_cub *data, int *i)
{
	while (data->draw.line[*i])
	{
		if (!check_line(data->draw.line[*i], data))
			(*i)++;
		else
			return ;
	}
	free_double(data->draw.line);
	free_texture(data);
	write(2, "Error\n", 6);
	write(2, "the map is not set\n", 19);
	exit(1);
}

int	check_end_of_map(t_cub *data, int *i)
{
	int	flag;

	flag = 0;
	while (data->draw.line[*i])
	{
		if (!check_line(data->draw.line[*i], data))
		{
			(*i)++;
			flag = 1;
		}
		else
		{
			if (flag == 1)
				return (0);
			else
				return (1);
		}
	}
	return (1);
}

void	check_all_caracters(t_cub *data)
{
	if (data->player == 0 || data->player > 1)
	{
		free_double(data->draw.line);
		write(2, "Error\n", 6);
		write(2, "you're missing a caracter or more players\n", 42);
		exit(1);
	}
}

int	check_border_map(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	check_map_is_empty(data, &i);
	while (data->draw.line[i])
	{
		if (!check_end_of_map(data, &i))
			return (0);
		if (!data->draw.line[i])
			break ;
		j = 0;
		while (data->draw.line[i][j])
		{
			if (!check_caracter_is_valid(data->draw.line[i][j], data))
				print_error_caracter(data);
			if (!check_border(data->draw.line[i][j], i, j, data))
				print_error_border(data);
			j++;
		}
		i++;
	}
	check_all_caracters(data);
	return (1);
}

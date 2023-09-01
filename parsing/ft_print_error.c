/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:36:40 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/31 00:55:32 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	print_error_fd(void)
{
	write(2, "Error\n", 6);
	write(2, "failed open fd\n", 15);
	exit(1);
}

void	print_error_malloc(void)
{
	write(2, "Error\n", 6);
	write(2, "failed malloc\n", 15);
	exit(1);
}

void	print_error_caracter(t_cub *data)
{
	free_double(data->draw.line);
	free_texture(data);
	write(2, "Error\n", 6);
	write(2, "there are character not valid\n", 30);
	exit(1);
}

void	print_error_border(t_cub *data)
{
	free_double(data->draw.line);
	free_texture(data);
	write(2, "Error\n", 6);
	write(2, "The map must be closed/surrounded by walls\n", 43);
	exit(1);
}

void	print_error_map_empty(void)
{
	write(2, "Error\n", 6);
	write(2, "The map is empty\n", 17);
	exit(1);
}

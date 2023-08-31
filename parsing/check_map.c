/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 01:12:42 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/31 00:55:47 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_map(int fd)
{
	int		count;
	char	*line;

	count = 0;
	while (count < 6)
	{
		line = get_next_line(fd);
		if (!check_line_is_empty(line))
			count++;
		free(line);
	}
	return (1);
}

int	check_caracter_is_valid(char c, t_cub *data)
{
	if (c != '1' && c != '0' && c != 'N' && c != ' '
		&& c != 'S' && c != 'E' && c != 'W' && c != 'D')
		return (0);
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		data->player += 1;
	return (1);
}

int	check_border(char c, int i, int j, t_cub *data)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == 'D')
	{
		if (j == 0 || i == 0 || !data->draw.line[i + 1])
			return (0);
		if (j != 0)
			if (data->draw.line[i][j - 1] == ' ')
				return (0);
		if (data->draw.line[i][j + 1] == ' '
			|| data->draw.line[i][j + 1] == '\0'
			|| data->draw.line[i][j + 1] == '\n')
			return (0);
		if (i != 0)
			if (data->draw.line[i - 1][j] == ' '
				|| ft_strlen(data->draw.line[i - 1]) - 1 < j)
				return (0);
		if (data->draw.line[i + 1])
			if (data->draw.line[i + 1][j] == ' '
				|| ft_strlen(data->draw.line[i + 1]) - 1 < j)
				return (0);
	}
	return (1);
}

int	check_line(char *line, t_cub *data)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ')
			return (1);
		i++;
	}
	if (i != 0)
	{
		free_double(data->draw.line);
		write(2, "Error\n", 6);
		write(2, "the map is not valid\n", 21);
		exit(1);
	}
	return (0);
}

void	check_map(char	*str, t_cub *data)
{
	fill_map_array(data, str);
	if (!check_border_map(data))
	{
		free_double(data->draw.line);
		free_texture(data);
		write(2, "Error\n", 6);
		write(2, "the map is not valid\n", 21);
		exit(1);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 01:12:42 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/28 03:44:36 by amoukhle         ###   ########.fr       */
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
		if (!line)
		{
			close(fd);
			return (0);
		}
		if (!check_line_is_empty(line))
			count++;
		free(line);
	}
	return (1);
}

int	check_caracter_is_valid(char c)
{
	if (c != '1' && c != '0' && c != 'N' && c != ' '
		&& c != 'S' && c != 'E' && c != 'W')
		return (0);
	return (1);
}

int	check_border(char c, int i, int j, t_cub *data)
{
	if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
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

void	check_border_map(t_cub *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->draw.line[i])
	{
		j = 0;
		while (data->draw.line[i][j])
		{
			if (!check_caracter_is_valid(data->draw.line[i][j]))
				print_error_caracter(data);
			if (!check_border(data->draw.line[i][j], i, j, data))
				print_error_border(data);
			j++;
		}
		i++;
	}
}

void	check_map(char	*str, t_cub *data)
{
	int		fd;

	fd = open(str, O_RDONLY, 0777);
	if (fd == -1)
		print_error_fd();
	if (!find_map(fd))
	{
		write(2, "Error\n", 6);
		write(2, "the map not set\n", 16);
		exit(1);
	}
	fill_map_array(data, str);
	check_border_map(data);
}

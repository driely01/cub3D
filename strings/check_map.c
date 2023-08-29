/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 01:12:42 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/28 20:56:20 by amoukhle         ###   ########.fr       */
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
		&& c != 'S' && c != 'E' && c != 'W')
		return (0);
	if (c == '0')
		data->floor = 1;
	else if (c == '1')
		data->wall = 1;
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		data->player = 1;
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
	if (data->floor == 0 || data->wall == 0 || data->player == 0)
	{
		free_double(data->draw.line);
		write(2, "Error\n", 6);
		write(2, "you're missing a caracter\n", 26);
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
			break;
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

void	check_map(char	*str, t_cub *data)
{
	fill_map_array(data, str);
	if (!check_border_map(data))
	{
		free_double(data->draw.line);
		write(2, "Error\n", 6);
		write(2, "the map is not valid\n", 21);
		exit(1);
	}
}

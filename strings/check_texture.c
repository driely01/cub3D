/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 04:39:26 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/28 01:10:56 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_texture(char	*str, t_cub *data)
{
	int		fd;

	fd = open(str, O_RDONLY, 0777);
	if (fd == -1)
		print_error_fd();
	if (!get_paths(fd, data))
		return (0);
	close(fd);
	if (!check_path_of_text(data))
		return (0);
	if (!check_color_is_valid(data))
	{
		write(2, "Error\n", 6);
		write(2, "invalid color\n", 15);
		exit(1);
	}
	return (1);
}

int	check_path_of_text(t_cub *data)
{
	if (!data->no || access(data->no, F_OK) == -1)
		return (0);
	if (!data->so || access(data->so, F_OK) == -1)
		return (0);
	if (!data->we || access(data->we, F_OK) == -1)
		return (0);
	if (!data->ea || access(data->ea, F_OK) == -1)
		return (0);
	return (1);
}

int	check_type(char	*line, t_cub *data, int fd)
{
	char	**tmp;

	tmp = ft_split_two_part(line);
	if (!check_type_identifier(tmp, data))
	{
		free(line);
		free_double(tmp);
		free_texture(data);
		close(fd);
		return (0);
	}
	free_double(tmp);
	return (1);
}

int	get_paths(int fd, t_cub *data)
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
		{
			if (!check_type(line, data, fd))
				return (0);
			count++;
		}
		free(line);
	}
	return (1);
}
int	check_type_identifier(char **str, t_cub *data)
{
	if (ft_strcmp(str[0], "NO"))
	{
		data->no = ft_strdup(str[1]);
		return (1);
	}
	else if (ft_strcmp(str[0], "SO"))
	{
		data->so = ft_strdup(str[1]);
		return (1);
	}
	else if (ft_strcmp(str[0], "WE"))
	{
		data->we = ft_strdup(str[1]);
		return (1);
	}
	else if (ft_strcmp(str[0], "EA"))
	{
		data->ea = ft_strdup(str[1]);
		return (1);
	}
	else if (check_type_identifier_next(str, data))
		return (1);
	return (0);
}
int	check_type_identifier_next(char **str, t_cub *data)
{
	if (ft_strcmp(str[0], "F"))
	{
		data->f = get_color(str);
		return (1);
	}
	else if (ft_strcmp(str[0], "C"))
	{
		data->c = get_color(str);
		return (1);
	}
	return (0);
}

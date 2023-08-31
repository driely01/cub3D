/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_textures_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:20:13 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/29 16:20:58 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
		data->text.no = ft_strdup(str[1]);
		return (1);
	}
	else if (ft_strcmp(str[0], "SO"))
	{
		data->text.so = ft_strdup(str[1]);
		return (1);
	}
	else if (ft_strcmp(str[0], "WE"))
	{
		data->text.we = ft_strdup(str[1]);
		return (1);
	}
	else if (ft_strcmp(str[0], "EA"))
	{
		data->text.ea = ft_strdup(str[1]);
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
		data->text.f = get_color(str);
		return (1);
	}
	else if (ft_strcmp(str[0], "C"))
	{
		data->text.c = get_color(str);
		return (1);
	}
	return (0);
}

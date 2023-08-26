/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exc_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:07:26 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/26 03:33:31 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_if_dote_cub(char *str, int start, int end)
{
	char	*cmp;
	int		i;

	i = 0;
	cmp = malloc(sizeof(char) * (end - start) + 2);
	if (!cmp)
		return (0);
	while (start <= end)
	{
		cmp[i++] = str[start++];
	}
	cmp[i] = 0;
	if (!ft_strncmp(cmp, "cub", 3) && ft_strlen(cmp) == ft_strlen("cub"))
		return (free(cmp), 1);
	else
		return (free(cmp), 0);
}

int	check_file_name(char *str)
{
	int	i;
	int	start;
	int	end;

	i = 0;
	while (str[i])
		i++;
	i--;
	end = i;
	while (i >= 0)
	{
		i--;
		if (str[i] == '.')
		{
			start = ++i;
			if (!check_if_dote_cub(str, start, end))
				return (0);
			else
				return (1);
		}
	}
	if (i == -1)
		return (0);
	return (1);
}

int	check_line_is_empty(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != ' ' && line[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*get_color(char **str)
{
	int		i;
	char	*part;

	i = 0;
	while (str[i])
		i++;
	if (i > 2)
	{
		i = 1;
		part = NULL;
		while (str[i])
		{
			part = ft_strjoin(part, str[i]);
			i++;
		}
		return (part);
	}
	return (ft_strdup(str[1]));
}

char	*get_path(char **str)
{
	int	i;
	
	i = 0;
	while (str[i])
		i++;
	if (i > 2)
		return (NULL);
	return (ft_strdup(str[1]));
}

int	check_direction(char **str, t_cub *data)
{
	
	if (ft_strcmp(str[0], "NO"))
	{
		data->no = get_path(str);
		return (1);
	}
	else if (ft_strcmp(str[0], "SO"))
	{
		data->so = get_path(str);
		return (1);
	}
	else if (ft_strcmp(str[0], "WE"))
	{
		data->we = get_path(str);
		return (1);
	}
	else if (ft_strcmp(str[0], "EA"))
	{
		data->ea = get_path(str);
		return (1);
	}
	else if (ft_strcmp(str[0], "F"))
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

void	print_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		printf("%s\n", str[i]);
		i++;
	}
}

int	get_paths(int fd, t_cub *data)
{
	int		count;
	char	*line;
	char	**tmp;

	count = 0;
	while (count < 6)
	{
		line = get_next_line(fd);
		if (!check_line_is_empty(line))
		{
			tmp = ft_split(line, ' ');
			if(!check_direction(tmp, data))
			{
				free(line);
				free_double(tmp);
				free_texture(data);
				close(fd);
				return (0);
			}
			free_double(tmp);
			count++;
		}
		free(line);
	}
	return (1);
}

int	check_path_of_text(t_cub *data)
{
	if (!data->no || access(data->no, F_OK) == -1)
		return (0);
	if (!data->so ||access(data->so, F_OK) == -1)
		return (0);
	if (!data->we || access(data->we, F_OK) == -1)
		return (0);
	if (!data->ea || access(data->ea, F_OK) == -1)
		return (0);
	return (1);
}

int	check_color_is_valid(t_cub *data)
{
	int		color;
	char	**str;
	int		i;

	if (!data->f || !data->c)
		return (0);
	str = ft_split(data->f, ',');
	i = 0;
	while (str[i])
		i++;
	if (i == 3)
	{
		i = 0;
		while (str[i])
		{
			color = ft_atoi(str[i]);
			if (color < 0 || color > 255)
			{
				free_double(str);
				return (0);
			}
			i++;
		}
	}
	else
	{
		free_double(str);
		return (0);
	}
	// same thing for c
	return (1);
}

int	check_texture(char	*str, t_cub *data)
{
	int		fd;

	fd = open(str, O_RDONLY, 0777);
	if (fd == -1)
		print_error_fd();
	if(!get_paths(fd, data))
		return(0);
	close(fd);
	if (!check_path_of_text(data) || !check_color_is_valid(data))
		return (0);
	return (1);
}

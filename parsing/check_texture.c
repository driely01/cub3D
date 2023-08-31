/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 04:39:26 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/29 16:20:49 by del-yaag         ###   ########.fr       */
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
	if (!data->text.no || access(data->text.no, F_OK) == -1)
		return (0);
	if (!data->text.so || access(data->text.so, F_OK) == -1)
		return (0);
	if (!data->text.we || access(data->text.we, F_OK) == -1)
		return (0);
	if (!data->text.ea || access(data->text.ea, F_OK) == -1)
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

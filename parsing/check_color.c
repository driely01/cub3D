/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 04:44:24 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/29 16:16:52 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*get_color(char **str)
{
	int		i;
	char	**colors;
	char	*tmp;
	char	*color;
	int		flag;

	flag = 0;
	if (str[1][ft_strlen(str[1]) - 1] == ',' || str[1][0] == ',')
		flag = 1;
	colors = ft_split(str[1], ',');
	i = 0;
	color = NULL;
	while (colors[i])
	{
		tmp = delete_spaces_first_last(colors[i]);
		if (color)
			color = ft_strjoin(color, ",");
		color = ft_strjoin(color, tmp);
		free(tmp);
		i++;
	}
	if (flag == 1)
		color = ft_strjoin(color, ",");
	free_double(colors);
	return (color);
}

int	check_color(char **str)
{
	int	i;
	int	color;

	i = 0;
	while (str[i])
	{
		color = ft_atoi(str[i++]);
		if (color < 0 || color > 255)
		{
			free_double(str);
			return (0);
		}
	}
	if (i != 3)
	{
		free_double(str);
		return (0);
	}
	free_double(str);
	return (1);
}

char	*ft_strjoin_one_char(char c, char *str)
{
	int		len;
	char	*new_str;
	int		i;

	len = 0;
	if (str)
		len += ft_strlen(str);
	new_str = (char *)malloc(len + 2);
	if (!new_str)
		print_error_malloc();
	i = 0;
	while (str && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = c;
	i++;
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

int	check_color_is_valid(t_cub *data)
{
	char	**str;

	if (!data->text.f || !data->text.c
		|| data->text.f[ft_strlen(data->text.f) - 1] == ','
		|| data->text.c[ft_strlen(data->text.c) - 1] == ',')
		return (0);
	str = ft_split(data->text.f, ',');
	if (!check_color(str))
		return (0);
	str = ft_split(data->text.c, ',');
	if (!check_color(str))
		return (0);
	get_color_in_decimal(data);
	return (1);
}

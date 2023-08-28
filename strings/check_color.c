/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_color.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/27 04:44:24 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/28 01:10:59 by amoukhle         ###   ########.fr       */
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

char	*ft_puthex(int num)
{
	char	*str;
	char	*hex;
	char	c;

	hex = NULL;
	str = "0123456789abcdef";
	if (num >= 16)
		hex = ft_puthex(num / 16);
	c = str[num % 16];
	hex = ft_strjoin_one_char(c, hex);
	return (hex);
}

int	hex_to_decimal(char *str)
{
	int number;
	int i;
	int ex;

	i = -1;
	ex = 6;
	number = 0;
	while (str[++i])
	{
		if (str[i] == 'F' || str[i] == 'f')
			number += (int)(15 * pow(16, (double)--ex));
		else if (str[i] == 'E' || str[i] == 'e')
			number += (int)(14 * pow(16, (double)--ex));
		else if (str[i] == 'D' || str[i] == 'd')
			number += (int)(13 * pow(16, (double)--ex));
		else if (str[i] == 'C' || str[i] == 'c')
			number += (int)(12 * pow(16, (double)--ex));
		else if (str[i] == 'B' || str[i] == 'b')
			number += (int)(11 * pow(16, (double)--ex));
		else if (str[i] == 'A' || str[i] == 'a')
			number += (int)(10 * pow(16, (double)--ex));
		else
			number += (int)((str[i] - 48) * pow(16, (double)--ex));
	}
	return (number);
}

char	*get_color_hex(char *color)
{
	char	**str;
	int		color_int;
	int		i;
	char	*color_hex;
	char	*tmp;

	str = ft_split(color, ',');
	i = 0;
	color_hex = NULL;
	while (str[i])
	{
		color_int = atoi(str[i]);
		tmp = ft_puthex(color_int);
		color_hex = ft_strjoin(color_hex, tmp);
		free(tmp);
		i++;
	}
	free_double(str);
	return (color_hex);
}

void	get_color_in_decimal(t_cub *data)
{
	char	*tmp;
	
	tmp = get_color_hex(data->f);
	data->f_color = hex_to_decimal(tmp);
	free(tmp);
	tmp = get_color_hex(data->c);
	data->c_color = hex_to_decimal(tmp);
	free(tmp);
}

int	check_color_is_valid(t_cub *data)
{
	char	**str;

	if (!data->f || !data->c || data->f[ft_strlen(data->f) - 1] == ','
		|| data->c[ft_strlen(data->c) - 1] == ',')
		return (0);
	str = ft_split(data->f, ',');
	if (!check_color(str))
		return (0);
	str = ft_split(data->c, ',');
	if (!check_color(str))
		return (0);
	get_color_in_decimal(data);
	return (1);
}

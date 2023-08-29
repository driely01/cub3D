/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base_conversion.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:14:57 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/29 16:16:58 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	int	number;
	int	i;
	int	ex;

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

	tmp = get_color_hex(data->text.f);
	data->text.f_color = hex_to_decimal(tmp);
	free(tmp);
	tmp = get_color_hex(data->text.c);
	data->text.c_color = hex_to_decimal(tmp);
	free(tmp);
}

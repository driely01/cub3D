/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exc_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:07:26 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/13 11:36:16 by del-yaag         ###   ########.fr       */
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

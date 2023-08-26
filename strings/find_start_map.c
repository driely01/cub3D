/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_start_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:55:12 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/24 15:23:17 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	find_map_start(char *line)
{
	int	i;

	i = 0;
	while (line[i] == '\n')
		return (0);
	while (line[i])
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == ' ' || line[i] == 'N'
			|| line[i] == 'S' || line[i] == 'W' || line[i] == 'E'
			|| line[i] == '\n')
			i++;
		else
			return (0);
	}
	return (1);
}

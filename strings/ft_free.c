/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:30:46 by amoukhle          #+#    #+#             */
/*   Updated: 2023/09/02 16:13:11 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	free_texture(t_cub *data)
{
	if (data->text.no)
		free(data->text.no);
	if (data->text.so)
		free(data->text.so);
	if (data->text.we)
		free(data->text.we);
	if (data->text.ea)
		free(data->text.ea);
	if (data->text.f)
		free(data->text.f);
	if (data->text.c)
		free(data->text.c);
}

void	free_double(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	free_doors(t_door *doors)
{
	t_door	*p;

	while (doors && doors->next)
	{
		p = doors->next;
		free(doors);
		doors = p;
	}
	free(doors);
}

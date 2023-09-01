/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_addback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:24:26 by amoukhle          #+#    #+#             */
/*   Updated: 2023/09/01 01:27:18 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	add_door(t_door **s_door, t_door *s_new)
{
	t_door	*p;

	if (!*s_door)
	{
		*s_door = s_new;
		return ;
	}
	p = *s_door;
	while (p->next)
		p = p->next;
	p->next = s_new;
}

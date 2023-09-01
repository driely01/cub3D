/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 01:23:55 by amoukhle          #+#    #+#             */
/*   Updated: 2023/09/01 01:24:47 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_door	*new_door(int i, int j)
{
	t_door	*new;

	new = (t_door *)malloc(sizeof(t_door));
	if (!new)
		print_error_malloc();
	new->i = i;
	new->j = j;
	new->status = 0;
	new->next = NULL;
	return (new);
}

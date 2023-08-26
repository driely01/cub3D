/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 13:56:33 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/13 11:32:28 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup(char *str)
{
	int		i;
	char	*new_str;
	int		lenght;

	if (!str)
		return (NULL);
	i = 0;
	lenght = ft_strlen(str);
	new_str = malloc(sizeof(char) * lenght + 1);
	if (!new_str)
		return (NULL);
	while (str[i] != '\n' && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = 0;
	return (new_str);
}

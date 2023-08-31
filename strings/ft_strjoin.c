/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 01:56:19 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/29 16:08:51 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		extra_len;
	char	*str;
	int		i;
	int		j;

	extra_len = 0;
	if (s1)
		extra_len += ft_strlen(s1);
	if (s2)
		extra_len += ft_strlen(s2);
	str = (char *)malloc(extra_len + 1);
	if (!str)
		print_error_malloc();
	i = 0;
	while (s1 && s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j] && s2[j] != '\n')
		str[i++] = s2[j++];
	str[i] = '\0';
	free(s1);
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 00:46:02 by amoukhle          #+#    #+#             */
/*   Updated: 2023/08/26 01:32:03 by amoukhle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	num_w(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (!str[i])
			break ;
		while (str[i] != c && str[i])
			i++;
		count++;
	}
	return (count);
}

static char	*fill_str(char **st, char *s, int start, int end)
{
	int		i;
	char	*str;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(end - start + 1);
	if (!str)
	{
		while (*st)
			free((*st)++);
		free(st);
		return (NULL);
	}
	while (start < end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	str = (char **)malloc((num_w((char *)s, c) + 1) * sizeof(char *));
	if (!str || !s)
		return (NULL);
	while (i < num_w((char *)s, c) + 1)
	{
		while (s[start] == c && s[start])
			start++;
		if (!s[start])
			break ;
		end = start;
		while (s[end] != c && s[end])
			end++;
		str[i++] = fill_str(str, (char *)s, start, end);
		start = end;
	}
	str[i] = NULL;
	return (str);
}
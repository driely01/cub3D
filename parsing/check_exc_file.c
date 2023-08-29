/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exc_file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 20:07:26 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/29 16:10:38 by del-yaag         ###   ########.fr       */
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

char	*delete_spaces_first_last(char *str)
{
	int		start;
	int		end;
	int		i;
	char	*new_str;
	int		len;

	start = 0;
	while (str[start] && str[start] == ' ')
		start++;
	end = ft_strlen(str);
	while (end > 0 && str[end - 1] == ' ')
		end--;
	len = end - start;
	if (len < 0)
		len = 1;
	new_str = (char *)malloc(len + 1);
	if (!new_str)
		print_error_malloc();
	i = 0;
	if (start > end)
		new_str [i++] = ' ';
	while (start < end)
		new_str[i++] = str[start++];
	new_str[i] = '\0';
	return (new_str);
}

char	*get_first_part(char *line, int *start, int *end)
{
	char	*str;
	int		i;
	int		len;

	*start = 0;
	while (line[*start] && line[*start] == ' ')
		(*start)++;
	*end = *start;
	while (line[*end] && line[*end] != ' ' && line[*end] != '\n')
		(*end)++;
	len = *end - *start;
	str = (char *)malloc(len + 1);
	if (!str)
		print_error_malloc();
	i = 0;
	while (*start < *end)
		str[i++] = line[(*start)++];
	str[i] = '\0';
	return (str);
}

char	*get_second_part(char *line, int *start, int *end)
{
	char	*str;
	int		len;
	int		i;

	while (line[*start] && line[*start] == ' ')
		(*start)++;
	*end = *start;
	while (line[*end] && line[*end] != '\n')
		(*end)++;
	len = *end - *start;
	str = (char *)malloc(len + 1);
	if (!str)
		print_error_malloc();
	i = 0;
	while (*start < *end)
		str[i++] = line[(*start)++];
	str[i] = '\0';
	return (str);
}

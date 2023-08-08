/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:25:00 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/07 16:28:17 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int     check_valid_line(char *line)
{
    int i;

    i = 0;
    while (line[i])
    {
        if (line[i] != '1' && line[i] != 32 && line[i] != '0'
            && line[i] != '\n' && line[i] != 'N')
            break;
        else
            i++;
    }
    if (line[i] == 0 && i > 0)
        return (1);
    else
        return (0);
}

int    count_lines_map(void)
{
    char    *line;
    int     fd;
    int     i;
    
    i = 0;
    fd = open("map", O_RDONLY, 0777);
    if (fd == -1)
        return (i);
    line = get_next_line(fd);
    while (line)
    {
        if (check_valid_line(line))
            i++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return (i);
}

char    **fill_map_array(void)
{
    size_t  i;
    size_t  map_lenght;
    char    *line;
    char    **map;
    int     fd;

    i = 0;
    map = NULL;
    map_lenght = count_lines_map();
    if (map_lenght > 0)
        map = malloc(sizeof(char *) * (map_lenght + 1));
    if (!map)
        return (NULL);
    fd = open("map", O_RDONLY, 0777);
    if (fd == -1)
        return (NULL);
    line = get_next_line(fd);
    while (line)
    {
        map[i++] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
    }
    map[i] = NULL;
    free(line);
    return (map);
}

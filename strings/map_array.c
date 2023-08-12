/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:25:00 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/12 13:53:56 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void    fill_the_array_map(t_cub *img, int fd)
{
    size_t  i;
    char    *line;

    i = 0;
    line = get_next_line(fd);
    while (line)
    {
        if (find_map_start(line))
            img->draw.line[i++] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
    }
    img->draw.line[i] = NULL;
    free(line);
}

int    fill_map_array(t_cub *img, char *file_name)
{
    size_t  map_lenght;
    int     fd;

    map_lenght = count_lines_map(file_name);
    if (map_lenght > 0)
        img->draw.line = malloc(sizeof(char *) * (map_lenght + 1));
    if (!img->draw.line)
        return (0);
    fd = open(file_name, O_RDONLY, 0777);
    if (fd == -1)
        return (0);
    fill_the_array_map(img, fd);
    close(fd);
    return (1);
}

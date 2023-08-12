/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_tall_line_count_lines.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 13:53:23 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/12 13:55:08 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int find_tall_line(t_cub *img)
{
    int count;
    size_t linelen;
    int i;

    count = -1;
    i = 0;
    while (img->draw.line[i])
    {
        linelen = ft_strlen(img->draw.line[i]);
        if (count < (int)linelen)
            count = (int)linelen;
        i++;
    }
    return (count);
}

int    count_lines_map(char *file_name)
{
    char    *line;
    int     fd;
    int     i;
    
    i = 0;
    fd = open(file_name, O_RDONLY, 0777);
    if (fd == -1)
        return (i);
    line = get_next_line(fd);
    while (line)
    {
        if (find_map_start(line))
            i++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return (i);
}

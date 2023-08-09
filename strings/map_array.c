/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 16:25:00 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/09 19:17:29 by del-yaag         ###   ########.fr       */
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
        if (check_valid_line(line))
            i++;
        free(line);
        line = get_next_line(fd);
    }
    free(line);
    close(fd);
    return (i);
}

int    fill_map_array(t_cub *img, char *file_name)
{
    size_t  i;
    size_t  map_lenght;
    char    *line;
    int     fd;

    i = 0;
    map_lenght = count_lines_map(file_name);
    if (map_lenght > 0)
        img->draw.line = malloc(sizeof(char *) * (map_lenght + 1));
    if (!img->draw.line)
        return (0);
    fd = open(file_name, O_RDONLY, 0777);
    if (fd == -1)
        return (0);
    line = get_next_line(fd);
    while (line)
    {
        img->draw.line[i++] = ft_strdup(line);
        free(line);
        line = get_next_line(fd);
    }
    img->draw.line[i] = NULL;
    free(line);
    close(fd);
    return (1);
}

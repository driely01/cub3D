/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:13:29 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/08 15:31:13 by del-yaag         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <unistd.h>
# include <mlx.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 1
# endif

// Macros
# define HEIGHT 1024
# define WIDTH 1920
# define UNIT 44

// get next line struct
typedef struct collecion
{
	int		r;
	size_t	i;
	char	*bf;
	char	*ln;
}	t_collecion;

// drawing struct
typedef struct s_drawing
{
    int x1;
    int x2;
    int y1;
    int y2;
    int px1;
    int py1;
    int px2;
    int py2;
}   t_drawing;

// mlx struct
typedef struct s_cub
{
    void                *img;
    char                *addr;
    int                 bits_per_pixel;
    int                 line_lenght;
    int                 endian;
    int                 color;
    int                 border_color;
    void                *mlx;
    void                *mlx_win;
    struct s_drawing    draw;
}   t_cub;


// drawing line algorithm
void    bresenham_y_axis(t_cub *data, int x1, int y1, int x2, int y2);
void    bresenham_x_axis(t_cub *data, int x1, int y1, int x2, int y2);
void    check_dy(int *y, int dy, int dx, int *p);
void    check_dx(int *x, int dx, int dy, int *p);
int     ft_abs(int number);
void    check_before_draw(t_cub *data, int x1, int y1, int x2, int y2);

// put pixel
void    my_put_pixel(t_cub *data, int x, int y, int color);

// cub drawing
// void    cub_draw(t_cub *data, int x1, int y1, int x2, int y2);
void    cub_draw(t_cub *data);

// get next line functions
size_t	ft_strlen(const char *str);
void	*ft_calloc(size_t number, size_t size);
char	*cpy(char *s, char *p);
char	*ft_append(char *s1, char *s2);
char	*ft_read(char **leftover, char *line, size_t i);
char	*get_next_line(int fd);
char	*cpy_two(char *s1, char *s2, char *p);
int		stc(t_collecion *vb);

// strings
char    *ft_strdup(char *str);

// map array
char    **fill_map_array(void);
int    count_lines_map(void);
int     check_valid_line(char *line);

// drawing mini map
void    initail_and_fill(t_cub *img, char **line, int i, int j);
int     draw_mini_map(t_cub *img);

#endif
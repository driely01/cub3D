/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:13:29 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/16 16:06:55 by del-yaag         ###   ########.fr       */
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
# include <limits.h>

# define BUFFER_SIZE 1

// Macros
# define HEIGHT 500
# define WIDTH 1200
# define UNIT 32

// keys
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define UP 126
# define DOWN 125
# define LEFT 123
# define RIGHT 124
# define ESC 53

// rotation angle
# define ANGLE 0.059
# define RAY 1.5
# define ONE 0.0174533

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
	char	**line;
	int		x1;
	int		x2;
	int		y1;
	int		y2;
	int		forward;
	int		backward;
	int		moveleft;
	int		moveright;
	int		rotleft;
	int		rotright;
	double	py;
	double	px;
	double	pr;
	double	pdx;
	double	pdy;
	double	pa;
}	t_drawing;

// coordinates
typedef struct s_cordt
{
	int	width;
	int	height;
}	t_dordt;

// ray-casting
typedef struct s_cast
{
	int		lenght;
	double	hx;
	double	hy;
	double	hx_offs;
	double	hy_offs;
	double	vx;
	double	vy;
	double	vx_offs;
	double	vy_offs;
	double	*distances;
	double	ray_ang;
	double	angl_inc;
}	t_cast;

// mlx struct
typedef struct s_cub
{
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_lenght;
	int					endian;
	int					color;
	int					border_color;
	void				*mlx;
	void				*mlx_win;
	struct s_drawing	draw;
	struct s_cordt		cordt;
	struct s_cast		cast;
}	t_cub;

// drawing line algorithm
void	bresenham_y_axis(t_cub *data, int *pxy, int *pxy1);
void	bresenham_x_axis(t_cub *data, int *pxy, int *pxy1);
void	check_dy(int *y, int dy, int dx, int *p);
void	check_dx(int *x, int dx, int dy, int *p);
int		ft_abs(int number);
void	check_before_draw(t_cub *data, int *pxy, int *pxy1);

// put pixel
void	my_put_pixel(t_cub *data, int x, int y, int color);

// mlx initialize images, hooks and windows
void	init_win_put_img(t_cub *img, int choice);
void	destroy_init_img(t_cub *img, int choice);

// mlx key events
int		destroy(t_cub *data);
int		key_press(int keycode, t_cub *data);
int		key_release(int keycode, t_cub *data);

// cub && player drawing
void	cub_draw(t_cub *data);
void	border_cub_draw(t_cub *data);
void	player_draw(t_cub *data);

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
char	*ft_strdup(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);

// map array
int		fill_map_array(t_cub *img, char *file_name);
int		count_lines_map(char *file_name);
int		find_tall_line(t_cub *img);
int		find_map_start(char *line);

// drawing mini map
void	initail_and_fill(t_cub *img, int i, int j);
int		draw_mini_map(t_cub *img);

// drawing player movement 2D
int		drawing_all_things(t_cub *img);
void	draw_move_player_2d(t_cub *img);
void	initail_and_fill_player(t_cub *img, int i, int j);

// check extantion file
int		check_if_dote_cub(char *str, int start, int end);
int		check_file_name(char *str);

// player movement and rotations
void	lateral_move(t_cub *data);
void	straight_move(t_cub *data);
void	move_backward(t_cub *data);
void	move_rotate_player(t_cub *data);
void	move_right_end_check(t_cub *data);
void	move_left_and_check(t_cub *data);
void	right_slide_wall(t_cub *data, double prevpx, double prevpy);
void	left_slide_wall(t_cub *data, double nextpx, double nextpy);

// ray casting
double	hor_ray_casting(t_cub *data);
double	ver_ray_casting(t_cub *data);
int		check_is_ver_wall(t_cub *data);
void	increment_ray_angle(t_cub *data, int is_increment);
void	allocate_distance_array(t_cub *data);
double	distance(t_cub *data, double x2, double y2);
void	vertical_ray_equation(t_cub *data);
void	horizontal_ray_equation(t_cub *data);
void	draw_casted_rays(t_cub *data);
void	ray_coordinate(t_cub *data, int *i, int is_hor);

#endif
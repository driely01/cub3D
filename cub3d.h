/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoukhle <amoukhle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:13:29 by del-yaag          #+#    #+#             */
/*   Updated: 2023/08/28 03:12:59 by amoukhle         ###   ########.fr       */
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
# define HEIGHT 1080
# define WIDTH 1600
# define UNIT 640

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
# define RAY 44
# define COEFF 20
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
	int		height;
	int		posx;
	int		posy;
	int		endx;
	int		endy;
	int		prevx;
	double	xdistance;
	double	rotangl;
	double	px1;
	double	py1;
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
	int				lenght;
	int				color;
	int				flag;
	int				offset;
	double			hx;
	double			hy;
	double			hx_offs;
	double			hy_offs;
	double			vx;
	double			vy;
	double			vx_offs;
	double			vy_offs;
	double			*distances;
	double			ray_ang;
	double			angl_inc;
	double			wall_height;
	double			step;
}	t_cast;

// mini map
typedef struct s_map
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}	t_map;

// textures
typedef struct s_text
{
	void			*left_img;
	char			*left_add;
	int				left_width;
	int				left_height;
	int				left_bits_per_pixel;
	int				left_line_lenght;
	int				left_endian;
	void			*right_img;
	char			*right_add;
	int				right_width;
	int				right_height;
	int				right_bits_per_pixel;
	int				right_line_lenght;
	int				right_endian;
	void			*up_img;
	char			*up_add;
	int				up_width;
	int				up_height;
	int				up_bits_per_pixel;
	int				up_line_lenght;
	int				up_endian;
	void			*down_img;
	char			*down_add;
	int				down_width;
	int				down_height;
	int				down_bits_per_pixel;
	int				down_line_lenght;
	int				down_endian;
	unsigned int	*color;
}	t_text;

// mlx struct
typedef struct s_cub
{
	char				*no;
	char				*so;
	char				*we;
	char				*ea;
	char				*f;
	char				*c;
	int					f_color;
	int					c_color;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_lenght;
	int					endian;
	int					color;
	int					border_color;
	void				*mlx;
	void				*mlx_win;
	void				*fire_img;
	char				*fire_addr;
	int					fire_width;
	int					fire_height;
	int					fire_bits_per_pixel;
	int					fire_line_lenght;
	int					fire_endian;
	struct s_drawing	draw;
	struct s_cordt		cordt;
	struct s_cast		cast;
	struct s_map		map;
	struct s_text		text;
}	t_cub;

// initial variables
void	initial_drawing_vars(t_cub *data);
void	initial_cast_vars(t_cub *data);
void	initial_textures(t_cub *data);

// drawing line algorithm
int		ft_abs(int number);
void	bresenham_y_axis(t_cub *data, int *pxy, int *pxy1);
void	bresenham_x_axis(t_cub *data, int *pxy, int *pxy1);
void	check_dy(int *y, int dy, int dx, int *p);
void	check_dx(int *x, int dx, int dy, int *p);
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

// mlx mouse events
int		mouse_move(int x, int y, t_cub *data);

// cub && player drawing
void	cub_draw(t_cub *data);
void	border_cub_draw(t_cub *data);
void	player_draw(t_cub *data);

// get next line functions
int		stc(t_collecion *vb);
void	*ft_calloc(size_t number, size_t size);
char	*cpy(char *s, char *p);
char	*ft_append(char *s1, char *s2);
char	*ft_read(char **leftover, char *line, size_t i);
char	*get_next_line(int fd);
char	*cpy_two(char *s1, char *s2, char *p);
int		ft_strlen(const char *str);

// strings
char	*ft_strdup(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);
int		ft_atoi(const char *str);
char	*get_color(char **str);
int		check_color(char **str);
int		check_color_is_valid(t_cub *data);
char	**ft_split_two_part(char *line);
int		check_line_is_empty(char *line);
int		check_if_dote_cub(char *str, int start, int end);
int		check_file_name(char *str);
char	*delete_spaces_first_last(char *str);
char	*get_second_part(char *line, int *start, int *end);
char	*get_first_part(char *line, int *start, int *end);
int		check_texture(char	*str, t_cub *data);
int		check_path_of_text(t_cub *data);
int		get_paths(int fd, t_cub *data);
int		check_type_identifier(char **str, t_cub *data);
int		check_type_identifier_next(char **str, t_cub *data);
void	check_map(char	*str, t_cub *data);
// char	**ft_strjoin_double(char **str1, char **str2);

// map array
int		fill_map_array(t_cub *img, char *file_name);
int		count_lines_map(char *file_name);
int		find_tall_line(t_cub *img);
int		find_map_start(char *line);

// drawing mini map
void	initail_and_fill(t_cub *img, int i, int j);
int		draw_mini_map(t_cub *img);
void	initial_player_coordinate(t_cub *img);
void	initail_and_fill(t_cub *img, int i, int j);

// drawing player movement 2D
int		drawing_all_things(t_cub *img);

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
int		check_is_ver_wall(t_cub *data);
int		check_is_hor_wall(t_cub *data);
void	increment_ray_angle(t_cub *data, int is_increment);
void	allocate_distance_array(t_cub *data);
void	vertical_ray_equation(t_cub *data);
void	horizontal_ray_equation(t_cub *data);
void	draw_casted_rays(t_cub *data);
void	ray_coordinate(t_cub *data, int *i, int r, int is_hor);
double	distance(t_cub *data, double x2, double y2);
double	hor_ray_casting(t_cub *data);
double	ver_ray_casting(t_cub *data);

// walls 3D, floor and ceil
void	draw_ceil_floor(t_cub *data, int i);

// mini map
void	put_map_pixel(t_cub *data, int x, int y, int color);
void	draw_custom_map(t_cub *img);

// draw textures
void	up_textures(t_cub *data, int i);
void	down_textures(t_cub *data, int i);
void	right_textures(t_cub *data, int i);
void	left_textures(t_cub *data, int i);
void	calculate_wall_height_offset(t_cub *data, int height, int i);

// animation
void	coordinate_animation(t_cub *data, int *ptr);
void	draw_fire_animation(t_cub *data, int r);

//parsing
int		check_texture(char	*str, t_cub *data);
int		check_line_is_empty(char *line);

// free
void	free_texture(t_cub *data);
void	free_double(char **str);

// error_msg
void	print_error_fd(void);
void	print_error_malloc(void);
void	print_error_caracter(t_cub *data);
void	print_error_border(t_cub *data);
void	print_error_map_empty(void);

#endif
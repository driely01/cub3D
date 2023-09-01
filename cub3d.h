/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: del-yaag <del-yaag@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 16:13:29 by del-yaag          #+#    #+#             */
/*   Updated: 2023/09/01 18:32:44 by del-yaag         ###   ########.fr       */
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
# define MINI_HEIGHT 300
# define MINI_WIDTH 300

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
# define TAB 48
# define SPACE 49
# define RET 51

// rotation angle
# define ANGLE 0.059
# define RAY 60
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
	double	d_vx;
	double	d_vy;
	double	d_v_dist;
	double	d_hx;
	double	d_hy;
	double	d_h_dist;
	double	d_dist;
	double	d_height;
	int		d_flag;
	int		lenght;
	int		color;
	int		flag;
	int		offset;
	double	hx;
	double	hy;
	double	hx_offs;
	double	hy_offs;
	double	vx;
	double	vy;
	double	vx_offs;
	double	vy_offs;
	double	ray_ang;
	double	angl_inc;
	double	wall_height;
	double	step;
	double	dist;
}	t_cast;

// mini map
typedef struct s_map
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		height;
	int		width;
	int		endian;
}	t_map;

// textures
typedef struct s_text
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	int				f_color;
	int				c_color;
	void			*we_img;
	char			*we_add;
	int				we_width;
	int				we_height;
	int				we_bits_per_pixel;
	int				we_line_lenght;
	int				we_endian;
	void			*ea_img;
	char			*ea_add;
	int				ea_width;
	int				ea_height;
	int				ea_bits_per_pixel;
	int				ea_line_lenght;
	int				ea_endian;
	void			*so_img;
	char			*so_add;
	int				so_width;
	int				so_height;
	int				so_bits_per_pixel;
	int				so_line_lenght;
	int				so_endian;
	void			*no_img;
	char			*no_add;
	int				no_width;
	int				no_height;
	int				no_bits_per_pixel;
	int				no_line_lenght;
	int				no_endian;
	void			*door_img;
	char			*door_add;
	int				door_width;
	int				door_height;
	int				door_bits_per_pixel;
	int				door_line_lenght;
	int				door_endian;
	unsigned int	*color;

}	t_text;

// doors struct
typedef struct s_door
{
	int				i;
	int				j;
	int				status;
	struct s_door	*next;

}	t_door;

// fire struct
typedef struct s_fire
{
	void				*fire_img;
	char				*fire_addr;
	int					fire_width;
	int					fire_height;
	int					fire_bits_per_pixel;
	int					fire_line_lenght;
	int					fire_endian;
}	t_fire;

// torch struct
typedef struct s_torch
{
	void				*torch_img;
	char				*torch_addr;
	int					torch_width;
	int					torch_height;
	int					torch_bits_per_pixel;
	int					torch_line_lenght;
	int					torch_endian;
}	t_torch;

// mlx struct
typedef struct s_cub
{
	int					player;
	void				*img;
	char				*addr;
	int					bits_per_pixel;
	int					line_lenght;
	int					endian;
	int					color;
	int					border_color;
	void				*mlx;
	void				*mlx_win;
	int					sprit1;
	int					sprit2;
	struct s_drawing	draw;
	struct s_cordt		cordt;
	struct s_cast		cast;
	struct s_map		map;
	struct s_text		text;
	struct s_fire		fire;
	struct s_torch		torch;
	struct s_door		*doors;
}	t_cub;

// initial variables
void	init_all_structrs(t_cub *data);
void	initial_drawing_vars(t_cub *data);
void	initial_cast_vars(t_cub *data);
void	initial_textures(t_cub *data);
void	initial_cub_struct(t_cub *data);
void	initial_fire_struct(t_cub *data);
void	initial_torch_struct(t_cub *data);
void	initial_map_struct(t_cub *data);

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

// mlx destroy images
void	destroy_texture(t_cub *data);
void	init_textures(t_cub *img);
void	destroy_torch_and_fire(t_cub *data, int ptr);

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
char	**ft_split_two_part(char *line);
char	*delete_spaces_first_last(char *str);
char	*get_second_part(char *line, int *start, int *end);
char	*get_first_part(char *line, int *start, int *end);
void	add_door(t_door **s_door, t_door *s_new);
t_door	*new_door(int i, int j);

// map array
int		fill_map_array(t_cub *img, char *file_name);
int		count_lines_map(char *file_name);
int		find_tall_line(t_cub *img);
int		find_map_start(char *line);

// drawing mini map
void	initail_and_fill(t_cub *img, int i, int j);
void	draw_mini_map(t_cub *img);
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
void	backward_slid(t_cub *data, double prevpx, double prevpy);
void	forward_slid(t_cub *data, double nextpx, double nextpy);

// ray casting
int		check_is_ver_wall(t_cub *data);
int		check_is_hor_wall(t_cub *data);
void	increment_ray_angle(t_cub *data, int is_increment);
void	vertical_ray_equation(t_cub *data);
void	horizontal_ray_equation(t_cub *data);
void	draw_casted_rays(t_cub *data);
void	ray_coordinate(t_cub *data, int *i, int r, int is_hor);
double	distance(t_cub *data, double x2, double y2);
double	hor_ray_casting(t_cub *data);
double	ver_ray_casting(t_cub *data);
void	we_textures_up_down(t_cub *data, double next_px, int choice);

// walls 3D, floor and ceil
void	draw_ceil_floor(t_cub *data, int i);

// mini map
void	put_map_pixel(t_cub *data, int x, int y, int color);
void	draw_custom_map(t_cub *img);

// draw textures
void	so_textures(t_cub *data, int i);
void	no_textures(t_cub *data, int i);
void	ea_textures(t_cub *data, int i);
void	we_textures(t_cub *data, int i);
void	calculate_wall_height_offset(t_cub *data, int height, int i);

// animation
void	coordinate_animation(t_cub *data, int *ptr);
void	coordinate_animation_torch(t_cub *data, int *ptr);
void	draw_fire_animation(t_cub *data, int r);
void	draw_torch_animation(t_cub *data, int r);

//parsing
int		check_line_is_empty(char *line);

// parsing textures
int		check_texture(char	*str, t_cub *data);
int		check_path_of_text(t_cub *data);
int		check_type(char	*line, t_cub *data, int fd);

// parsing textures utils
int		get_paths(int fd, t_cub *data);
int		check_type_identifier(char **str, t_cub *data);
int		check_type_identifier_next(char **str, t_cub *data);

// parsing colors
char	*get_color(char **str);
int		check_color(char **str);
char	*ft_strjoin_one_char(char c, char *str);
int		check_color_is_valid(t_cub *data);

// parsing base conversion
char	*ft_puthex(int num);
int		hex_to_decimal(char *str);
char	*get_color_hex(char *color);
void	get_color_in_decimal(t_cub *data);

// parsing map
void	check_map(char	*str, t_cub *data);
int		check_line(char *line, t_cub *data);
int		check_border(char c, int i, int j, t_cub *data);
int		check_caracter_is_valid(char c, t_cub *data);
int		find_map(int fd);

// parsing map utils
void	check_map_is_empty(t_cub *data, int *i);
int		check_end_of_map(t_cub *data, int *i);
void	check_all_caracters(t_cub *data);
int		check_border_map(t_cub *data);

// free
void	free_texture(t_cub *data);
void	free_double(char **str);
void	free_doors(t_door *doors);

// error_msg
void	print_error_fd(void);
void	print_error_malloc(void);
void	print_error_caracter(t_cub *data);
void	print_error_border(t_cub *data);
void	print_error_map_empty(void);

// door
int		check_door(t_cub *data, double nextpx, double nextpy);
void	door_ver_coordinates(t_cub *data);
void	door_hor_coordinates(t_cub *data);
void	get_dist_door(t_cub *data, int r);
void	door_textures(t_cub *data, int i);
void	calculate_door_height_offset(t_cub *data, int height, int i);
void	get_door(t_cub *data, int x, int y);

//protect_img
void	protect_img_textures(t_cub *img);
void	protect_img_sprit_f(t_cub *data);
void	protect_img_sprit_tr(t_cub *data);

#endif
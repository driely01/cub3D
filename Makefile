NAME = cub3D

# Folders
BRESENHAM = bresenham_algo/
RENDER = rendring_stuff/
STRINGS = strings/
MLX = mlx_functions/
COORD = coordinates/
RCAST = ray_casting/
TEXTUR = textures_randring/
INIT = initial_all_variables/
PARS = parsing/

SRC = main.c \
	  ${INIT}init_draw_struct.c \
	  ${INIT}init_cast_struct.c \
	  ${INIT}init_texture_struct.c \
	  ${INIT}init_cub_struct.c \
	  ${INIT}initial_all.c \
	  ${PARS}check_color.c \
	  ${PARS}check_exc_file.c \
	  ${PARS}check_map.c \
	  ${PARS}check_texture.c \
	  ${PARS}find_start_map.c \
	  ${PARS}find_tall_line_count_lines.c \
	  ${PARS}ft_print_error.c \
	  ${PARS}map_array.c \
	  ${PARS}base_conversion.c \
	  ${PARS}check_map_utils.c \
	  ${PARS}check_textures_utils.c \
	  ${BRESENHAM}bresenham.c \
	  ${BRESENHAM}bresenham_utils_fn.c \
	  ${RENDER}cub_drawing.c \
	  ${RENDER}player_drawing.c \
	  ${RENDER}draw_custom_map.c \
	  ${RENDER}animation_sprit.c \
	  ${RENDER}animation_fire.c \
	  ${RENDER}draw_after_rot_move.c \
	  ${RENDER}ray_casting_draw.c \
	  ${RENDER}draw_ceil_floor.c \
	  ${STRINGS}get_next_line_utils.c \
	  ${STRINGS}get_next_line.c \
	  ${STRINGS}ft_strdup.c \
	  ${STRINGS}ft_strncmp.c \
	  ${STRINGS}ft_atoi.c \
	  ${STRINGS}ft_split.c \
	  ${STRINGS}ft_free.c \
	  ${STRINGS}ft_strjoin.c \
	  ${STRINGS}ft_lstnew.c \
	  ${STRINGS}ft_lst_addback.c \
	  ${STRINGS}protect_imgs.c \
	  ${MLX}put_pixel.c \
	  ${MLX}key_events.c \
	  ${MLX}mouse_events.c \
	  ${MLX}mlx_hooks_imgs.c \
	  ${COORD}mini_map.c \
	  ${COORD}move_left_and_right.c \
	  ${COORD}wall_silde.c \
	  ${COORD}doors_coordinates.c \
	  ${COORD}player_move_rotations.c \
	  ${RCAST}coordinate_and_equations.c \
	  ${RCAST}ray_casting.c \
	  ${RCAST}rays_angles_distances.c \
	  ${TEXTUR}west_texture.c \
	  ${TEXTUR}north_texture.c \
	  ${TEXTUR}east_texture.c \
	  ${TEXTUR}calculate_wall_height_offset.c \
	  ${TEXTUR}south_texture.c

HEADERS = cub3d.h

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror -Ofast#-fsanitize=address -g
CC = cc
RM = rm -f

all: ${NAME}

${NAME}: ${OBJ}
	${CC} ${CFLAGS} ${OBJ} -lmlx -framework OpenGL -framework AppKit -o ${NAME}

%.o: %.c ${HEADERS}
	${CC} ${CFLAGS} -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: clean all fclean re

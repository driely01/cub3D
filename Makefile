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

SRC = main.c \
	  ${INIT}init_draw_struct.c \
	  ${INIT}init_cast_struct.c \
	  ${INIT}init_texture_struct.c \
	  ${BRESENHAM}bresenham.c \
	  ${BRESENHAM}bresenham_utils_fn.c \
	  ${RENDER}cub_drawing.c \
	  ${RENDER}player_drawing.c \
	  ${RENDER}draw_custom_map.c \
	  ${RENDER}draw_after_rot_move.c \
	  ${RENDER}ray_casting_draw.c \
	  ${RENDER}draw_ceil_floor.c \
	  ${STRINGS}get_next_line_utils.c \
	  ${STRINGS}get_next_line.c \
	  ${STRINGS}ft_strdup.c \
	  ${STRINGS}map_array.c \
	  ${STRINGS}check_exc_file.c \
	  ${STRINGS}ft_strncmp.c \
	  ${STRINGS}find_tall_line_count_lines.c \
	  ${STRINGS}find_start_map.c \
	  ${MLX}put_pixel.c \
	  ${MLX}key_events.c \
	  ${MLX}mouse_events.c \
	  ${MLX}mlx_hooks_imgs.c \
	  ${COORD}mini_map.c \
	  ${COORD}move_left_and_right.c \
	  ${COORD}wall_silde.c \
	  ${COORD}player_move_rotations.c \
	  ${RCAST}coordinate_and_equations.c \
	  ${RCAST}ray_casting.c \
	  ${RCAST}rays_angles_distances.c \
	  ${TEXTUR}left_texture.c \
	  ${TEXTUR}down_texture.c \
	  ${TEXTUR}right_texture.c \
	  ${TEXTUR}calculate_wall_height_offset.c \
	  ${TEXTUR}up_texture.c

HEADERS = cub3d.h

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
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

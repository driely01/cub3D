NAME = cub3D

# Folders
BRESENHAM = bresenham_algo/
RENDER = rendring_stuff/
STRINGS = strings/
MLX = mlx_functions/

SRC = main.c \
	  ${BRESENHAM}bresenham.c \
	  ${BRESENHAM}bresenham_utils_fn.c \
	  ${RENDER}cub_drawing.c \
	  ${RENDER}mini_map.c \
	  ${STRINGS}get_next_line_utils.c \
	  ${STRINGS}get_next_line.c \
	  ${STRINGS}ft_strdup.c \
	  ${STRINGS}map_array.c \
	  ${MLX}put_pixel.c 

HEADERS = cub3d.h

OBJ = ${SRC:.c=.o}

CFLAGS = -Wall -Wextra -Werror -fsanitize=address
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

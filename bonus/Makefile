NAME	=	../cub3D_bonus

LIBFT	=	./libft/libft.a

LIBFT_DIR	=	./libft/

INC_DIR	=	./include/cube3d.h

LIBX	=	../minilibx-linux/libmlx.a

LIBXX	=	../minilibx-linux/libmlx_Linux.a

LIBX_DIR	=	../minilibx-linux/

CC	=	gcc

CFLAGS	=	-Wall -Werror -Wextra -g

LIBX_FLAGS	=	-lXext -lX11 -lm

SRC	=	./src/main.c ./src/circl_image.c \
		./src/bonus_error.c \
		./src/color.c ./src/cub_event.c \
		./src/cub_moovement.c ./src/debug_function.c \
		./src/destroydata.c ./src/destroydata_next.c \
		./src/get_door.c ./src/get_textur.c \
		./src/getmap.c ./src/init_data.c \
		./src/init_image.c ./src/initdata.c \
		./src/initdata_mini.c ./src/is_in_order.c \
		./src/loop_cub3d.c ./src/map_utils.c \
		./src/mini_map.c ./src/minimap.c \
		./src/newdata.c ./src/ray_cast.c \
		./src/ray_roundf.c ./src/render.c \
		./src/surround.c ./src/verify_line_map.c \
		./src/verify_path.c ./src/time.c

OBJ_DIR = obj

OBJ	=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir ${SRC}))

${shell mkdir -p ${OBJ_DIR}}

${OBJ_DIR}/%.o	:	./src/%.c
		${CC} ${CFLAGS} -o $@ -c $<

all	:	${NAME}

${NAME}	:	${OBJ} $(INC_DIR)
		make -C ${LIBX_DIR}
		make -C ${LIBFT_DIR}
		${CC} ${CFLAGS} -o $@ ${OBJ} ${LIBFT} ${LIBX} ${LIBXX} ${LIBX_FLAGS}

clean	:
		make clean -C ${LIBX_DIR}
		make clean -C ${LIBFT_DIR}
		rm -rf ${OBJ_DIR}

fclean	:	clean
		make fclean -C ${LIBFT_DIR}
		rm -f ${NAME}

re	:	fclean
		make -C ./

c	:
		clear

l	:
		make -C ./
		./${NAME} ./maps/map.cub

v	:
		make -C ./
		valgrind -s --leak-check=full --show-leak-kinds=all ./${NAME} ./maps/map.cub

vfd	:
		make -C ./
		valgrind -s --leak-check=full --show-leak-kinds=all --track-fds=yes ./${NAME} ./maps/map.cub

.PHONY	:	all clean fclean re

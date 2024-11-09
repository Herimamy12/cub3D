NAME	=	cub3d

LIBFT	=	./libft/libft.a

LIBFT_DIR	=	./libft/

LIBX	=	./minilibx-linux/libmlx.a

LIBXX	=	./minilibx-linux/libmlx_Linux.a

LIBX_DIR	=	./minilibx-linux/

CC	=	cc

# CFLAGS	=	-Wall -Werror -Wextra -g
CFLAGS	=	-g

LIBX_FLAGS	=	-lXext -lX11 -lm

SRC	=	${wildcard ./src/*.c}
# SRC	=	./src/main.c ./src/newdata.c

OBJ_DIR = obj

OBJ	=	$(patsubst %.c, $(OBJ_DIR)/%.o, $(notdir ${SRC}))

.SILENT	:

${shell mkdir -p ${OBJ_DIR}}

${OBJ_DIR}/%.o	:	./src/%.c
		${CC} ${CFLAGS} -o $@ -c $<

all	:	${NAME}

${NAME}	:	${OBJ}
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

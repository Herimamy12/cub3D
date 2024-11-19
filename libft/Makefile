CC = cc

NAME = libft.a

CFLAGS = -Wall -Werror -Wextra

SRC = libft_utils.c libft_next.c \
		get_next_line.c libft.c \
		ft_strncmp.c

OBJ = $(SRC:.c=.o)

.SILENT :

%.o : %.c
		$(CC) $(CFLAGS) -o $@ -c $<

all : $(NAME)

$(NAME) : $(OBJ)
		ar rsc $@ $^

clean :
		rm -f $(OBJ)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re

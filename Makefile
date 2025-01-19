MAND_DIR		=	./mandatory

BONUS_DIR		=	./bonus

NAME			=	cub3D

NAME_BONUS 		=	cub3D_bonus

all				:	${NAME} 

${NAME}         :
				make -C $(MAND_DIR)

bonus			:	${NAME_BONUS} 

${NAME_BONUS}	:
				make -C $(BONUS_DIR)

clean			:
				make clean -C $(MAND_DIR)
				make clean -C $(BONUS_DIR)

fclean			:	clean
				make fclean -C $(MAND_DIR)
				make fclean -C $(BONUS_DIR)

re				:	fclean all

.PHONY			: all bonus clean fclean re

MAND_DIR		=	./mandatory

BONUS_DIR		=	./bonus

all				:
				make -C $(MAND_DIR)

bonus			:
				make -C $(BONUS_DIR)

clean			:
				make clean -C $(MAND_DIR)
				make clean -C $(BONUS_DIR)

fclean			:	clean
				make fclean -C $(MAND_DIR)
				make fclean -C $(BONUS_DIR)

re				:	fclean all

.PHONY			: all bonus clean fclean re
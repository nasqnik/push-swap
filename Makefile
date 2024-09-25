CC 			= cc
CFLAGS 		= -Wall -Werror -Wextra
RM 			= rm -rf
NAME 		= push_swap
HEADER		= push_swap.h
BONUS		= checker

SRC 		= push_swap.c parsing_checks.c parsing_initialize.c stack_utils.c \
			operation_push.c operation_swap.c operation_rotate.c operation_rrotate.c \
			sort_mini.c sort_big.c sort_utils.c sort_move.c
					
OBJ			= $(SRC:%.c=%.o)

BONUS_SRC 	= checker.c parsing_checks.c parsing_initialize.c stack_utils.c \
			operation_push.c operation_swap.c operation_rotate.c operation_rrotate.c 

BONUS_OBJ 	= $(BONUS_SRC:.c=.o)

LIBFT		=	libft/libft.a
FT_PRINTF	=	ft_printf/libftprintf.a

all: 		libft ft_printf $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS)  -c $< -o $@

libft:
			@$(MAKE) -C libft/

ft_printf:
			@$(MAKE) -C ft_printf/

bonus: 		libft ft_printf $(BONUS_OBJ)
			$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIBFT) $(FT_PRINTF) -o $(BONUS)

clean:
			@$(RM) $(OBJ) $(BONUS_OBJ)
			@$(MAKE) -C libft/ clean
			@$(MAKE) -C ft_printf/ clean

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(MAKE) -C ft_printf/ fclean
			@$(RM) $(NAME) $(BONUS)

re:			fclean all

.PHONY:		all	clean fclean re libft ft_printf bonus

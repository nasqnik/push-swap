CC 					= gcc
CFLAGS 				= -Wall -Werror -Wextra
RM 					= rm -rf
NAME 				= push_swap
HEADER				= push_swap.h
#CHECKER			= checker

SRC 				= push_swap.c parsing_checks.c parsing_initialize.c stack_utils.c \
					operation_push.c operation_swap.c operation_rotate.c operation_rrotate.c \
					sort_mini.c sort_big.c
					
OBJ					= $(SRC:%.c=%.o)

#CHECKER_SRC 		= 
#CHECHER_OBJ 		= $(CHECKER_SRC:.c=.o)

LIBFT				=	libft/libft.a
FT_PRINTF			=	ft_printf/libftprintf.a

all: libft ft_printf $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(FT_PRINTF) -o $(NAME)

%.o:		%.c $(HEADER)
			$(CC) $(CFLAGS)  -c $< -o $@

libft:
		@$(MAKE) -C libft/

ft_printf:
		@$(MAKE) -C ft_printf/


clean:
			@$(RM) $(OBJ)
			@$(MAKE) -C libft/ clean
			@$(MAKE) -C ft_printf/ clean

fclean:		clean
			@$(MAKE) -C libft/ fclean
			@$(MAKE) -C ft_printf/ fclean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all	clean	fclean	re	libft ft_printf

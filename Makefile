SRCS			=	fractal.c libft_utils.c 

RM				= rm -f
GCC			= gcc -Wall -Wextra -Werror
NAME			= fract_ol
all:			$(SRCS) $(NAME)


$(NAME): $(SRCS)
	$(GCC) -I./mlx -framework OpenGL -framework AppKit $(SRCS) -L./mlx -lmlx -o $(NAME)
	@reset
	@echo "\n \
	please try these \n \
	deneme,ikinciarg,uc \n"

clean:
	$(RM) $(NAME)

fclean:			clean
	@echo "files cleaned."

re:				fclean $(NAME)

.PHONY:			all clean fclean re

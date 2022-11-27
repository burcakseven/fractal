SRCS			=	fractal.c libft_utils.c 

RM				= rm -f
GCC			= gcc -Wall -Wextra -Werror
NAME			= fract_ol
all:			$(SRCS) $(NAME)


$(NAME): $(SRCS)
	$(GCC) -I./mlx -framework OpenGL -framework AppKit $(SRCS) -L./mlx -lmlx -o $(NAME)
	@reset
	@echo "\n \
	please try these"
	@echo "\033[36mdeneme\033[0m"
	@echo "\033[31mikinciarg\033[0m"
	@echo "\033[92muc\033[0m"

clean:
	$(RM) $(NAME)

fclean:			clean
	@echo "files cleaned."

re:				fclean $(NAME)

.PHONY:			all clean fclean re

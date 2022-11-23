SRCS			= minilibx.c mouse_hooks.c \
				fract_ol.c
RM				= rm -f
GCC			= gcc -Wall -Wextra -Werror
NAME			= fract_ol
all:			$(SRCS) $(NAME)


$(NAME): $(SRCS)
	$(GCC) -I./mlx -framework OpenGL -framework AppKit $(SRCS) -L./mlx -lmlx -o $(NAME)

clean:
	$(RM) $(NAME)

fclean:			clean
	@echo "cleaning 100%"

re:				fclean $(NAME)


.PHONY:			all clean fclean re

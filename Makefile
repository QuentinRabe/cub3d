NAME	=	cub3D
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I./includes -I./libft -I./minilibx-linux -g -D STAT=2
LDFLAGS	=	-L./libft -lft -L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
O_DIR	=	objs_dir
OBJS	=	$(addprefix $(O_DIR)/, $(SRCS:.c=.o))
SRCS	=	$(shell find srcs -name "*.c") main.c
$(O_DIR)/%.o		:	%.c
		@mkdir -p $(dir $@)
		$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
		make -C ./libft
		make -C ./minilibx-linux
		$(CC) $(CFLAGS)  $(SRCS) -o $(NAME) $(LDFLAGS)

clean	:
		make clean -C ./libft
		make clean -C ./minilibx-linux
		rm -rf $(O_DIR)

fclean	:	clean
		make fclean -C ./libft
		rm -f $(NAME)

msh_val	:	all
		@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) $(ARGS)
re		:	fclean all

.PHONY	:	all fclean clean re msh_val

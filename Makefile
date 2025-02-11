NAME	=	cub3D
CC		=	gcc
CFLAGS	=	-Wall -Werror -Wextra -I./includes -I./libft -I./minilibx-linux -g -D STAT=2
LDFLAGS	=	-L./libft -lft -L./minilibx-linux -lmlx -lXext -lX11 -lm -lbsd
SRCS	=	srcs/gnl/get_next_line.c\
srcs/gnl/get_next_line_utils.c\
srcs/error_handler/input.c\
srcs/error_handler/status.c\
srcs/error_handler/read.c\
srcs/parsing/color.c\
srcs/parsing/color_additionnal.c\
srcs/parsing/store.c\
srcs/parsing/texture.c\
srcs/parsing/texture_additionnal.c\
srcs/parsing/map_check.c\
srcs/parsing/map_additionnal_1.c\
srcs/parsing/parse.c\
srcs/parsing/map.c\
srcs/parsing/map_additionnal.c\
srcs/utils/free.c\
srcs/utils/utils_1.c\
srcs/utils/utils_2.c\
srcs/print/ascii.c\
srcs/events/event.c\
./main.c\

O_DIR	=	objs_dir
OBJS	=	$(addprefix $(O_DIR)/, $(SRCS:.c=.o))

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


.PHONY: all clean fclean re

NAME	=	cub3D
CC		=	clang
FLAGS	=	-O3 -Wall -Wextra -Werror
INC		=	incs
OBJ		=	objs
SRC		=	srcs
LIBFT	=	libft
LIBMLX	=	libmlx
INCS	=	$(addprefix $(INC)/, cub3d.h)
OBJS	=	$(addprefix $(OBJ)/, $(SRCS:.c=.o))
SRCS 	=	get_next_line.c \
			get_next_line_utils.c \
			file_parsing.c \
			map_parsing.c \
			load_texture.c \
			start_game.c \
			mlx_utils.c \
			raycasting_floor.c \
			hook.c \
			move.c \
			wall.c \
			raycasting_sprite.c \
			save.c

all: init $(NAME)

init:
	mkdir -p $(OBJ)
	make -C $(LIBFT)
	make -C $(LIBMLX)

$(NAME): $(OBJS) $(INCS)
	$(CC) $(FLAGS) -I$(INC) -o $(NAME) srcs/main.c $(OBJS) -Llibft -lft -Llibmlx -lmlx -lX11 -lbsd -lm -lXext

$(OBJ)/%.o: $(SRC)/%.c $(INCS)
	$(CC) $(FLAGS) -I$(INC) -c $< -o $@

clean:
	rm -rf $(OBJ)
	make -C $(LIBFT) clean
	make -C $(LIBMLX) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT) fclean

re: fclean all

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -lmlx -framework OpenGL -framework AppKit

LIBFT_DIR = ./libft
LIBFT_INC = $(LIBFT_DIR)/inc
LIBFT = $(LIBFT_DIR)/libft.a

INC = inc

MAIN = src/main.c
# scene
SRC := $(SRC) \
	src/scene/init_scene.c \
	src/scene/clean_scene.c \
	src/scene/print_scene.c \
	src/scene/set_color.c \
	src/scene/set_map.c \
	src/scene/set_path.c \
	src/scene/set_resolution.c \
	src/scene/verify_map.c \
# player
SRC := $(SRC) \
	src/player/init_player.c \
	src/player/move_player.c \
	src/player/rotate_player.c
# window
SRC := $(SRC) \
	src/window/init_window.c \
	src/window/init_textures.c \
	src/window/load_texture.c \
	src/window/handle_keys.c \
	src/window/reset_image.c

# cast
SRC := $(SRC) \
	src/cast/init_cast.c \
	src/cast/do_cast.c \
	src/cast/draw_cast.c \
	src/cast/draw_sprites.c \
	src/cast/cast_all.c
# utils (distance ????)
SRC := $(SRC) \
	src/utils/is_num.c \
	src/utils/free_split.c \
	src/utils/distance.c \
	src/utils/game_over.c
# vector
SRC := $(SRC) \
	src/vector/vector.c
# error
SRC := $(SRC) \
	src/error/print_error.c

OBJ = $(notdir $(SRC:.c=.o))

NAME = cub3D
all : $(NAME)

$(NAME): $(MAIN) $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(MLX_FLAGS) -I $(LIBFT_INC) -I $(INC) $(LIBFT) $(OBJ) $(MAIN) -o $(NAME)

%.o: src/scene/%.c
	$(CC) $(CFLAGS) -c -I $(LIBFT_INC) -I $(INC) $< -o $(@)
%.o: src/cast/%.c
	$(CC) $(CFLAGS) -c -I $(LIBFT_INC) -I $(INC) $< -o $(@)
%.o: src/player/%.c
	$(CC) $(CFLAGS) -c -I $(LIBFT_INC) -I $(INC) $< -o $(@)
%.o: src/window/%.c
	$(CC) $(CFLAGS) -c -I $(LIBFT_INC) -I $(INC) $< -o $(@)
%.o: src/ray/%.c
	$(CC) $(CFLAGS) -c -I $(LIBFT_INC) -I $(INC) $< -o $(@)
%.o: src/utils/%.c
	$(CC) $(CFLAGS) -c -I $(LIBFT_INC) -I $(INC) $< -o $(@)
%.o: src/vector/%.c
	$(CC) $(CFLAGS) -c -I $(LIBFT_INC) -I $(INC) $< -o $(@)
%.o: src/error/%.c
	$(CC) $(CFLAGS) -c -I $(LIBFT_INC) -I $(INC) $< -o $(@)
%.o: src/vector/%.c
	$(CC) $(CFLAGS) -c -I $(LIBFT_INC) -I $(INC) $< -o $(@)

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	make clean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -f $(NAME)

re: fclean all

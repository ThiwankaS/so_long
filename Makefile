TARGET_PROGRM	= so_long

CMD				= cc
CFLAGS			= -Wall -Wextra -I/usr/include -Iminilibx-linux -O3 -g -fPIE
LFLAGS			= -Lminilibx-linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

TARGET_LIBFTA	= libft.a
LIBFT_DIR		= ft_libft
LIBFT_A			= $(TARGET_LIBFTA)

# MiniLibX library
MLX_DIR			= minilibx-linux
MLX_LIB			= $(MLX_DIR)/libmlx_Linux.a
MLX_REPO		= https://github.com/42Paris/minilibx-linux

SRC_PROGRM		= \
					srcs/game_window.c\
					srcs/helper_main.c\
					srcs/helper_map.c\
					srcs/main.c\
					srcs/map_draw.c\
					srcs/map_parse.c\
					srcs/map_valid_path.c\
					srcs/map_validate.c\
					srcs/moves.c\
					srcs/texture.c\
					srcs/utils_main.c\
					srcs/utils_window.c\

OBJ_PROGRM		= $(SRC_PROGRM:.c=.o)

HEADER			= so_long.h ft_libft/libft.h ft_libft/ft_gnl/get_next_line.h \
					ft_libft/ft_printf/ft_printf.h minilibx-linux/mlx.h

all: $(LIBFT_A) $(MLX_LIB) $(TARGET_PROGRM)

# Build the libft library and move it to the current directory
$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)/$(TARGET_LIBFTA) .

# Build/update the MiniLibX graphic library
$(MLX_LIB):
	@if [ ! -d "$(MLX_DIR)" ]; then\
		echo "cloning $(MLX_DIR) from $(MLX_REPO)....";\
		git clone $(MLX_REPO) $(MLX_DIR);\
	fi
	$(MAKE) -C $(MLX_DIR)

# Link the final executable with objects from your project, libft and MiniLibX
$(TARGET_PROGRM): $(OBJ_PROGRM) $(LIBFT_A) $(MLX_LIB)
	$(CMD) $(CFLAGS) -o $@ $^ $(LFLAGS)

%.o : %.c $(HEADER)
	$(CMD) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PROGRM)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -rf $(TARGET_PROGRM) $(TARGET_LIBFTA)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(MLX_DIR) clean
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all clean fclean re

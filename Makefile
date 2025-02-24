TARGET_PROGRM = so_long

CMD = gcc
CFLAGS = -Wall -Wextra -I/usr/include -Imlx_linux -O3 -g -fPIE
LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lz

TARGET_LIBFTA = libft.a

LIBFT_DIR = ft_libft
LIBFT_A = $(TARGET_LIBFTA)

SRC_PROGRM = \
	srcs/game_hooks.c\
	srcs/game_window.c\
	srcs/helper_game.c\
	srcs/helper_main.c\
	srcs/helper_map.c\
	srcs/helper_window.c\
	srcs/main.c\
	srcs/map_draw.c\
	srcs/map_parse.c\
	srcs/map_valid_path.c\
	srcs/map_validate.c\
	srcs/moves.c\
	srcs/texture.c\
	srcs/utils_main.c\
	srcs/utils_window.c\

OBJ_PROGRM = $(SRC_PROGRM:.c=.o)

HEADER = so_long.h ft_libft/libft.h ft_libft/ft_gnl/get_next_line.h ft_libft/ft_printf/ft_printf.h mlx_linux/mlx.h

all: $(LIBFT_A) $(TARGET_PROGRM)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)/$(TARGET_LIBFTA) .  # Moved here

$(TARGET_PROGRM): $(OBJ_PROGRM) $(LIBFT_A)
	$(CMD) $(CFLAGS) -o $@ $^ $(LFLAGS)

%.o: %.c $(HEADER)
	$(CMD) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_PROGRM)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(TARGET_PROGRM) $(TARGET_LIBFTA)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

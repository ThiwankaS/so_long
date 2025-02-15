TARGET_PROGRM = so_long

CMD = gcc
CFLAGS = -Wall -Wextra -I/usr/include -Imlx_linux -O3 -g -fsanitize=address,undefined
LFLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

TARGET_LIBFTA = libft.a

LIBFT_DIR = ft_libft
LIBFT_A = $(TARGET_LIBFTA)

SRC_PROGRM = \
	main.c\

OBJ_PROGRM = $(SRC_PROGRM:.c=.o)

HEADER = so_long.h -I./ft_libft -I./ft_libft/ft_gnl -I./ft_libft/ft_printf -Imlx_linux

all: $(LIBFT_A) $(TARGET_PROGRM)

$(LIBFT_A):
	$(MAKE) -C $(LIBFT_DIR)
	mv $(LIBFT_DIR)/$(TARGET_LIBFTA) .

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

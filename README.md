# So_Long Project
A simple 2D game built using MiniLibX.

## Compilation
```sh
make
```

## Directory Structure
```
├── ft_libft         	# Custom C library https://github.com/ThiwankaS/ft_libft
├── mlx_linux        	# MiniLibX library https://github.com/42Paris/minilibx-linux
├── srcs             	# Game source files
   ├── game_hooks.c		# Contains all event hooks
   ├── game_window.c	# Contains all the window management funtions
   ├── helper_main.c	# Conatins helper functions to the main
   ├── helper_map.c		# Conatins helper functions to load the map
   ├── helper_window.c  # Conatins helper functions to window management
   ├── main.c			# Conatins main entry point to the program
   ├── map_draw.c		# Conatins helper functions to draw the map
   ├── map_parse.c		# Conatins helper functions to the main
   ├── map_valid_path.c	# Conatins helper functions to check the map contains a valid path
   ├── map_validate.c	# Conatins functions relate to validate map
   ├── moves.c			# Conatins functions realte to move the character
   ├── so_long.h        # Main header file of the program
   ├── textures  		# Contain utility functions to load the textures
   ├── utils_main.c 	# Contain utility functions to the main program
├── textures		 	# Game assets
   ├── collectible.png
   ├── collectible.xpm
   ├── empty_space.png
   ├── empty_space.xpm
   ├── exit_open.png
   ├── exit_open.xpm
   ├── exit.png
   ├── exit.xpm
   ├── player.png
   ├── player.xpm
   ├── wall.png
   ├── wall.xpm
├── Makefile             # Help to compile the program
├── test.ber			 # Map to test the Game
```

## Function Overview
### `main.c`
- `int main(int argc, char **argv)`: Initializes the game, loads assets, and starts the loop.

### `ft_gnl/`
- `char *get_next_line(int fd)`: Reads a line from a file descriptor.

### `ft_printf/`
- `int ft_printf(const char *format, ...)`: Custom printf implementation.

## Data Structures

### `t_position` # will contain the information of 'P' and 'E'
```c
typedef struct s_position
{
	int		x;
	int		y;
	char	type;
}	t_position;
```

### `t_texture` # will hold the pointers to the game textures
```c
typedef struct s_texture
{
	void	*empty_space;
	void	*wall;
	void	*collectible;
	void	*player;
	void	*exit;
	void	*exit_open;
}	t_texture;
```

### `t_info` # will contains the summery of characters on the map
```c
typedef struct s_info
{
	int	p_count;
	int	e_count;
	int	c_count;
	int	s_count;
	int	w_count;
	int	height;
	int	width;
}	t_info;
```

### `t_game` # main data structure of the game, holds all the data require
```c
typedef struct s_game
{
	int			score;
	int			img_width;
	int			img_height;
	int			count_moves;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*temp;
	char		**map;
	t_texture	*textures;
	t_position	*player;
	t_position	*exit;
	t_info		*map_info;
}	t_game;
```
- `mlx`: MiniLibX connection
- `win`: Window pointer
- `map`: 2D array for the game map
- `player_x/y`: Player position

## Flowchart
```
Start -> Load Map -> Render Window -> Player Input
       -> Update Game State -> Check for Win/Loss -> Loop
```

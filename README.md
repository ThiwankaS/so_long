# So_Long Project
A simple 2D game built using MiniLibX.

## Compilation
```sh
make
```

## Directory Structure
```
├── ft_libft         # Custom C library
├── mlx_linux        # MiniLibX library
├── srcs             # Game source files
   ├── main.c        # Entry to the game
   ├── utils_main.c  # Contain utility functions for main program
   ├── helper_main.c # Contain helper function to the main program
├── textures         # Game assets
├── docs             # Documentation files
```

## Function Overview
### `main.c`
- `int main(int argc, char **argv)`: Initializes the game, loads assets, and starts the loop.

### `ft_gnl/`
- `char *get_next_line(int fd)`: Reads a line from a file descriptor.

### `ft_printf/`
- `int ft_printf(const char *format, ...)`: Custom printf implementation.

## Data Structures

### `t_texture`
```c
typedef struct s_texture
{
	/* data */
}
```

### `t_image`
```c
typedef struct s_image
{
	/* data */
}	t_image;
```

### `t_map`
```c
typedef struct s_map
{
	/* data */
}	t_map;
```

### `t_game`
```c
typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_texture	*textures;
	t_image		*images;
	t_map		*maps;
	int			width;
	int			height;
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

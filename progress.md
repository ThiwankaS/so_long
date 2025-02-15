# So_Long Project
A simple 2D game built using MiniLibX.

## Compilation
```sh
make
```

## Directory Structure
```
├── ft_libft     # Custom C library
├── mlx_linux    # MiniLibX library
├── srcs         # Game source files
├── textures     # Game assets
├── docs         # Documentation files
```

## Function Overview
### `main.c`
- `int main(int argc, char **argv)`: Initializes the game, loads assets, and starts the loop.

### `ft_gnl/`
- `char *get_next_line(int fd)`: Reads a line from a file descriptor.

### `ft_printf/`
- `int ft_printf(const char *format, ...)`: Custom printf implementation.

## Data Structures
### `t_game`
```c
typedef struct s_game {
    void    *mlx;
    void    *win;
    char    **map;
    int     player_x;
    int     player_y;
} t_game;
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

## TODO List
- [ ] Argument validation
    - [ ] ./so_long <map_name> valid game starting with argument
    - [ ] if argc > 2 -> too much arguments
    - [ ] if argc < 2 -> some arguments missing
- [ ] Add collision detection
- [ ] Implement collectible items
- [ ] Optimize rendering


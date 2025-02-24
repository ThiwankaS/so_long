/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:36:28 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/24 02:59:24 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../ft_libft/libft.h"
# include "../ft_libft/ft_printf.h"
# include "../ft_libft/get_next_line.h"
# include "../mlx_linux/mlx.h"

# define TILE_SIZE 64
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define KEY_ESC 65307
# define KEY_OK 65293
# define KEY_YES 121
# define KEY_NO 110

typedef struct s_position
{
	int		x;
	int		y;
	char	type;
}	t_position;

typedef struct s_texture
{
	void	*empty_space;
	void	*wall;
	void	*collectible;
	void	*player;
	void	*exit;
	void	*exit_open;
}	t_texture;

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

typedef struct s_game
{
	int			score;
	int			img_width;
	int			img_height;
	int			count_moves;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*temp;
	void		*img;
	char		**map;
	t_texture	*textures;
	t_position	*player;
	t_position	*exit;
	t_info		*map_info;
}	t_game;

//utils_main.c
int		ft_error(char *msg);
int		ft_exit(char **arr);
void	ft_set_point(char **map, char c, int *x, int *y);
void	ft_start(t_game *game, char *map_name);
void	ft_cleanup(t_game *game);

//helper_main.c
bool	ft_isvalid(const char *str);

//map_parse.c
void	ft_load_map(t_game *game, char *file_name);

//map_validate.c
bool	ft_map_validate(char **map, t_info *info);

//map_validate_path.c
bool	ft_contains_valid_path(char **map, t_info *info);

//texture.c
void	ft_load_textures(t_game *game);

//map_draw.c
void	ft_draw_map(t_game *game);

//moves.c
int		ft_key_press(int keycode, t_game *game);

void	ft_configure_vars(t_game *game);

int		ft_close_window(t_game *game);
int		ft_focus_out(void);
int		ft_focus_in(void);
int		ft_exit_confirm_key(int keycode, t_game *game);
int		ft_exit_confirm_key_win(int keycode, t_game *game);

void	ft_hooks(t_game *game);

int		ft_exit_confirmation(t_game *game);

int		ft_close_window_confirmation(t_game *game);
int		ft_close_window_win(t_game *game);
int		ft_win(t_game *game);
int		ft_map_info_init(char **map, t_info *map_info);

int		ft_get_width(char **map);
int		ft_get_height(char **map);
int		ft_set_window_size(t_game *game, int *width, int *height, int *size);

void	print_map(char **map, t_info *map_info);
char	*ft_strncpy(char *dest, char *src, int n);
int		ft_count_nl(char *str);

int		ft_clean_textures(t_game *game);
void	ft_clear(t_game *game, char *msg);
int		ft_clean_game(t_game *game);
bool	ft_valid_char(char c);

#endif

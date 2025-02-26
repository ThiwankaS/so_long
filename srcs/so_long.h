/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:36:28 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/26 14:11:27 by tsomacha         ###   ########.fr       */
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
# include "../minilibx-linux/mlx.h"

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
	char		prev;
	t_texture	*textures;
	t_position	*player;
	t_position	*exit;
	t_info		*map_info;
}	t_game;

int		ft_error(char *msg);
int		ft_exit(char **arr);
int		ft_count_nl(char *str);
int		ft_get_width(char **map);
int		ft_get_height(char **map);
int		ft_clean_game(t_game *game);
int		ft_close_window(t_game *game);
int		ft_clean_textures(t_game *game);
int		ft_key_press(int keycode, t_game *game);
int		ft_map_info_init(char **map, t_info *map_info);
int		ft_set_window_size(t_game *game, int *width, int *height, int *size);

void	ft_hooks(t_game *game);
void	ft_cleanup(t_game *game);
void	ft_draw_map(t_game *game);
void	ft_load_textures(t_game *game);
void	ft_configure_vars(t_game *game);
void	ft_clear(t_game *game, char *msg);
void	ft_start(t_game *game, char *map_name);
void	ft_load_map(t_game *game, char *file_name);
void	ft_set_point(char **map, char c, int *x, int *y);

char	*ft_strncpy(char *dest, char *src, int n);

bool	ft_isvalid(const char *str);
bool	ft_valid_char(char c);
bool	ft_map_validate(char **map, t_info *info);
bool	ft_contains_valid_path(char **map, t_info *info);

#endif

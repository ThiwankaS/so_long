/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:36:28 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/16 12:36:27 by tsomacha         ###   ########.fr       */
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

# define WIDTH 1820
# define HEIGHT 980
# define TILE_SIZE 64

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
	void		*mlx_ptr;
	void		*win_ptr;
	char		**map;
	t_texture	*textures;
	t_position	*player;
	t_position	*exit;
	t_info		*map_info;
	int			score;
	int			img_width;
	int			img_height;
	int			count_colectibles;
	int			count_moves;
}	t_game;

//utils_main.c
int		ft_error(char *msg);
void	ft_start(t_game *game, char *map_name);
void	ft_cleanup(t_game *game);
int		ft_exit(char **arr);
void	ft_set_point(char **map, char c, int *x, int *y);

//helper_main.c
bool	ft_isvalid(const char *str);

//map_parse.c
char	**ft_load_map(char *file_name, t_info *map_info);

//map_validate.c
bool	ft_map_validate(char **map, t_info *map_info);

//map_validate_path.c
int		ft_contains_valid_path(char **map, t_info *map_info);

//temp function
void ft_print_map(char **map);

//texture.c
void	ft_load_textures(t_game *game);

//map_draw.c
void ft_draw_map(t_game *game);

//moves.c
int	ft_key_press(int keycode, t_game *game);

void ft_configure_vars(t_game *game, char **map, t_info *map_info);

#endif

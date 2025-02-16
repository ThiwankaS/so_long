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

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_position
{
	int		x;
	int		y;
	char	standing;
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

typedef struct s_image
{
	void	*empty_space;
	void	*wall;
	void	*collectible;
	void	*player;
	void	*exit;
	void	*exit_open;

}	t_image;

typedef struct s_map
{
	char		**full;
	t_position	player;
	t_position	tiles_to_render;
	t_position	exit;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_texture	*textures;
	t_image		*images;
	t_map		*maps;
	int			width;
	int			height;
	int			score;
	int			count_colectibles;
	int			count_moves;
	int			cooldown;
	int			exit_flag;
	int			count_exit;
	int			count_player;
}	t_game;


//utils_main.c
int	ft_error(char *msg);
void	ft_start(t_game *game);
void	ft_cleanup(t_game *game);

//helper_main.c
bool	ft_isvalid(const char *str);

#endif

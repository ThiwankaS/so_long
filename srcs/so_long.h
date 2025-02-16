/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 05:23:44 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/14 05:25:28 by tsomacha         ###   ########.fr       */
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

typedef struct s_texture
{
	/* data */
}	t_texture;

typedef struct s_image
{
	/* data */
}	t_image;

typedef struct s_map
{
	/* data */
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
}	t_game;


//utils_main.c
int	ft_error(char *msg);
void	ft_start(t_game *game);
void	ft_cleanup(t_game *game);

//helper_main.c
bool	ft_isvalid(const char *str);

#endif

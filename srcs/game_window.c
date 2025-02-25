/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 04:04:51 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/25 05:07:34 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_game *game)
{
	ft_cleanup(game);
	exit(EXIT_SUCCESS);
}

static int	ft_focus_out(void)
{
	return (0);
}

static int	ft_focus_in(void)
{
	return (0);
}

void	ft_hooks(t_game *game)
{
	mlx_key_hook(game->win_ptr, ft_key_press, game);
	mlx_hook(game->win_ptr, 17, 0, ft_close_window, game);
	mlx_hook(game->win_ptr, 9, 1L << 21, ft_focus_in, game);
	mlx_hook(game->win_ptr, 10, 1L << 21, ft_focus_out, game);
}

int	ft_set_window_size(t_game *game, int *width, int *height, int *size)
{
	int	sc_width;
	int	sc_height;

	mlx_get_screen_size(game->mlx_ptr, &sc_width, &sc_height);
	if (*width > sc_width || *height > sc_height)
		ft_error("EXCEED MAXIMUM SCREEN RESOLUTION!");
	*size = *width * TILE_SIZE;
	return (1);
}

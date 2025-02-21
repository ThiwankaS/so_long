/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 04:26:22 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/21 05:14:59 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window_confirmation(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->temp);
	return (0);
}

int	ft_close_window_win(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->temp);
	return (0);
}

int	ft_exit_confirmation(t_game *game)
{
	int		width;
	int		height;

	width = 600;
	height = 250;
	game->temp = mlx_new_window(game->mlx_ptr, width, height, "Exit");
	mlx_string_put(game->mlx_ptr, game->temp, 50, 50, 0xFFFFFF, "Do you want to quit ?");
	mlx_string_put(game->mlx_ptr, game->temp, 50, 80, 0xFFFFFF, "[Y] Yes  [N] No");
	mlx_hook(game->temp, 2, 1L << 0, ft_exit_confirm_key, game);
	return (0);
}

int ft_win(t_game *game)
{
	int		width;
	int		height;

	width = 600;
	height = 250;
	game->temp = mlx_new_window(game->mlx_ptr, width, height, "Exit");
	mlx_string_put(game->mlx_ptr, game->temp, 50, 50, 0xFFFFFF, "Congratulations, You have won!");
	mlx_string_put(game->mlx_ptr, game->temp, 50, 80, 0xFFFFFF, "[Press ENTER to Exit]");
	mlx_hook(game->temp, 2, 1L << 0, ft_exit_confirm_key_win, game);
	return (0);
}

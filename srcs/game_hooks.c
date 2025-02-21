/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_hooks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:56:50 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/21 04:20:42 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void ft_hooks(t_game *game)
{
	mlx_key_hook(game->win_ptr, ft_key_press, game);
	mlx_hook(game->win_ptr, 17, 0, ft_close_window, game);
	mlx_hook(game->win_ptr, 17, 0, ft_close_window, game);
	mlx_hook(game->win_ptr, 9, 1L << 21, ft_focus_in, game);
	mlx_hook(game->win_ptr, 10, 1L << 21, ft_focus_out, game);
}

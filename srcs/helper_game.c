/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/22 09:44:55 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/22 12:13:31 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_set_window_size(t_game *game, int *width, int *height, int *size)
{
	int	sc_width;
	int	sc_height;

	mlx_get_screen_size(game->mlx_ptr, &sc_width, &sc_height);

	if(*width > sc_width || *height > sc_height)
		ft_error("EXCEED MAXIMUM SCREEN RESOLUTION!");
	*size = *width * TILE_SIZE;
	return (1);
}

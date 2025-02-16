/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:36:43 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/16 11:53:57 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(char *msg)
{
	ft_printf("Error\n : %s\n", msg);
	exit(EXIT_FAILURE);
}

void	ft_cleanup(t_game *game)
{
	game->height = 1000;
	game->width = 2000;
	ft_printf("width : %d\n", game->width);
	ft_printf("height : %d\n", game->height);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:35:58 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/26 14:11:12 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_init(t_game *game)
{
	game->score = 0;
	game->img_width = 0;
	game->img_height = 0;
	game->count_moves = 0;
	game->prev = '0';
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	game->temp = NULL;
	game->img = NULL;
	game->map = NULL;
	game->textures = NULL;
	game->player = NULL;
	game->exit = NULL;
	game->map_info = NULL;
	return (1);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	if (argc == 2)
	{
		if (ft_isvalid((const char *)argv[1]))
		{
			game = ft_calloc(1, sizeof(t_game));
			if (!game)
				ft_error("MEMORY ALLOCATION FALIUR!");
			ft_init(game);
			ft_start(game, argv[1]);
		}
	}
	else
	{
		if (argc > 2)
			ft_error("TOO MANY ARGUMENTS!");
		if (argc < 2)
			ft_error("SOME ARGUMENTS MISSING!");
	}
	exit(EXIT_SUCCESS);
}

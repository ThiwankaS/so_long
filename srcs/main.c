/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 11:35:58 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/21 05:56:42 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
			ft_start(game, argv[1]);
			ft_cleanup(game);
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

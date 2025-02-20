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
	ft_printf("width : %d\n", game->img_width);
	ft_printf("height : %d\n", game->img_height);
}

int	ft_exit(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
	{
		free(arr[count]);
		count++;
	}
	free(arr);
	return (1);
}

void	ft_set_point(char **map, char c, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while(map[j])
	{
		while(map[j][i])
		{
			if(map[j][i] == c)
			{
				*x = i;
				*y = j;
			}
			i++;
		}
		i = 0;
		j++;
	}
}

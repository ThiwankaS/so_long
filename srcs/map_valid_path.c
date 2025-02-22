/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:44:14 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/21 06:10:10 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_duplicate_map(char **map, t_info *map_info)
{
	int		y;
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * (map_info->height + 1));
	if (!map_copy)
		ft_error("MEMORY ALLOCATION FAILED!");
	y = 0;
	while (y < map_info->height)
	{
		map_copy[y] = ft_strdup(map[y]);
		y++;
	}
	map_copy[y] = NULL;
	return (map_copy);
}

static void	ft_flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	ft_flood_fill(map, x + 1, y);
	ft_flood_fill(map, x - 1, y);
	ft_flood_fill(map, x, y + 1);
	ft_flood_fill(map, x, y - 1);
}

static int	ft_check_path(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[j])
	{
		while (map[j][i])
		{
			if (map[j][i] == 'C' || map[j][i] == 'E')
				ft_error("INVALID MAP (COLLECTIBLE OR EXIT NOT ACCESSIBLE)!");
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int	ft_contains_valid_path(char **map, t_info *map_info)
{
	int		x;
	int		y;
	char	**map_copy;

	map_copy = ft_duplicate_map(map, map_info);
	ft_set_point(map, 'P', &x, &y);
	ft_flood_fill(map_copy, x, y);
	ft_check_path(map_copy);
	ft_exit(map_copy);
	return (1);
}

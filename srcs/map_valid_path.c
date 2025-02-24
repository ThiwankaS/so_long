/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_valid_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:44:14 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/24 02:13:56 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_duplicate_map(char **map, t_info *info)
{
	int		y;
	char	**map_copy;

	map_copy = malloc(sizeof(char *) * (info->height + 1));
	if (!map_copy)
		return (NULL);
	y = 0;
	while (y < info->height)
	{
		map_copy[y] = ft_strdup(map[y]);
		y++;
	}
	map_copy[y] = NULL;
	return (map_copy);
}

static void	ft_flood_fill(char **map, t_info *info, int x, int y)
{
	if (x < 0 || x >= info->width || y < 0 || y >= info->height)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'X')
		return ;
	map[y][x] = 'X';
	ft_flood_fill(map, info, x + 1, y);
	ft_flood_fill(map, info, x - 1, y);
	ft_flood_fill(map, info, x, y + 1);
	ft_flood_fill(map, info, x, y - 1);
}

static bool	ft_check_path(char **map)
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
				return (false);
			i++;
		}
		i = 0;
		j++;
	}
	return (true);
}

bool	ft_contains_valid_path(char **map, t_info *info)
{
	int		x;
	int		y;
	char	**map_copy;

	map_copy = ft_duplicate_map(map, info);
	ft_set_point(map, 'P', &x, &y);
	ft_flood_fill(map_copy, info, x, y);
	if (!ft_check_path(map_copy))
	{
		ft_exit(map_copy);
		return (false);
	}
	ft_exit(map_copy);
	return (true);
}

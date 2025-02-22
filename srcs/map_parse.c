/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 03:44:24 by tsomacha          #+#    #+#             */
/*   Updated: 2025/02/22 05:22:51 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_get_map_height(char *file_name)
{
	int		fd;
	int		height;
	char	*line;

	height = 0;
	if (!file_name)
		ft_error("FAILED TO OPEN THE MAP (NULL FILE NAME)!");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error("FAILED TO OPEN THE MAP!");
	line = get_next_line(fd);
	while (line)
	{
		height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (height);
}

int	ft_get_width(char **map)
{
	int		x;
	int		width;
	int		length;

	if (!map || !*map)
		ft_error("INVALID MAP!");
	x = 0;
	width = 0;
	while (map[x])
	{
		length = ft_strlen(map[x]);
		if (length > width)
			width = length;
		x++;
	}
	width--;
	return (width);
}

int	ft_get_height(char **map)
{
	int		x;
	int		height;

	if (!map || !*map)
		ft_error("INVALID MAP!");
	x = 0;
	height = 0;
	while (map[x])
	{
		height++;
		x++;
	}
	return (height);
}

char	**ft_load_map(char *file_name, t_info *map_info)
{
	int		fd;
	int		count;
	char	**map;
	int		height;

	count = 0;
	height = ft_get_map_height(file_name);
	if (height < 3)
		ft_error("INVALID MAP(TOO SMALL)!");
	map = malloc(sizeof(char *) * (height + 1));
	if (!map)
		ft_error("MEMORY ALLOCATION FAILED!");
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error("FAILED TO OPEN THE MAP!");
	while (count < height)
	{
		map[count] = get_next_line(fd);
		count++;
	}
	map[count] = NULL;
	close(fd);
	if (!ft_map_validate(map, map_info))
		return (NULL);
	return (map);
}

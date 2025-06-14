/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 10:20:50 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/13 17:43:13 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_object(char c)
{
	if (c == WALL)
		return (1);
	if (c == EMPTY)
		return (1);
	if (c == PLAYER)
		return (1);
	if (c == DOOR)
		return (1);
	if (c == COLLECT)
		return (1);
	return (0);
}

void	check_map_basics(t_map_data *map)
{
	int		index_height;
	int		index_width;
	t_list	*iter;

	index_height = -1;
	iter = map->read_lst;
	map->map = (char **)malloc(map->height * sizeof(char *));
	if (map->map == NULL)
		clean_exit(map, "malloc failure", EXIT_FAILURE);
	while (++index_height < map->height)
	{
		map->map[index_height] = iter->line;
		if (ft_strlen(iter->line) != map->width)
			clean_exit(map, "Map dimensions incorrect!", MAP_ERROR);
		iter = iter->next;
	}
	map->width = map->width - 2;
	while (--index_height >= 0)
	{
		index_width = -1;
		while (++index_width < map->width)
			if (is_object(map->map[index_height][index_width]) == 0)
				clean_exit(map, "Wrong character(s)!", MAP_ERROR);

	}
}

void	check_map_advanced(t_map_data *map)
{
	t_pos	pos;

	pos.y = -1;
	while (++(pos.y) < map->height)
	{
		pos.x = -1;
		while (++(pos.x) < map->width)
		{
			if (map->map[pos.y][pos.x] == PLAYER && map->player.x >= 0)
				clean_exit(map, "More than one player!", MAP_ERROR);
			if (map->map[pos.y][pos.x] == PLAYER)
				map->player = pos;
			if (map->map[pos.y][pos.x] == DOOR && map->door.x >= 0)
				clean_exit(map, "More than one exit!", MAP_ERROR);
			if (map->map[pos.y][pos.x] == DOOR)
				map->door = pos;
			if ((pos.y == 0 || pos.y == map->height - 1 || pos.x == 0 || pos.x
					== map->width - 1) && map->map[pos.y][pos.x] != WALL)
				clean_exit(map, "Outer wall incomplete!", MAP_ERROR);
		}
	}
	if (map->player.x == -1)
		clean_exit(map, "Player not found!", MAP_ERROR);
	if (map->door.x == -1)
		clean_exit(map, "Exit not found!", MAP_ERROR);
}

void	register_collectables(t_map_data *map)
{
	t_pos	pos;

	pos.y = -1;
	while (++(pos.y) < map->height)
	{
		pos.x = -1;
		while (++(pos.x) < map->width)
		{
			if (map->map[pos.y][pos.x] == COLLECT)
			{
				lst_push_back(map, &(map->cols), NULL, &pos);
				(map->num_cols)++;
			}
		}
	}
	if (map->num_cols == 0)
		clean_exit(map, "Collectibles not found!", MAP_ERROR);
	map->map_copy = (char **)malloc(map->height * sizeof(char *));
	if (map->map == NULL)
		clean_exit(map, "malloc failure", EXIT_FAILURE);
	while (--(pos.y) >= 0)
		map->map_copy[pos.y] = ft_strdup(map->map[pos.y], map);
}

int	search_route(t_map_data *map, int x, int y)
{
	static int	cols;
	static int	door;
	int			result;

	result = 0;
	if (map->map_copy[y][x] == COLLECT)
		cols++;
	if (map->map_copy[y][x] == DOOR)
		door++;
	map->map_copy[y][x] = WALL;
	if (cols >= map->num_cols && door >= 1)
		return (1);
	if (y < map->height - 1 && map->map_copy[y + 1][x] != WALL)
		result += search_route(map, x, y + 1);
	if (y > 0 && map->map_copy[y - 1][x] != WALL && result == 0)
		result += search_route(map, x, y - 1);
	if (x < map->width - 1 && map->map_copy[y][x + 1] != WALL && result == 0)
		result += search_route(map, x + 1, y);
	if (x > 0 && map->map_copy[y][x - 1] != WALL && result == 0)
		result += search_route(map, x - 1, y);
	return (result);
}

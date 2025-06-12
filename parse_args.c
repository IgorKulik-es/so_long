/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:04:12 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/12 16:13:56 by ikulik           ###   ########.fr       */
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
	if (c == M_EXIT)
		return (1);
	if (c == COLLECT)
		return (1);
	return (0);
}

int	read_map(t_map_data *map, int argc, char **argv)
{
	int		fd;
	int		index;
	char	*next_line;

	if (argc != 2)
		clean_exit(map, "wrong number of arguments", 1);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		clean_exit(map, "error openning file", 1);
	if (ft_strncmp(&argv[1][ft_strlen(argv[0]) - 5], ".ber", 4) != 0)
		clean_exit(map, "wrong file extension", 1);
	next_line = get_next_line(fd);
	if (next_line == NULL || ft_strlen(next_line) == 0)
		clean_exit(map, "Error\nempty file", 1);
	lst_push_back(map, next_line);
	map->width = ft_strlen(next_line);
	map->height = 0;
	while (next_line != NULL)
	{
		map->height++;
		next_line = get_next_line(fd);
		lst_push_back(map, next_line);
	}
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
	if (map->map)
		clean_exit(map, "malloc failure", 1);
	while (++index_height < map->height)
	{
		map->map[index_height] = iter->line;
		if (ft_strlen(iter->line) != map->width)
			clean_exit(map, "Error\nMap dimensions incorrect", 1);
		iter = iter->next;
	}
	while (--index_height < map->height)
	{
		index_width = -1;
		while (++index_width < map->width)
			if (is_object(map->map[index_height][index_width]) == 0)
				clean_exit(map, "Error\nWrong character", 1);
	}
}

void	check_map_advanced(t_map_data *map)
{



}
/*	while (++index < map->height && index < map->width)
	{
		if (index < map->height && (map->map[index][0] != WALL
			|| map->map[index][map->width - 1] != WALL))
			clean_exit(map, "Error\nWall incomplete", 1);
		if (index < map->width &&
			(map->map[0][index] != WALL || map->map[map->height - 1][0] != WALL))
			clean_exit(map, "Error\nBorder wall incomplete", 1);
	}*/

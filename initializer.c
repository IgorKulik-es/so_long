/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:04:12 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/14 16:23:56 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initialize_map(t_map_data *map)
{
	map->cols = NULL;
	map->map = NULL;
	map->map_copy = NULL;
	map->read_lst = NULL;
	map->door.x = -1;
	map->door.y = -1;
	map->player.x = -1;
	map->player.y = -1;
	map->height = 0;
	map->width = 0;
	map->num_cols = 0;
	map->moves = 0;
	map->c_size = DF_CELL;
	map->offs.x = SIDE_OFF;
	map->offs.y = TOP_OFF;
}

int	read_map(t_map_data *map, int argc, char **argv)
{
	int		fd;
	char	*next_line;

	if (argc != 2)
		clean_exit(map, "wrong number of arguments", EXIT_FAILURE);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		clean_exit(map, "error openning file", EXIT_FAILURE);
	if (ft_strncmp(&(argv[1][ft_strlen(argv[1]) - 4]), ".ber", 4) != 0)
		clean_exit(map, "wrong file extension", EXIT_FAILURE);
	next_line = get_next_line(fd);
	if (next_line == NULL || ft_strlen(next_line) == 0)
		clean_exit(map, "empty file", MAP_ERROR);
	lst_push_back(map, &(map->read_lst), next_line, NULL);
	map->width = ft_strlen(next_line);
	while (next_line != NULL)
	{
		(map->height)++;
		next_line = get_next_line(fd);
		lst_push_back(map, &(map->read_lst), next_line, NULL);
	}
	return (0);
}

void	validate_map(t_map_data *map, int argc, char **argv)
{
	int	vert_fit;
	int	hor_fit;

	read_map(map, argc, argv);
	check_map_basics(map);
	check_map_advanced(map);
	register_collectables(map);
	if (search_route(map, map->player.x, map->player.y) == 0)
		clean_exit(map, "No viable route found!", MAP_ERROR);
	vert_fit = WIN_HEIGHT / map->height;
	hor_fit = WIN_WIDTH / map->width;
	if (hor_fit < vert_fit)
	{
		map->c_size = hor_fit;
		map->offs.x = 0;
		map->offs.y = WIN_HEIGHT / 2
			- (int)(((double)(map->height) / (double)2) * (double)map->c_size);
	}
	else
	{
		map->c_size = hor_fit;
		map->offs.y = 0;
		map->offs.x = WIN_WIDTH / 2
			- (int)(((double)(map->width) / (double)2) * (double)map->c_size);
	}
}




/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 20:04:12 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/07 20:04:12 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		clean_exit(map, "empty file", 1);
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

int	check_map(t_map_data *map)
{
	map->map = (int **)malloc(map->height * sizeof(int *));
	
}
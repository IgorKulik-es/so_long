/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:10:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/17 22:10:35 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	spawn_enemies(t_map_data *map)
{
	int		count;
	t_pos	pos;
	int		index;
	int		spawn;

	count = map->num_empty / EN_DENSITY + 1;
	srand(time(NULL));
	while (--count > 0)
	{
		index = 0;
		spawn = rand() % map->num_empty;
		pos.y = 0;
		while (++(pos.y) < map->height - 1 && index < spawn)
		{
			pos.x = 0;
			while (++(pos.x) < map->width - 1 && index <= spawn)
			{
				if (map->map[pos.y][pos.x] == EMPTY && (index++ == spawn))
				{
					map->map[pos.y][pos.x] = ENEMY;
					(map->num_empty)--;
				}
			}
		}
	}
}

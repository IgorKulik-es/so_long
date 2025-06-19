/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 22:10:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/18 16:51:15 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	copy_links(void **dst, void **src, int count);

void	spawn_enemies(t_mlx_data *data, t_map_data *map)
{
	int		count;
	t_pos	pos;
	int		spawn;

	count = map->num_enem;
	srand(5);
	while (--count >= 0)
	{
		spawn = rand() % map->num_empty;
		pos.y = 0;
		while (++(pos.y) < map->height - 1 && spawn > 0)
		{
			pos.x = 0;
			while (++(pos.x) < map->width - 1 && 0 <= spawn)
			{
				if (map->map[pos.y][pos.x] == EMPTY && (spawn-- == 0))
				{
					map->map[pos.y][pos.x] = ENEMY;
					(map->num_empty)--;
					data->enemies[count].pos.x = pos.x;
					data->enemies[count].pos.y = pos.y;
				}
			}
		}
	}
}

void	initialize_enemies(t_mlx_data *data)
{
	int	index;

	index = -1;	
	(data->enem_base).time = 0;
	data->map.num_enem = data->map.num_empty / EN_DENSITY;
	data->enemies = malloc(data->map.num_enem * sizeof(t_anim));
	while (++index < data->map.num_enem)
	{
		data->enemies[index] = data->enem_base;
		(data->enemies[index]).idl_frame = 0;
		(data->enemies[index]).facing = 1;
		(data->enemies[index]).moving = 0;
		(data->enemies[index]).steps = 0;
		(data->enemies[index]).pos.x = 0;
		(data->enemies[index]).pos.y = 0;
		copy_links((data->enemies[index]).idle_left,
			data->enem_base.idle_left, EN_IDLE);
		copy_links((data->enemies[index]).idle_right,
			data->enem_base.idle_right, EN_IDLE);
		copy_links((data->enemies[index]).walk_left,
			data->enem_base.walk_left, EN_WALK);
		copy_links((data->enemies[index]).walk_right,
			data->enem_base.walk_right, EN_WALK);
	}
}

void	copy_links(void **dst, void **src, int count)
{
	while (count >= 0)
	{
		count--;
		dst[count] = src[count];
	}
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:06:09 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/19 20:31:36 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player_cool(int key, t_mlx_data *data);
void	check_end_game(t_mlx_data *data, t_anim *entity, char mode);
void	move_enemy(t_mlx_data *data, t_anim *anim);
void	move_all_enemies(t_mlx_data *data);

int	key_manager_plus(int key, t_mlx_data *data)
{
	if ((key == UP || key == DOWN || key == LEFT || key == RIGHT)
		&& data->anim.moving == 0)
		move_player_cool(key, data);
	if (key == ESC || key == ESC_ASCII)
		close_window(data);
	return (0);
}

void	move_player_cool(int key, t_mlx_data *data)
{
	t_pos	new;
	t_pos	old;

	old = data->map.player;
	new.y = old.y - (key == UP) + (key == DOWN);
	new.x = old.x - (key == LEFT) + (key == RIGHT);
	if (new.x > old.x)
		data->anim.facing = 1;
	if (new.x < old.x)
		data->anim.facing = 0;
	if (data->map.map[new.y][new.x] == ENEMY)
		check_end_game(data, find_enemy(data, new), ENEMY);
	else if (data->map.map[new.y][new.x] != WALL && data->game_over == 0)
	{
		(data->map.moves)++;
		data->anim.moving = 1;
		data->anim.dest = new;
		data->map.player = new;
		if (data->map.map[new.y][new.x] == COLLECT)
			(data->map.num_cols)--;
		data->map.map[old.y][old.x] = EMPTY;
		data->map.map[new.y][new.x] = PLAYER;
		check_end_game(data, NULL, COLLECT);
		move_all_enemies(data);
	}
}

void	move_all_enemies(t_mlx_data *data)
{
	int	index;

	index = 0;
	while (index < data->map.num_enem)
	{
		move_enemy(data, &(data->enemies[index]));
		index++;
	}
}

void	move_enemy(t_mlx_data *data, t_anim *anim)
{
	t_pos	new;
	t_pos	old;
	char	move;

	old = anim->pos;
	move = rand() % 4;
	new.x = old.x - (move == 0) + (move == 1);
	new.y = old.y - (move == 2) + (move == 3);
	if (new.x > old.x)
		anim->facing = 1;
	if (new.x < old.x)
		anim->facing = 0;
	move = data->map.map[new.y][new.x];
	if (move == PLAYER)
			check_end_game(data, anim, ENEMY);
	else if (move == EMPTY && !(new.x
				== data->map.door.x && new.y == data->map.door.y))
	{
		anim->moving = 1;
		anim->dest = new;
		data->map.map[old.y][old.x] = EMPTY;
		data->map.map[new.y][new.x] = ENEMY;
	}
}

void	check_end_game(t_mlx_data *data, t_anim *entity, char mode)
{
	t_pos	door;

	if (mode == COLLECT)
	{
		if (data->map.num_cols > 0)
			return ;
		door = data->map.door;
		if (data->anim.dest.x == door.x && data->anim.dest.y == door.y)
			close_window(data);
		else if (data->map.map[door.y][door.x] != DOOR)
		{
			data->map.map[door.y][door.x] = DOOR;
			put_image_to_grid(data, data->door, door.x, door.y);
		}
	}
	if (mode == ENEMY && entity != NULL)
	{
	data->game_over = 1;
	data->anim.acting = 1;
	entity->acting = 1;
	entity->moving = 0;
	entity->step = 0;
	}
}

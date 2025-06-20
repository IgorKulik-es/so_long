/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gaming.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:06:09 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/20 19:37:51 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player_simple(int key, t_mlx_data *data);
int		end_game(t_mlx_data *data);
void	count_moves(t_mlx_data *data);

int	key_manager(int key, t_mlx_data *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_player_simple(key, data);
	if (key == ESC)
		close_window(data);
	return (0);
}

void	move_player_simple(int key, t_mlx_data *data)
{
	t_pos	new;
	t_pos	old;

	old = data->map.player;
	new = old;
	new.y = new.y - (key == UP) + (key == DOWN);
	new.x = new.x - (key == LEFT) + (key == RIGHT);
	if (data->map.map[new.y][new.x] != WALL)
	{
		count_moves(data);
		if (data->map.map[new.y][new.x] == COLLECT)
			(data->map.num_cols)--;
		data->map.player = new;
		data->anim.pos = new;
		if (data->map.num_cols <= 0)
			end_game(data);
		data->map.map[new.y][new.x] = PLAYER;
		data->map.map[old.y][old.x] = EMPTY;
		put_image_to_grid(data, data->player, new.x, new.y);
		put_image_to_grid(data, data->empty, old.x, old.y);
		if (new.x < old.x)
			data->anim.facing = 0;
		else
			data->anim.facing = 1;
	}
}

int	end_game(t_mlx_data *data)
{
	t_pos	door;

	door = data->map.door;
	if (data->map.player.x == door.x && data->map.player.y == door.y)
		close_window(data);
	else
		put_image_to_grid(data, data->door, door.x, door.y);
	return (0);
}

void	count_moves(t_mlx_data *data)
{
	(data->map.moves)++;
	write(1, "Total moves: ", 13);
	ft_putnbr_fd(data->map.moves, 1);
	write(1, "\n", 1);
}

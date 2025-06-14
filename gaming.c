/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:06:09 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/14 16:34:00 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int key, t_mlx_data *data);
int		end_game(t_mlx_data *data);
void	count_moves(t_mlx_data *data);

int	key_manager(int key, t_mlx_data *data)
{
	if (key == UP || key == DOWN || key == LEFT || key == RIGHT)
		move_player(key, data);
	if (key == ESC || key == ESC_ASCII)
		close_window(data);
	return (0);
}

void	move_player(int key, t_mlx_data *data)
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
		if (data->map.num_cols <= 0)
			end_game(data);
		data->map.map[new.y][new.x] = PLAYER;
		data->map.map[old.y][old.x] = EMPTY;
		put_image_from_grid(data, new.x, new.y);
		put_image_from_grid(data, old.x, old.y);
	}
}

int	end_game(t_mlx_data *data)
{
	t_pos	door;

	door = data->map.door;
	if (data->map.player.x == door.x && data->map.player.y == door.y)
		close_window(data);
	else if (data->map.map[door.y][door.x] != DOOR)
	{
		data->map.map[door.y][door.x] = DOOR;
		put_image_from_grid(data, door.x, door.y);
	}
	return (0);
}

void	count_moves(t_mlx_data *data)
{
	(data->map.moves)++;
	write(1, "Total moves: ", 13);
	ft_putnbr_fd(data->map.moves, 1);
	write(1, "\n", 1);
}

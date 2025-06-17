/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:15:49 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/16 19:49:45 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	standing_still(t_mlx_data *data)
{
	int		l_off;
	int		t_off;
	t_pos	player;
	int		frame;


	frame = 0;
	l_off = data->map.offs.x + data->map.c_size * data->map.player.x;
	t_off = data->map.offs.y + data->map.c_size * data->map.player.y;
	player.x = data->map.player.x;
	player.y = data->map.player.y;
	while (data->map.player.x == player.x && data->map.player.y == player.y)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->anim.standing[frame], l_off, t_off);
		usleep(500000);
		frame++;
		if (frame >= N_FRAMES_STAND)
			frame = 0;
	}
	mlx_put_image_to_window(data->mlx, data->win,
		data->empty, l_off, t_off);
}

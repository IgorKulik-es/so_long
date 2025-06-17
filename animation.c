/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 17:15:49 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/17 20:04:31 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	idle_player(t_mlx_data *data)
{
	static int				frame;
	static struct timeval	time_old;
	struct timeval			time_curr;

	if (time_old.tv_usec == 0)
		gettimeofday(&time_old, NULL);
	gettimeofday(&time_curr, NULL);
	if ((__uint64_t)time_curr.tv_usec - (__uint64_t)time_old.tv_usec > AN_DELAY)
	{
		if (data->anim.facing == 1)
			put_image_to_grid(data, data->anim.idle_right[frame],
				data->map.player.x, data->map.player.y);
		else
			put_image_to_grid(data, data->anim.idle_left[frame],
				data->map.player.x, data->map.player.y);
		frame++;
		if (frame >= FR_IDLE)
			frame = 0;
		time_old = time_curr;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:11:16 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/20 19:35:56 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	put_count(t_mlx_data *data)
{
	int	x;
	int	y;
	int	num;

	y = 0;
	x = WIN_WIDTH - 3 * NUM_WIDTH - TXT_MOVES;
	mlx_put_image_to_window(data->mlx, data->win, data->txt_moves, x, y);
	x = WIN_WIDTH - 3 * NUM_WIDTH;
	num = (data->map.moves / 100) % 10;
	mlx_put_image_to_window(data->mlx, data->win, data->txt_nums[num], x, y);
	x = WIN_WIDTH - 2 * NUM_WIDTH;
	num = (data->map.moves / 10) % 10;
	mlx_put_image_to_window(data->mlx, data->win, data->txt_nums[num], x, y);
	x = WIN_WIDTH - NUM_WIDTH;
	num = data->map.moves % 10;
	mlx_put_image_to_window(data->mlx, data->win, data->txt_nums[num], x, y);
}

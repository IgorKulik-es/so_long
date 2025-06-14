/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:06:09 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/14 14:39:46 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(int keycode, t_mlx_data *data)
{
	printf("keycode %d \n", keycode);
	if (keycode == ' ')
		printf("Hello there!\n");
	if (keycode == 65307 || keycode == 33)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->door);
		mlx_destroy_image(data->mlx, data->player);
		mlx_destroy_image(data->mlx, data->wall);
		mlx_destroy_image(data->mlx, data->empty);
		mlx_destroy_image(data->mlx, data->coll);
		mlx_destroy_display(data->mlx);
		free(data->mlx);
		clean_exit(&(data->map), "OK", 0);
	}
	return (0);
}

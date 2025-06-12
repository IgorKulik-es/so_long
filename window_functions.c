/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 18:06:09 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/12 20:08:47 by ikulik           ###   ########.fr       */
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
		free(data->mlx);
		exit(0);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:21:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/12 19:32:50 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **arr, int height)
{
	int	index;
	
	index = 0;
	if (arr == NULL)
		return ;
	while (index < height)
	{
		write(1, arr[index], ft_strlen(arr[index]));
		write(1, "\n", 1);
		index++;
	}
}




int	main(int argc, char **argv)
{
	//t_mlx_data	mlx_data;
	t_map_data	map;

	initialize_map(&map);
	read_map(&map, argc, argv);
	check_map_basics(&map);
	print_map(map.map, map.height);
/*	mlx_data.mlx = mlx_init();
	mlx_data.win = mlx_new_window(mlx_data.mlx, 1920, 1080, "Hello world!");
	sleep(1);
	mlx_hook(mlx_data.win, 2, 1L << 0, close_window, &mlx_data);
	mlx_loop(mlx_data.mlx);*/
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:21:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/20 19:36:31 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	main(int argc, char **argv)
{
	t_mlx_data	data;

	initialize_map(&(data.map));
	validate_map(&(data.map), argc, argv);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "So Long");
	add_images(&data);
	load_anim_src(&data);
	create_frames(&data);
	srand(time(NULL));
	initialize_enemies(&data);
	spawn_enemies(&data, &(data.map));
	create_background(&data);
	create_grid(&(data));
	put_count(&data);
	mlx_hook(data.win, 2, 1L << 0, key_manager_plus, &data);
	mlx_hook(data.win, 17, 0L, close_window, &data);
	mlx_loop_hook(data.mlx, idle_all, &data);
	mlx_loop(data.mlx);
}

/* void	print_map(char **arr, int height)
{
	int	index;

	index = 0;
	if (arr == NULL)
		return ;
	while (index < height)
	{
		write(1, arr[index], ft_strlen(arr[index]));
		index++;
	}
	write(1, "\n", 1);
} */

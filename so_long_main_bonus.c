/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:21:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/16 19:59:06 by ikulik           ###   ########.fr       */
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
	t_mlx_data	data;
	int			dummy;

	initialize_map(&(data.map));
	initialize_data(&data);
	validate_map(&(data.map), argc, argv);
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	asign_basic_colors(&data);
	data.coll = mlx_xpm_file_to_image(data.mlx, "./img/Booma.xpm", &dummy, &dummy);
	data.empty = mlx_xpm_file_to_image(data.mlx, "./img/Grass.xpm", &dummy, &dummy);
	data.coll = stretch_to_fit(&data, data.coll, DF_CELL, DF_CELL);
	data.empty = stretch_to_fit(&data, data.empty, DF_CELL, DF_CELL);
	data.anim.standing[N_FRAMES_STAND] = mlx_xpm_file_to_image(data.mlx, "./img/IDLE.xpm", &dummy, &dummy);
	create_anim_stand(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.anim.standing[0], 0, 0);
	//create_grid(&(data));
	mlx_hook(data.win, 2, 1L << 0, key_manager, &data);
	mlx_loop(data.mlx);
}

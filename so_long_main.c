/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:21:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/14 17:53:05 by ikulik           ###   ########.fr       */
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
	validate_map(&(data.map), argc, argv);
	if (argc)
		argv[0][0] = argv[0][0];
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, "Hello world!");
	asign_basic_colors(&data);
	data.player = mlx_xpm_file_to_image(data.mlx, "./img/Jarjar.xpm", &dummy, &dummy);
	data.coll = mlx_xpm_file_to_image(data.mlx, "./img/Booma.xpm", &dummy, &dummy);
	data.empty = mlx_xpm_file_to_image(data.mlx, "./img/Grass.xpm", &dummy, &dummy);
	data.coll = stretch_to_fit(&data, data.coll);
	data.player = stretch_to_fit(&data, data.player);
	data.empty = stretch_to_fit(&data, data.empty);
	create_grid(&(data));
	mlx_hook(data.win, 2, 1L << 0, key_manager, &data);
	mlx_loop(data.mlx);
}

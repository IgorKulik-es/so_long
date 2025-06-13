/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:21:35 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/13 20:26:44 by ikulik           ###   ########.fr       */
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
	t_mlx_data	mlx_data;
	int			width;
	int			height;
	t_map_data	map;

	initialize_map(&map);
	map.width = 5;
	map.height = 5;
/*	read_map(&map, argc, argv);
	check_map_basics(&map);
	print_map(map.map, map.height); */
	if (argc)
		argv[0][0] = argv[0][0];
	mlx_data.mlx = mlx_init();
	mlx_data.img = mlx_xpm_file_to_image(mlx_data.mlx, "./img/JarJarBinks.xpm", &width, &height);
	mlx_data.img1 = mlx_xpm_file_to_image(mlx_data.mlx, "./img/Booma.xpm", &width, &height);
	if (mlx_data.img == NULL)
		printf("Image reading failed\n");
	else
		printf("Image size %d x %d\n", width, height);
	mlx_data.win = mlx_new_window(mlx_data.mlx, 1920, 1080, "Hello world!");
	create_grid(&map, &mlx_data);
	mlx_hook(mlx_data.win, 2, 1L << 0, close_window, &mlx_data);
	mlx_loop(mlx_data.mlx);
}

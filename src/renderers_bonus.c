/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderers_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:48:19 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/20 19:36:27 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	*stretch_anim(t_mlx_data *data, void *src, int width, int start)
{
	void			*img;
	double			factor;
	unsigned int	*pixels[2];
	int				i;
	int				j;

	if (src == NULL)
		return (NULL);
	factor = (double)data->map.c_size / (double)AN_HEIGHT;
	img = mlx_new_image(data->mlx, data->map.c_size, data->map.c_size);
	pixels[0] = (unsigned int *)mlx_get_data_addr(img, &i, &i, &i);
	pixels[1] = (unsigned int *)mlx_get_data_addr(src, &i, &i, &i);
	i = 0;
	while (i < data->map.c_size)
	{
		j = 0;
		while (j < data->map.c_size)
		{
			pixels[0][i * data->map.c_size + j] = pixels[1][((int)((double)i
						/ factor)) * width + (int)((double)j / factor) + start];
			j++;
		}
		i++;
	}
	return (img);
}

void	*stretch_banners(t_mlx_data *data, int start)
{
	void			*img;
	unsigned int	*pixels[2];
	int				i;
	int				j;

	img = mlx_new_image(data->mlx, NUM_WIDTH, TXT_HEIGHT);
	pixels[0] = (unsigned int *)mlx_get_data_addr(img, &i, &i, &i);
	pixels[1] = (unsigned int *)mlx_get_data_addr(data->txt_nums[10],
			&i, &i, &i);
	i = 0;
	while (i < TXT_HEIGHT)
	{
		j = 0;
		while (j < NUM_WIDTH)
		{
			pixels[0][i * NUM_WIDTH + j] = pixels[1][i * TXT_WIDTH + j + start];
			j++;
		}
		i++;
	}
	return (img);
}

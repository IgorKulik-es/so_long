/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:53:10 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/14 17:30:04 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include "./minilibx-linux/mlx.h"

# define TOTAL 1
# define PARTIAL 0
# define MAP_ERROR 2
# define WALL '1'
# define EMPTY '0'
# define COLLECT 'C'
# define DOOR 'E'
# define PLAYER 'P'
# define UP 'w'
# define DOWN 's'
# define LEFT 'a'
# define RIGHT 'd'
# define ESC 65307
# define ESC_ASCII 33
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define DF_CELL 300
# define TOP_OFF 100
# define SIDE_OFF 100
# define C_GOLD 16761104
# define C_GREEN 8439808
# define C_VIOLET 9055202
# define C_CRIMSON 14423100
# define C_GREY 3100495

typedef struct s_coordinates
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_list
{
	char			*line;
	t_pos			pos;
	struct s_list	*next;
	struct s_list	*prev;
}			t_list;

typedef struct s_map_data
{
	int		width;
	int		height;
	int		num_cols;
	int		c_size;
	int		moves;
	char	**map;
	char	**map_copy;
	t_list	*read_lst;
	t_list	*cols;
	t_pos	player;
	t_pos	door;
	t_pos	offs;
}			t_map_data;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	void		*wall;
	void		*empty;
	void		*coll;
	void		*door;
	void		*player;
	t_map_data	map;
}		t_mlx_data;

int		ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_putnbr_fd(int n, int fd);
char	*ft_strdup(const char *s, t_map_data *map);
t_list	*lst_push_back(t_map_data *map, t_list **lst, char *line, t_pos *pos);
void	clean_exit(t_map_data *map, char *error, int exit_code);
char	*get_next_line(int fd);
void	lst_clear(t_list **lst, int mode);
int		key_manager(int key, t_mlx_data *data);
void	close_window(t_mlx_data *data);
void	array_clear(char **arr, int size);
void	initialize_map(t_map_data *map);
int		read_map(t_map_data *map, int argc, char **argv);
void	check_map_basics(t_map_data *map);
void	check_map_advanced(t_map_data *map);
void	register_collectables(t_map_data *map);
int		search_route(t_map_data *map, int x, int y);
void	validate_map(t_map_data *map, int argc, char **argv);
void	create_grid(t_mlx_data *mlx);
void	asign_basic_colors(t_mlx_data *data);
void	put_image_from_grid(t_mlx_data *data, int x, int y);
void	*stretch_to_fit(t_mlx_data *data, void *src);

#endif

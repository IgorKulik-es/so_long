/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikulik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 19:53:10 by ikulik            #+#    #+#             */
/*   Updated: 2025/06/20 20:05:57 by ikulik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <sys/time.h>
# include <time.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"

# define TOTAL 1
# define PARTIAL 0
# define MAP_ERROR 2
# define WALL '1'
# define EMPTY '0'
# define COLLECT 'C'
# define DOOR 'E'
# define PLAYER 'P'
# define ENEMY 'S'
# define UP 'w'
# define DOWN 's'
# define LEFT 'a'
# define RIGHT 'd'
# define ESC XK_Escape
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define DF_CELL 32
# define TOP_OFF 100
# define SIDE_OFF 100
# define C_BACKGR 0x181a31
# define AN_HEIGHT 38
# define AN_IDLE_W 266
# define AN_WALK_W 304
# define NUM_WIDTH 63
# define TXT_HEIGHT 114
# define TXT_WIDTH 630
# define TXT_MOVES 357
# define GM_OVR_WIDTH 1080
# define GM_OVR_HEIGHT 195
# define AN_DELAY 130000
# define AN_WALK 400000
# define AN_DEATH 130000
# define AN_ATTACK 200000
# define FR_IDLE 7
# define FR_WALK 8
# define FR_ACT 12
# define EN_IDLE 4
# define EN_WALK 7
# define EN_ACT 4
# define EN_DENSITY 20
# define FORWARD 1
# define REVERSE 0
# define CLEAN 2
# define NUMBERS 3

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
	int		num_empty;
	int		num_enem;
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
typedef struct s_anim_imgs
{
	void		*idle_left[FR_IDLE + 1];
	void		*idle_right[FR_IDLE + 1];
	void		*walk_left[FR_WALK + 1];
	void		*walk_right[FR_WALK + 1];
	void		*act_left[FR_ACT + 1];
	void		*act_right[FR_ACT + 1];
	t_pos		pos;
	t_pos		dest;
	size_t		time;
	int			moving;
	int			acting;
	int			step;
	int			facing;
	int			idl_frame;
}		t_anim;

typedef struct s_mlx_data
{
	void		*mlx;
	void		*win;
	void		*wall;
	void		*wall_d;
	void		*empty;
	void		*coll;
	void		*door;
	void		*player;
	void		*txt_moves;
	void		*txt_nums[11];
	void		*txt_go;
	void		*txt_win;
	int			game_over;
	t_anim		anim;
	t_anim		enem_base;
	t_anim		*enemies;
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
int		close_window(t_mlx_data *data);
void	array_clear(char **arr, int size);
void	initialize_map(t_map_data *map);
void	add_images(t_mlx_data *data);
int		read_map(t_map_data *map, int argc, char **argv);
void	check_map_basics(t_map_data *map);
void	check_map_advanced(t_map_data *map);
void	register_collectables(t_map_data *map);
void	create_background(t_mlx_data *data);
int		search_route(t_map_data *map, int x, int y);
void	validate_map(t_map_data *map, int argc, char **argv);
void	create_grid(t_mlx_data *mlx);
void	put_image_to_grid(t_mlx_data *data, void *img, int x, int y);
void	*stretch_to_fit(t_mlx_data *data, void *src, int width, int start);
void	*stretch_anim(t_mlx_data *data, void *src, int width, int start);
void	clean_anims(t_mlx_data *data);
void	load_anim_src(t_mlx_data *data);
void	create_frames(t_mlx_data *data);
int		idle_all(t_mlx_data *data);
void	spawn_enemies(t_mlx_data *data, t_map_data *map);
void	initialize_enemies(t_mlx_data *data);
int		key_manager_plus(int key, t_mlx_data *data);
void	animate_act(t_mlx_data *data, t_anim *entity, int num_fr, size_t speed);
t_anim	*find_enemy(t_mlx_data *data, t_pos find);
void	set_frames(t_mlx_data *data, void **anims, int num_frames, int mode);
void	*stretch_banners(t_mlx_data *data, int start);
void	put_count(t_mlx_data *data);

#endif

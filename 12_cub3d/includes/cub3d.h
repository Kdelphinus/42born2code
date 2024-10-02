#ifndef CUB3D_H
# define CUB3D_H

# include "../mlx/mlx.h"
# include "../lib/libft.h"
# include "../gnl/get_next_line.h"
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define FAILE				0
# define SUCCESS			1
# define FALSE				0
# define TRUE				1
# define SCREENWIDTH		1680
# define SCREENHEIGHT		1050
# define X					0
# define Y					1
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17
# define KEY_LEFT			123
# define KEY_RIGHT			124
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ESC			53
# define IMG_H				64
# define IMG_W				64

typedef enum e_errno {
	NOWALL,
	WRONGDATA,
	NOFILE,
	WRONGFILE,
	WRONGARG
}	t_errno;

typedef enum e_dir {
	NO = 0,
	SO,
	WE,
	EA
}	t_dir;

typedef struct s_obj
{
	int	p_cnt;
	int	w;
	int	h;
}	t_obj;

typedef struct s_mapping
{
	char				*line;
	int					line_len;
	struct s_mapping	*next;
}	t_mapping;

typedef struct s_texture
{
	void				*img;
	char				*path;
	int					img_w;
	int					img_h;
}	t_texture;

typedef struct s_map_data {
	char		**map;
	int			flr_color;
	int			ceil_color;
	int			flr_count;
	int			ceil_count;
	t_texture	*textures;
}	t_map_data;

typedef struct s_ray
{
	double	pos[2];
	double	dir[2];
	double	plane[2];
	double	camera_x;
	double	ray_dir[2];
	int		map[2];
	double	side_dist[2];
	double	delta_dist[2];
	double	perp_wall_dist;
	int		step[2];
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_num;
	int		tex[2];
	double	step_d;
	double	tex_pos;
	double	wall_x;
	double	frame_time;
	double	move_speed;
	double	rot_speed;
}	t_ray;

typedef struct s_img
{
	void	*img_ptr;
	int		*data;
	int		size_l;
	int		bpp;
	int		endian;
}	t_img;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_map_data	map;
	t_ray		*ray;
	t_img		*img;
}	t_game;

typedef struct s_game_info {
	void		*mlx;
	void		*win;
	int			stop_flag;
	t_ray		*ray;
	t_img		*img;
	t_map_data	*map_data;
}	t_game_info;

int			key_press(int keycode, t_game_info *game_info);

//initailize
void		parsing(t_game_info *info, char *map_file);
void		info_init(t_game_info *info, t_obj *obj);
void		img_init(t_game_info *game_info);
void		ray_init(t_ray *ray);

//check
void		check_texture(char *line, t_game_info *info);
void		check_extension(char *file_name);
int			check_tmp_invalid(t_game_info *info, char *line, char **tmp);
void		check_object_map(char **map, t_obj *obj, int x, int y);

//read
void		read_map(t_game_info *info, t_obj *obj, t_mapping *tmp, int i);

//mapping allowcate
void		allocate_dir(char **data, t_game_info *info, t_dir dir);
void		allocate_flr(char **data, t_game_info *info);
void		allocate_ceil(char **data, t_game_info *info);

//struct linked list utils
t_mapping	*new_mapping(char *line, t_obj *obj, t_game_info *info);
void		add_mapping_node(t_mapping **list, t_mapping *new_node);

//utils
void		print_err_exit(int errno);
void		free_data(char **data);

//raycast
void		ray_cast(t_ray *ray, t_game_info *game_info);

//render
void		window_init(t_map_data *map_data, t_img *img);
void		choice_tex(t_ray *ray);
void		put_color(int x, t_ray *ray, t_texture \
*texture, t_game_info *game_info);

//key press
void		key_rotate(int keycode, t_ray *ray);
void		move_side(int keycode, t_ray *ray, char **map);
void		key_move(int keycode, t_ray *ray, char **map);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:36:57 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:37:55 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../../libs/mlx/mlx.h"
# include "../../libs/libft/libft.h"
# include "../../libs/gnl/get_next_line.h"
# include <math.h>
# include <fcntl.h>

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17

/****------------ enum ------------****/
enum	e_error
{
	NO_ERROR,
	ERROR_ARG_NBR,
	ERROR_FILE_TYPE,
	ERROR_MAP_NOT_EXIST,
	ERROR_MISSING_FILE,
	ERROR_MAP_NO_RECT,
	ERROR_MAP_CHAR_NO_VALID,
	ERROR_MAP_NO_PLAYER,
	ERROR_WARNING_PLAYER,
	ERROR_MAP_NO_ITEM,
	ERROR_MAP_NO_EXIT,
	ERROR_MAP_WALL
};

enum	e_type_obj
{
	WALL='1',
	GROUND='0',
	ITEM='C',
	DOOR='E',
	PLAYER='P',
	ENEMY='K'
};

enum	e_key
{
	touch_w=13,
	touch_d=2,
	touch_a=0,
	touch_s=1,
	touch_up=126,
	touch_down=125,
	touch_left=123,
	touch_right=124,
	touch_esc=53
};

/****----------- struct -----------****/
typedef struct s_map
{
	char			*tile;
	int				bool;
	int				lenx;
	int				leny;
}			t_map;

typedef struct s_tools
{
	int				posx;
	int				posy;
	int				x;
	int				y;
	int				index;
}			t_tools;

typedef struct s_png
{
	int		w;
	int		h;
	void	*img;
	char	path[255];
}				t_png;
typedef struct s_player
{
	int		posx;
	int		posy;
	int		posi;
	int		countmove;
	t_png	png;
}				t_player;
typedef struct s_data
{
	void			*mlx;
	void			*windows;
	void			*img;
	int				img_width;
	int				img_height;
	int				bits_per_pixel;
	int				line_length;
	char			*line;
	int				endian;
	t_player		player;
	t_player		enemy;
	int				sizetile;
	t_png			item;
	t_png			door;
	t_png			ground;
	t_png			wall;
	t_map			map;
	t_tools			tools;
	enum e_error	error;
}				t_data;

/******----------------- intialise img ----------------------******/

void	define_all_png_to_image(t_data *game);

/******------------------ parsing ------------------------******/

int		parsing_map(t_data	*game, char *pathfile);

int		check_minimum_required(t_data *game);
int		check_wall_close_map(t_data *game, int i);
int		check_chars_is_valid(t_data *game);

/******-------------- manage open file -------------------******/

int		ft_open_file(char *path, t_data *game);
int		put_good_img_debug(t_data *game, char *line);

/******--------------- manage error --------------------******/

int		write_error_type(t_data *game);
int		check_type_file(char *str, char *filetype);
int		check_norm_arg_is_ok(int ac, char *str, t_data *game);

/******------------------- utils ---------------------******/

int		ft_str_search_char(char *str, char c);
int		exit_normal(t_data *game);

/******-------------- image management --------------******/

int		push_tile_to_win(t_data *game);

/******-------------- hook management ---------------******/

int		key_hook(int keycode, t_data *game);

/******------------------ mlx path ------------------******/

void	patch_mlx(t_data *game);

/******------------------ bonus ------------------******/

void	put_counter_in_windows(t_data *game, char *str);
int		exit_gameover(t_data *game);

#endif

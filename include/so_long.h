/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:01:37 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/24 12:06:28 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

# define WIDTH 600
# define HEIGHT 600
# define ITER_MAX 60

/*KEYCODES*/
# define ESC 65307

# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361

# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_A 97

/*IMAGES USED*/
# define PLAYERDOWN "./ressources/player/idle/down/player-idle-0-1.xpm"
# define PLAYERRIGHT "./ressources/player/idle/right/player-idle-1-1.xpm"
# define PLAYERUP "./ressources/player/idle/up/player-idle-2-1.xpm"
# define PLAYERLEFT "./ressources/player/idle/left/player-idle-3-1.xpm"

# define EXIT "./ressources/exit/exit.xpm"
# define EXITLADDER "./ressources/exit/exit_ladder.xpm"

# define MIDWALL "./ressources/wall/mid_wall.xpm"
# define MIDWALLCOL "./ressources/wall/top_wall_collied.xpm"

# define LEFTWALL "./ressources/wall/left_wall_1.xpm"
# define RIGHTWALL "./ressources/wall/right_wall_1.xpm"

# define CORNERWALLLEFT "./ressources/wall/corner_wall_left.xpm"
# define CORNERWALLRIGHT "./ressources/wall/corner_wall_right.xpm"

# define BOTWALL "./ressources/wall/bot_wall_1.xpm"
# define BOTWALLLEFT "./ressources/wall/bot_wall_left.xpm"
# define BOTWALLRIGHT "./ressources/wall/bot_wall_right.xpm"

# define TOPWALL "./ressources/wall/top_wall_1.xpm"
# define TOPWALLLEFT "./ressources/wall/top_wall_left.xpm"
# define TOPWALLRIGHT "./ressources/wall/top_wall_right.xpm"

# define FLOOR "./ressources/floor.xpm"

# define COIN "./ressources/coin/coin.xpm"

enum				e_errors
{
	SUCCESS,
	FAILURE,
	NOTBER,
	SCREENTOOBIG,
	FILENOTFOUND,
	CHARERROR,
	EMPTYLINE,
	MISSING,
	TOOMANY,
	NOTRECT,
	NOTBORDERED,
	NOVALIDPATH
};

typedef struct s_img
{
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				height;
	int				width;
}					t_img;

typedef struct s_exit
{
	struct s_img	*imgs[2];
	unsigned int	x;
	unsigned int	y;
}					t_exit;

typedef struct s_player
{
	struct s_img	*imgs[4];
	unsigned int	x;
	unsigned int	y;
	unsigned int	collected;
}					t_player;

typedef struct s_data
{
	struct s_img	*wall[8];
	struct s_img	*floor;
	struct s_img	*collect;
	struct s_player	*player;
	struct s_exit	*exit;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				height;
	int				width;
	unsigned int	nb_collectable;
	unsigned int	nb_pas;
}					t_data;

/*UTILS*/
int					on_destroy(t_data *data);
int					on_keypress(int keysym, t_data *data);
int					on_keyrelease(int keysym, t_data *data);
void				refresh_map(t_data *data, int key);
void				free_tab_str(char **str);
void				free_visited_map(char **map, int height);
bool				is_valid_path(t_data *data, char **visited, int x, int y);
char				**init_visited_map(t_data *data);
void				get_player_pos(t_data *data, int pos[2]);

/*DESTROY IMAGES*/

void				destroy_free_walls(t_data *data);
void				destroy_free_exit(t_data *data);
void				destroy_free_player(t_data *data);

/*ERROR GESTION*/
void				exit_error(int error);
int					on_destroy(t_data *data);

/*PARSING*/
void				check_chars(t_data *data);
int					right_line(char *line);
void				get_height_width(t_data *data, char *map[]);
void				check_valid_map(t_data *data, char *path);

/*INIT THE MINILIB*/
int					init_minilib(t_data *data);

/*SET IMAGES*/
void				set_img(t_data *data);

/*PRINT IMAGES*/
void				print_walls(t_data *data, int y, int x);
void				print_player(t_data *data, int key, int i, int j);

/*FILL IMAGE*/
void				init_images(t_data *data);
void				print_all_images(t_data *data);
void				re_print_all_images(t_data *data, int key);

#endif
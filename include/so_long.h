/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:01:37 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/26 16:20:25 by sgabsi           ###   ########.fr       */
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

/*SOME MESSAGES*/

# define YOU_WIN "#                                                                                                                                          \n\
#                                                                                                                                                            \n\
#  YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN      !!!  \n\
#  Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N     !!:!! \n\
#  Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N     !:::! \n\
#  Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N     !:::! \n\
#  YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N     !:::! \n\
#     Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N     !:::! \n\
#      Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N     !:::! \n\
#       Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N     !:::! \n\
#        Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N     !:::! \n\
#         Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N     !:::! \n\
#         Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N     !!:!! \n\
#         Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N      !!!  \n\
#         Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N           \n\
#      YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N      !!!  \n\
#      Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N     !!:!! \n\
#      YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN      !!!  \n\
#                                                                                                                                                            \n\
#                                                                                                                                                            \n\
#                                                                                                                                                            \n\
#                                                                                                                                                            \n\
#                                                                                                                                                            \n\
#                                                                                                                                                            \n\
#                                                                                                                                                            \n\
"
# define YOU_LOOSE "#                                                                                                                                                                  \n\
#                                                                                                                                                                                      \n\
#  YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     LLLLLLLLLLL                  OOOOOOOOO          OOOOOOOOO        SSSSSSSSSSSSSSS EEEEEEEEEEEEEEEEEEEEEE      !!!  \n\
#  Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     L:::::::::L                OO:::::::::OO      OO:::::::::OO    SS:::::::::::::::SE::::::::::::::::::::E     !!:!! \n\
#  Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     L:::::::::L              OO:::::::::::::OO  OO:::::::::::::OO S:::::SSSSSS::::::SE::::::::::::::::::::E     !:::! \n\
#  Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     LL:::::::LL             O:::::::OOO:::::::OO:::::::OOO:::::::OS:::::S     SSSSSSSEE::::::EEEEEEEEE::::E     !:::! \n\
#  YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U        L:::::L               O::::::O   O::::::OO::::::O   O::::::OS:::::S              E:::::E       EEEEEE     !:::! \n\
#     Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::OO:::::O     O:::::OS:::::S              E:::::E                  !:::! \n\
#      Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::OO:::::O     O:::::O S::::SSSS           E::::::EEEEEEEEEE        !:::! \n\
#       Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::OO:::::O     O:::::O  SS::::::SSSSS      E:::::::::::::::E        !:::! \n\
#        Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::OO:::::O     O:::::O    SSS::::::::SS    E:::::::::::::::E        !:::! \n\
#         Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::OO:::::O     O:::::O       SSSSSS::::S   E::::::EEEEEEEEEE        !:::! \n\
#         Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::OO:::::O     O:::::O            S:::::S  E:::::E                  !!:!! \n\
#         Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U        L:::::L         LLLLLLO::::::O   O::::::OO::::::O   O::::::O            S:::::S  E:::::E       EEEEEE      !!!  \n\
#         Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U      LL:::::::LLLLLLLLL:::::LO:::::::OOO:::::::OO:::::::OOO:::::::OSSSSSSS     S:::::SEE::::::EEEEEEEE:::::E           \n\
#      YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU       L::::::::::::::::::::::L OO:::::::::::::OO  OO:::::::::::::OO S::::::SSSSSS:::::SE::::::::::::::::::::E      !!!  \n\
#      Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU         L::::::::::::::::::::::L   OO:::::::::OO      OO:::::::::OO   S:::::::::::::::SS E::::::::::::::::::::E     !!:!! \n\
#      YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU           LLLLLLLLLLLLLLLLLLLLLLLL     OOOOOOOOO          OOOOOOOOO      SSSSSSSSSSSSSSS   EEEEEEEEEEEEEEEEEEEEEE      !!!  \n\
#                                                                                                                                                                                      \n\
#                                                                                                                                                                                      \n\
#                                                                                                                                                                                      \n\
#                                                                                                                                                                                      \n\
#                                                                                                                                                                                      \n\
#                                                                                                                                                                                      \n\
#                                                                                                                                                                                      \n\
"

/*IMAGES USED*/

/*ALL FRAME PLAYER DOWN*/
/*IDLE*/
# define PLAYERDOWN "./ressources/player/idle/down/player-idle-0-1.xpm"
# define PLAYERDOWN1 "./ressources/player/idle/down/player-idle-0-2.xpm"
# define PLAYERDOWN2 "./ressources/player/idle/down/player-idle-0-3.xpm"
# define PLAYERDOWN3 "./ressources/player/idle/down/player-idle-0-4.xpm"
# define PLAYERDOWN4 "./ressources/player/idle/down/player-idle-0-5.xpm"
# define PLAYERDOWN5 "./ressources/player/idle/down/player-idle-0-6.xpm"
# define PLAYERDOWN6 "./ressources/player/idle/down/player-idle-0-7.xpm"
# define PLAYERDOWN7 "./ressources/player/idle/down/player-idle-0-8.xpm"
/*RUN*/
# define PLAYERDOWNRUN "./ressources/player/run/down/player-run-0-1.xpm"
# define PLAYERDOWNRUN1 "./ressources/player/run/down/player-run-0-2.xpm"
# define PLAYERDOWNRUN2 "./ressources/player/run/down/player-run-0-3.xpm"
# define PLAYERDOWNRUN3 "./ressources/player/run/down/player-run-0-4.xpm"
# define PLAYERDOWNRUN4 "./ressources/player/run/down/player-run-0-5.xpm"
# define PLAYERDOWNRUN5 "./ressources/player/run/down/player-run-0-6.xpm"
# define PLAYERDOWNRUN6 "./ressources/player/run/down/player-run-0-7.xpm"
# define PLAYERDOWNRUN7 "./ressources/player/run/down/player-run-0-8.xpm"

/*ALL FRAME PLAYER RIGHT*/
# define PLAYERRIGHT "./ressources/player/idle/right/player-idle-1-1.xpm"
# define PLAYERRIGHT1 "./ressources/player/idle/right/player-idle-1-2.xpm"
# define PLAYERRIGHT2 "./ressources/player/idle/right/player-idle-1-3.xpm"
# define PLAYERRIGHT3 "./ressources/player/idle/right/player-idle-1-4.xpm"
# define PLAYERRIGHT4 "./ressources/player/idle/right/player-idle-1-5.xpm"
# define PLAYERRIGHT5 "./ressources/player/idle/right/player-idle-1-6.xpm"
# define PLAYERRIGHT6 "./ressources/player/idle/right/player-idle-1-7.xpm"
# define PLAYERRIGHT7 "./ressources/player/idle/right/player-idle-1-8.xpm"

/*ALL FRAME PLAYER UP*/
# define PLAYERUP "./ressources/player/idle/up/player-idle-2-1.xpm"
# define PLAYERUP1 "./ressources/player/idle/up/player-idle-2-2.xpm"
# define PLAYERUP2 "./ressources/player/idle/up/player-idle-2-3.xpm"
# define PLAYERUP3 "./ressources/player/idle/up/player-idle-2-4.xpm"
# define PLAYERUP4 "./ressources/player/idle/up/player-idle-2-5.xpm"
# define PLAYERUP5 "./ressources/player/idle/up/player-idle-2-6.xpm"
# define PLAYERUP6 "./ressources/player/idle/up/player-idle-2-7.xpm"
# define PLAYERUP7 "./ressources/player/idle/up/player-idle-2-8.xpm"

/*ALL FRAME PLAYER LEFT*/
# define PLAYERLEFT "./ressources/player/idle/left/player-idle-3-1.xpm"
# define PLAYERLEFT1 "./ressources/player/idle/left/player-idle-3-2.xpm"
# define PLAYERLEFT2 "./ressources/player/idle/left/player-idle-3-3.xpm"
# define PLAYERLEFT3 "./ressources/player/idle/left/player-idle-3-4.xpm"
# define PLAYERLEFT4 "./ressources/player/idle/left/player-idle-3-5.xpm"
# define PLAYERLEFT5 "./ressources/player/idle/left/player-idle-3-6.xpm"
# define PLAYERLEFT6 "./ressources/player/idle/left/player-idle-3-7.xpm"
# define PLAYERLEFT7 "./ressources/player/idle/left/player-idle-3-8.xpm"

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
# define COIN1 "./ressources/coin/coin-1.xpm"
# define COIN2 "./ressources/coin/coin-2.xpm"
# define COIN3 "./ressources/coin/coin-3.xpm"

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

enum e_direction
{
	SUD,
	EST,
	NORD,
	OUEST
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
	struct s_img	*idle[4][8];
	struct s_img	*run[4][8];
	unsigned int	x;
	unsigned int	y;
	unsigned int	collected;
	int				direction;
	int				old_direction;
}					t_player;

typedef struct s_data
{
	struct s_player	*player;
	struct s_exit	*exit;
	struct s_img	*wall[8];
	struct s_img	*floor;
	struct s_img	*collect[4];
	unsigned int	nb_collectable;
	unsigned int	nb_pas;
	void			*mlx_ptr;
	void			*win_ptr;
	char			**map;
	int				height;
	int				width;
	int				rate;
	int				frame;
	int				frame_collec;
	int				frame_run;
}					t_data;

/*UTILS*/
int					on_destroy(t_data *data);
int					on_keypress(int keysym, t_data *data);
int					on_keyrelease(int keysym, t_data *data);
int					on_refresh(t_data *data);
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
void				destroy_free_collect(t_data *data);

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
void				set_player_down(t_data *data);
void				set_player_left(t_data *data);
void				set_player_right(t_data *data);
void				set_player_up(t_data *data);
void				*set_image(t_data *data, char *path, int height, int width);
void				set_img(t_data *data);

/*PRINT IMAGES*/
void				print_walls(t_data *data, int y, int x);
void				print_player(t_data *data, int key, int i, int j);
void				print_image(t_data *data, void *img, int i, int j);

/*FILL IMAGE*/
void				init_screen(t_data *data);
void				init_images(t_data *data);
void				re_print_image(t_data *data, int key, int i, int j);

/*ANIMATIONS*/
void				animate_player(t_data *data);
void				animate_exit(t_data *data);
void				animate_collect(t_data *data);

#endif
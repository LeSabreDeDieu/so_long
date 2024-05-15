/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 14:01:37 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/15 16:52:39 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

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

# define YOU_WIN "\n\
YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     WWWWWWWW                           WWWWWWWWIIIIIIIIIINNNNNNNN        NNNNNNNN      !!!  \n\
Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN:::::::N       N::::::N     !!:!! \n\
Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     W::::::W                           W::::::WI::::::::IN::::::::N      N::::::N     !:::! \n\
Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     W::::::W                           W::::::WII::::::IIN:::::::::N     N::::::N     !:::! \n\
YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U       W:::::W           WWWWW           W:::::W   I::::I  N::::::::::N    N::::::N     !:::! \n\
   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        W:::::W         W:::::W         W:::::W    I::::I  N:::::::::::N   N::::::N     !:::! \n\
    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U         W:::::W       W:::::::W       W:::::W     I::::I  N:::::::N::::N  N::::::N     !:::! \n\
     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U          W:::::W     W:::::::::W     W:::::W      I::::I  N::::::N N::::N N::::::N     !:::! \n\
      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U           W:::::W   W:::::W:::::W   W:::::W       I::::I  N::::::N  N::::N:::::::N     !:::! \n\
       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U            W:::::W W:::::W W:::::W W:::::W        I::::I  N::::::N   N:::::::::::N     !:::! \n\
       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U             W:::::W:::::W   W:::::W:::::W         I::::I  N::::::N    N::::::::::N     !!:!! \n\
       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U              W:::::::::W     W:::::::::W          I::::I  N::::::N     N:::::::::N      !!!  \n\
       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U               W:::::::W       W:::::::W         II::::::IIN::::::N      N::::::::N           \n\
    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU                 W:::::W         W:::::W          I::::::::IN::::::N       N:::::::N      !!!  \n\
    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU                    W:::W           W:::W           I::::::::IN::::::N        N::::::N     !!:!! \n\
    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU                       WWW             WWW            IIIIIIIIIINNNNNNNN         NNNNNNN      !!!  \n\
"

# define YOU_LOSE "\n\
YYYYYYY       YYYYYYY     OOOOOOOOO     UUUUUUUU     UUUUUUUU     LLLLLLLLLLL                  OOOOOOOOO        SSSSSSSSSSSSSSS EEEEEEEEEEEEEEEEEEEEEE      !!!  \n\
Y:::::Y       Y:::::Y   OO:::::::::OO   U::::::U     U::::::U     L:::::::::L                OO:::::::::OO    SS:::::::::::::::SE::::::::::::::::::::E     !!:!! \n\
Y:::::Y       Y:::::Y OO:::::::::::::OO U::::::U     U::::::U     L:::::::::L              OO:::::::::::::OO S:::::SSSSSS::::::SE::::::::::::::::::::E     !:::! \n\
Y::::::Y     Y::::::YO:::::::OOO:::::::OUU:::::U     U:::::UU     LL:::::::LL             O:::::::OOO:::::::OS:::::S     SSSSSSSEE::::::EEEEEEEEE::::E     !:::! \n\
YYY:::::Y   Y:::::YYYO::::::O   O::::::O U:::::U     U:::::U        L:::::L               O::::::O   O::::::OS:::::S              E:::::E       EEEEEE     !:::! \n\
   Y:::::Y Y:::::Y   O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::OS:::::S              E:::::E                  !:::! \n\
    Y:::::Y:::::Y    O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O S::::SSSS           E::::::EEEEEEEEEE        !:::! \n\
     Y:::::::::Y     O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O  SS::::::SSSSS      E:::::::::::::::E        !:::! \n\
      Y:::::::Y      O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O    SSS::::::::SS    E:::::::::::::::E        !:::! \n\
       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O       SSSSSS::::S   E::::::EEEEEEEEEE        !:::! \n\
       Y:::::Y       O:::::O     O:::::O U:::::D     D:::::U        L:::::L               O:::::O     O:::::O            S:::::S  E:::::E                  !!:!! \n\
       Y:::::Y       O::::::O   O::::::O U::::::U   U::::::U        L:::::L         LLLLLLO::::::O   O::::::O            S:::::S  E:::::E       EEEEEE      !!!  \n\
       Y:::::Y       O:::::::OOO:::::::O U:::::::UUU:::::::U      LL:::::::LLLLLLLLL:::::LO:::::::OOO:::::::OSSSSSSS     S:::::SEE::::::EEEEEEEE:::::E           \n\
    YYYY:::::YYYY     OO:::::::::::::OO   UU:::::::::::::UU       L::::::::::::::::::::::L OO:::::::::::::OO S::::::SSSSSS:::::SE::::::::::::::::::::E      !!!  \n\
    Y:::::::::::Y       OO:::::::::OO       UU:::::::::UU         L::::::::::::::::::::::L   OO:::::::::OO   S:::::::::::::::SS E::::::::::::::::::::E     !!:!! \n\
    YYYYYYYYYYYYY         OOOOOOOOO           UUUUUUUUU           LLLLLLLLLLLLLLLLLLLLLLLL     OOOOOOOOO      SSSSSSSSSSSSSSS   EEEEEEEEEEEEEEEEEEEEEE      !!!  \n\
"

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
	OUEST,
	NORD,
	EST
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

typedef struct s_pos
{
	unsigned int	x;
	unsigned int	y;
}					t_pos;

typedef struct s_exit
{
	t_img			*imgs[2];
	t_pos			*pos;
}					t_exit;

typedef struct s_player
{
	t_img			*idle[4][8];
	t_img			*run[4][8];
	t_pos			*pos;
	unsigned int	collected;
	int				direction;
	int				old_direction;
}					t_player;

typedef struct s_data
{
	t_player		*player;
	t_exit			*exit;
	t_img			*mob[4][4];
	t_img			*wall[8];
	t_img			*collect[4];
	t_img			*floor;
	t_img			*heart[2];
	t_img			*numbers[10];
	char			**map;
	int				*mob_direction;
	void			*mlx_ptr;
	void			*win_ptr[2];
	unsigned int	nb_mobs;
	unsigned int	nb_collectable;
	unsigned int	nb_pas;
	unsigned int	frame_collec;
	unsigned int	frame_run;
	int				frame;
	int				height;
	int				width;
	int				rate;
	int				dead;
}					t_data;

/*UTILS*/
int					on_destroy(t_data *data);
int					on_keypress(int keysym, t_data *data);
int					on_keyrelease(int keysym, t_data *data);
int					on_refresh(t_data *data);
void				refresh_map_player(t_data *data, int key);
void				free_tab_str(char **str);
void				free_visited_map(char **map, int height);
int					is_valid_path(t_data *data, char **visited, int x, int y);
char				**init_visited_map(t_data *data);
void				get_player_pos(t_data *data, int pos[2]);
void				char_counter(t_data *data, int counter[4], int i, int j);
void				mob_mouv(t_data *data);
void				set_image_numbers(t_img *numbers, t_img *bot_wall);

/*DESTROY IMAGES*/

void				destroy_free_walls(t_data *data);
void				destroy_free_exit(t_data *data);
void				destroy_free_player(t_data *data);
void				destroy_free_enemy(t_data *data);
void				destroy_free_collect(t_data *data);
void				destroy_free_numbers(t_data *data);

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
int					init_win_lose_win(t_data *data);

/*SET & LOAD IMAGES*/
void				load_image(t_data *data);
t_img				*set_image(t_data *data, char *path);

/*SET IMAGES*/
void				load_player_down(t_data *data);
void				load_player_left(t_data *data);
void				load_player_right(t_data *data);
void				load_player_up(t_data *data);
void				load_enemy(t_data *data);

/*PRINT IMAGES*/
void				print_heart(t_data *data);
void				print_step(t_data *data, int nb_step);
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
void				animate_mob(t_data *data);

/*MATH*/
int					rand_number(int min, int max);

#endif
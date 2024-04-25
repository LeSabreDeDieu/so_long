/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/25 15:04:19 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_right_2(t_data *data)
{
	data->player->imgs[1][4]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERRIGHT4, &data->player->imgs[1][4]->height,
			&data->player->imgs[1][4]->width);
	if (!data->player->imgs[1][4]->img)
		on_destroy(data);
	data->player->imgs[1][5]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERRIGHT5, &data->player->imgs[1][5]->height,
			&data->player->imgs[1][5]->width);
	if (!data->player->imgs[1][5]->img)
		on_destroy(data);
	data->player->imgs[1][6]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERRIGHT6, &data->player->imgs[1][6]->height,
			&data->player->imgs[1][6]->width);
	if (!data->player->imgs[1][6]->img)
		on_destroy(data);
	data->player->imgs[1][7]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERRIGHT7, &data->player->imgs[1][7]->height,
			&data->player->imgs[1][7]->width);
	if (!data->player->imgs[1][7]->img)
		on_destroy(data);
}

void	set_player_right(t_data *data)
{
	data->player->imgs[1][0]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERRIGHT, &data->player->imgs[1][0]->height,
			&data->player->imgs[1][0]->width);
	if (!data->player->imgs[1][0]->img)
		on_destroy(data);
	data->player->imgs[1][1]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERRIGHT1, &data->player->imgs[1][1]->height,
			&data->player->imgs[1][1]->width);
	if (!data->player->imgs[1][1]->img)
		on_destroy(data);
	data->player->imgs[1][2]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERRIGHT2, &data->player->imgs[1][2]->height,
			&data->player->imgs[1][2]->width);
	if (!data->player->imgs[1][2]->img)
		on_destroy(data);
	data->player->imgs[1][3]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERRIGHT3, &data->player->imgs[1][3]->height,
			&data->player->imgs[1][3]->width);
	if (!data->player->imgs[1][3]->img)
		on_destroy(data);
	set_player_right_2(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/25 15:04:26 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_up_2(t_data *data)
{
	data->player->imgs[2][4]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERUP4, &data->player->imgs[2][4]->height,
			&data->player->imgs[2][4]->width);
	if (!data->player->imgs[2][4]->img)
		on_destroy(data);
	data->player->imgs[2][5]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERUP5, &data->player->imgs[2][5]->height,
			&data->player->imgs[2][5]->width);
	if (!data->player->imgs[2][5]->img)
		on_destroy(data);
	data->player->imgs[2][6]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERUP6, &data->player->imgs[2][6]->height,
			&data->player->imgs[2][6]->width);
	if (!data->player->imgs[2][6]->img)
		on_destroy(data);
	data->player->imgs[2][7]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERUP7, &data->player->imgs[2][7]->height,
			&data->player->imgs[2][7]->width);
	if (!data->player->imgs[2][7]->img)
		on_destroy(data);
}

void	set_player_up(t_data *data)
{
	data->player->imgs[2][0]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERUP, &data->player->imgs[2][0]->height,
			&data->player->imgs[2][0]->width);
	if (!data->player->imgs[2][0]->img)
		on_destroy(data);
	data->player->imgs[2][1]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERUP1, &data->player->imgs[2][1]->height,
			&data->player->imgs[2][1]->width);
	if (!data->player->imgs[2][1]->img)
		on_destroy(data);
	data->player->imgs[2][2]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERUP2, &data->player->imgs[2][2]->height,
			&data->player->imgs[2][2]->width);
	if (!data->player->imgs[2][2]->img)
		on_destroy(data);
	data->player->imgs[2][3]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERUP3, &data->player->imgs[2][3]->height,
			&data->player->imgs[2][3]->width);
	if (!data->player->imgs[2][3]->img)
		on_destroy(data);
	set_player_up_2(data);
}

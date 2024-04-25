/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/25 15:04:31 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_left_2(t_data *data)
{
	data->player->imgs[3][4]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERLEFT4, &data->player->imgs[3][4]->height,
			&data->player->imgs[3][4]->width);
	if (!data->player->imgs[3][4]->img)
		on_destroy(data);
	data->player->imgs[3][5]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERLEFT5, &data->player->imgs[3][5]->height,
			&data->player->imgs[3][5]->width);
	if (!data->player->imgs[3][5]->img)
		on_destroy(data);
	data->player->imgs[3][6]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERLEFT6, &data->player->imgs[3][6]->height,
			&data->player->imgs[3][6]->width);
	if (!data->player->imgs[3][6]->img)
		on_destroy(data);
	data->player->imgs[3][7]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERLEFT7, &data->player->imgs[3][7]->height,
			&data->player->imgs[3][7]->width);
	if (!data->player->imgs[3][7]->img)
		on_destroy(data);
}

void	set_player_left(t_data *data)
{
	data->player->imgs[3][0]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERLEFT, &data->player->imgs[3][0]->height,
			&data->player->imgs[3][0]->width);
	if (!data->player->imgs[3][0]->img)
		on_destroy(data);
	data->player->imgs[3][1]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERLEFT1, &data->player->imgs[3][1]->height,
			&data->player->imgs[3][1]->width);
	if (!data->player->imgs[3][1]->img)
		on_destroy(data);
	data->player->imgs[3][2]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERLEFT2, &data->player->imgs[3][2]->height,
			&data->player->imgs[3][2]->width);
	if (!data->player->imgs[3][2]->img)
		on_destroy(data);
	data->player->imgs[3][3]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERLEFT3, &data->player->imgs[3][3]->height,
			&data->player->imgs[3][3]->width);
	if (!data->player->imgs[3][3]->img)
		on_destroy(data);
	set_player_left_2(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/25 14:53:44 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_down_2(t_data *data)
{
	data->player->imgs[0][4]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERDOWN4, &data->player->imgs[0][4]->height,
			&data->player->imgs[0][4]->width);
	if (!data->player->imgs[0][4]->img)
		on_destroy(data);
	data->player->imgs[0][5]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERDOWN5, &data->player->imgs[0][5]->height,
			&data->player->imgs[0][5]->width);
	if (!data->player->imgs[0][5]->img)
		on_destroy(data);
	data->player->imgs[0][6]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERDOWN6, &data->player->imgs[0][6]->height,
			&data->player->imgs[0][6]->width);
	if (!data->player->imgs[0][6]->img)
		on_destroy(data);
	data->player->imgs[0][7]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERDOWN7, &data->player->imgs[0][7]->height,
			&data->player->imgs[0][7]->width);
	if (!data->player->imgs[0][7]->img)
		on_destroy(data);
}

void	set_player_down(t_data *data)
{
	data->player->imgs[0][0]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERDOWN, &data->player->imgs[0][0]->height,
			&data->player->imgs[0][0]->width);
	if (!data->player->imgs[0][0]->img)
		on_destroy(data);
	data->player->imgs[0][1]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERDOWN1, &data->player->imgs[0][1]->height,
			&data->player->imgs[0][1]->width);
	if (!data->player->imgs[0][1]->img)
		on_destroy(data);
	data->player->imgs[0][2]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERDOWN2, &data->player->imgs[0][2]->height,
			&data->player->imgs[0][2]->width);
	if (!data->player->imgs[0][2]->img)
		on_destroy(data);
	data->player->imgs[0][3]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERDOWN3, &data->player->imgs[0][3]->height,
			&data->player->imgs[0][3]->width);
	if (!data->player->imgs[0][3]->img)
		on_destroy(data);
	set_player_down_2(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:34:15 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/25 16:41:08 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	destroy_free_walls(data);
	destroy_free_exit(data);
	destroy_free_player(data);
	destroy_free_collect(data);
	mlx_destroy_image(data->mlx_ptr, data->floor->img);
	free(data->floor);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_tab_str(data->map);
	free(data->mlx_ptr);
	exit(0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == ESC)
		on_destroy(data);
	data->player->old_direction = data->player->direction;
	if (keysym == KEY_W || keysym == KEY_UP)
	{
		data->player->direction = NORD;
		refresh_map(data, KEY_UP);
	}
	if (keysym == KEY_A || keysym == KEY_LEFT)
	{
		data->player->direction = OUEST;
		refresh_map(data, KEY_LEFT);
	}
	if (keysym == KEY_S || keysym == KEY_DOWN)
	{
		data->player->direction = SUD;
		refresh_map(data, KEY_DOWN);
	}
	if (keysym == KEY_D || keysym == KEY_RIGHT)
	{
		data->player->direction = EST;
		refresh_map(data, KEY_RIGHT);
	}
	return (0);
}

int	on_refresh(t_data *data)
{
	data->rate++;
	if (data->frame == 8)
		data->frame = 0;
	if (data->rate == 10000)
	{
		animate_player(data);
		animate_exit(data);
		animate_collect(data);
		data->rate = 0;
		data->frame++;
	}
	return (0);
}

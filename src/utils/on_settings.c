/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:34:15 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/26 16:23:47 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	destroy_free_walls(data);
	destroy_free_exit(data);
	destroy_free_player(data);
	destroy_free_collect(data);
	if (data->floor->img)
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
	data->frame = -1;
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

static void	finish(t_data *data)
{
	if (data->player->collected == data->nb_collectable)
	{
		if (data->player->x == data->exit->x
			&& data->player->y == data->exit->y)
		{
			ft_printf("%s\n", YOU_WIN);
			on_destroy(data);
		}
	}
}

int	on_refresh(t_data *data)
{
	data->rate++;
	if (data->frame == 8)
		data->frame = 0;
	if (data->frame_run == 8)
		data->frame_run = 0;
	if (data->frame_collec == 8)
		data->frame_collec = 0;
	if (data->rate == 10000)
		data->frame_run++;
	if (data->rate == 10000)
	{
		animate_player(data);
		animate_exit(data);
		animate_collect(data);
		data->rate = 0;
		data->frame++;
		data->frame_collec++;
	}
	finish(data);
	return (0);
}

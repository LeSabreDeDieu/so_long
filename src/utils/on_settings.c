/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:34:15 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/15 17:06:02 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	destroy_free_walls(data);
	destroy_free_exit(data);
	destroy_free_player(data);
	destroy_free_enemy(data);
	destroy_free_collect(data);
	destroy_free_numbers(data);
	if (data->floor->img)
		mlx_destroy_image(data->mlx_ptr, data->floor->img);
	free(data->floor);
	free(data->mob_direction);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr[0]);
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
	if (!data->dead && (keysym == KEY_W || keysym == KEY_UP))
	{
		data->player->direction = NORD;
		refresh_map_player(data, KEY_UP);
	}
	if (!data->dead && (keysym == KEY_A || keysym == KEY_LEFT))
	{
		data->player->direction = EST;
		refresh_map_player(data, KEY_LEFT);
	}
	if (!data->dead && (keysym == KEY_S || keysym == KEY_DOWN))
	{
		data->player->direction = SUD;
		refresh_map_player(data, KEY_DOWN);
	}
	if (!data->dead && (keysym == KEY_D || keysym == KEY_RIGHT))
	{
		data->player->direction = OUEST;
		refresh_map_player(data, KEY_RIGHT);
	}
	return (0);
}

static void	finish(t_data *data)
{
	if (!data->dead)
	{
		if (data->player->collected == data->nb_collectable)
		{
			if (data->player->pos->x == data->exit->pos->x
				&& data->player->pos->y == data->exit->pos->y)
			{
				ft_printf("%s\n", YOU_WIN);
				on_destroy(data);
			}
		}
	}
	else
	{
		if (data->dead == 1)
			ft_printf("%s\n", YOU_LOSE);
		if (data->dead <= 2)
			data->dead++;
	}
}

int	on_refresh(t_data *data)
{
	animate_exit(data);
	if (!data->dead)
	{
		if (data->rate % 9000 == 0)
		{
			data->frame_run++;
			animate_player(data);
			animate_mob(data);
			animate_collect(data);
			data->frame++;
			data->frame_collec++;
		}
		if (++data->rate == 20000)
		{
			mob_mouv(data);
			data->rate = 0;
		}
	}
	finish(data);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:52:17 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/25 16:58:41 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_key_down(t_data *data, unsigned int i, unsigned int j)
{
	if (data->map[i + 1][j] == 'C')
		data->player->collected++;
	if (data->map[i + 1][j] != '1')
	{
		if (i - 1 == data->exit->y && j == data->exit->x)
			data->map[i][j] = 'E';
		else
			data->map[i][j] = '0';
		data->map[i + 1][j] = 'P';
		data->player->y++;
		data->nb_pas++;
	}
}

static void	map_key_left(t_data *data, unsigned int i, unsigned int j)
{
	if (data->map[i][j - 1] == 'C')
		data->player->collected++;
	if (data->map[i][j - 1] != '1')
	{
		if (i == data->exit->y && j + 1 == data->exit->x)
			data->map[i][j] = 'E';
		else
			data->map[i][j] = '0';
		data->map[i][j - 1] = 'P';
		data->player->x--;
		data->nb_pas++;
	}
}

static void	map_key_up(t_data *data, unsigned int i, unsigned int j)
{
	if (data->map[i - 1][j] == 'C')
		data->player->collected++;
	if (data->map[i - 1][j] != '1')
	{
		if (i + 1 == data->exit->y && j == data->exit->x)
			data->map[i][j] = 'E';
		else
			data->map[i][j] = '0';
		data->map[i - 1][j] = 'P';
		data->player->y--;
		data->nb_pas++;
	}
}

static void	map_key_right(t_data *data, unsigned int i, unsigned int j)
{
	if (data->map[i][j + 1] == 'C')
		data->player->collected++;
	if (data->map[i][j + 1] != '1')
	{
		if (i == data->exit->y && j - 1 == data->exit->x)
			data->map[i][j] = 'E';
		else
			data->map[i][j] = '0';
		data->map[i][j + 1] = 'P';
		data->player->x++;
		data->nb_pas++;
	}
}

void	refresh_map(t_data *data, int key)
{
	if (key == KEY_DOWN)
	{
		map_key_down(data, data->player->y, data->player->x);
		print_player(data, key, data->player->y, data->player->x);
	}
	else if (key == KEY_LEFT)
	{
		map_key_left(data, data->player->y, data->player->x);
		print_player(data, key, data->player->y, data->player->x);
	}
	else if (key == KEY_UP)
	{
		map_key_up(data, data->player->y, data->player->x);
		print_player(data, key, data->player->y, data->player->x);
	}
	else if (key == KEY_RIGHT)
	{
		map_key_right(data, data->player->y, data->player->x);
		print_player(data, key, data->player->y, data->player->x);
	}
	re_print_image(data, key, data->player->y, data->player->x);
	ft_printf("Nombre de pas : %d\n", data->nb_pas);
}

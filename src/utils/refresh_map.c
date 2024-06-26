/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refresh_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:52:17 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/17 18:53:20 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	map_key_down(t_data *data, t_pos pos, int key)
{
	if (data->map[pos.y + 1][pos.x] == 'M')
	{
		print_image(data, data->heart[1]->img, 0, 0);
		print_image(data, data->mob[0][1]->img, pos.y + 1, pos.x);
		data->dead = 1;
	}
	if (data->map[pos.y + 1][pos.x] != '1')
	{
		if (data->map[pos.y + 1][pos.x] == 'C')
		{
			data->player->collected++;
			print_numbers(data, data->player->collected, 4, 0);
		}
		data->player->pos->y++;
		if (pos.y == data->exit->pos->y && pos.x == data->exit->pos->x)
			data->map[data->exit->pos->y][data->exit->pos->x] = 'E';
		else
			data->map[pos.y][pos.x] = '0';
		data->map[data->player->pos->y][data->player->pos->x] = 'P';
		data->nb_pas++;
		ft_printf("Nombre de pas : %d\n", data->nb_pas);
		print_player(data, key, data->player->pos->y, data->player->pos->x);
		print_numbers(data, data->nb_pas, 0, data->height);
	}
}

static void	map_key_left(t_data *data, t_pos pos, int key)
{
	if (data->map[pos.y][pos.x - 1] == 'M')
	{
		print_image(data, data->heart[1]->img, 0, 0);
		print_image(data, data->mob[0][1]->img, pos.y, pos.x - 1);
		data->dead = 1;
	}
	if (data->map[pos.y][pos.x - 1] != '1')
	{
		if (data->map[pos.y][pos.x - 1] == 'C')
		{
			data->player->collected++;
			print_numbers(data, data->player->collected, 4, 0);
		}
		data->player->pos->x--;
		if (pos.y == data->exit->pos->y && pos.x == data->exit->pos->x)
			data->map[data->exit->pos->y][data->exit->pos->x] = 'E';
		else
			data->map[data->player->pos->y][pos.x] = '0';
		data->map[data->player->pos->y][data->player->pos->x] = 'P';
		data->nb_pas++;
		ft_printf("Nombre de pas : %d\n", data->nb_pas);
		print_player(data, key, data->player->pos->y, data->player->pos->x);
		print_numbers(data, data->nb_pas, 0, data->height);
	}
}

static void	map_key_up(t_data *data, t_pos pos, int key)
{
	if (data->map[pos.y - 1][pos.x] == 'M')
	{
		print_image(data, data->heart[1]->img, 0, 0);
		print_image(data, data->mob[0][1]->img, pos.y - 1, pos.x);
		data->dead = 1;
	}
	if (data->map[pos.y - 1][pos.x] != '1')
	{
		if (data->map[pos.y - 1][pos.x] == 'C')
		{
			data->player->collected++;
			print_numbers(data, data->player->collected, 4, 0);
		}
		data->player->pos->y--;
		if (pos.y == data->exit->pos->y && pos.x == data->exit->pos->x)
			data->map[data->exit->pos->y][data->exit->pos->x] = 'E';
		else
			data->map[pos.y][pos.x] = '0';
		data->map[data->player->pos->y][data->player->pos->x] = 'P';
		data->nb_pas++;
		ft_printf("Nombre de pas : %u\n", data->nb_pas);
		print_player(data, key, data->player->pos->y, data->player->pos->x);
		print_numbers(data, data->nb_pas, 0, data->height);
	}
}

static void	map_key_right(t_data *data, t_pos pos, int key)
{
	if (data->map[pos.y][pos.x + 1] == 'M')
	{
		print_image(data, data->heart[1]->img, 0, 0);
		print_image(data, data->mob[0][1]->img, pos.y, pos.x + 1);
		data->dead = 1;
	}
	if (data->map[pos.y][pos.x + 1] != '1')
	{
		if (data->map[pos.y][pos.x + 1] == 'C')
		{
			data->player->collected++;
			print_numbers(data, data->player->collected, 4, 0);
		}
		data->player->pos->x++;
		if (pos.y == data->exit->pos->y && pos.x == data->exit->pos->x)
			data->map[data->exit->pos->y][data->exit->pos->x] = 'E';
		else
			data->map[pos.y][pos.x] = '0';
		data->map[data->player->pos->y][data->player->pos->x] = 'P';
		data->nb_pas++;
		ft_printf("Nombre de pas : %d\n", data->nb_pas);
		print_player(data, key, data->player->pos->y, data->player->pos->x);
		print_numbers(data, data->nb_pas, 0, data->height);
	}
}

void	refresh_map_player(t_data *data, int key)
{
	if (key == KEY_DOWN)
		map_key_down(data, *(data->player->pos), key);
	else if (key == KEY_LEFT)
		map_key_left(data, *(data->player->pos), key);
	else if (key == KEY_UP)
		map_key_up(data, *(data->player->pos), key);
	else if (key == KEY_RIGHT)
		map_key_right(data, *(data->player->pos), key);
	re_print_image(data, key, data->player->pos->y, data->player->pos->x);
}

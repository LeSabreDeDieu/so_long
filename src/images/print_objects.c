/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:00:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/17 18:52:57 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

static void	set_image_UI(t_img *UI, t_img *top_wall)
{
	ssize_t	i;

	i = 0;
	while (i < UI->line_length * 64)
	{
		if (UI->addr[i] == 0)
			UI->addr[i] = top_wall->addr[i];
		i++;
	}
}

static void	print_walls_corner(t_data *data, int y, int x)
{
	if (x == 0 && (y == 0 || y == data->height))
		print_image(data, data->wall[4]->img, y, x);
	else if (x == data->width && (y == 0 || y == data->height))
		print_image(data, data->wall[5]->img, y, x);
	else
		print_image(data, data->wall[6]->img, y, x);
}

void	print_walls(t_data *data, int y, int x)
{
	if (x == 0 && y > 0 && y < data->height)
		print_image(data, data->wall[0]->img, y, x);
	else if (x == data->width && y > 0 && y < data->height)
		print_image(data, data->wall[1]->img, y, x);
	else if (x > 0 && x < data->width && y == data->height)
		print_image(data, data->wall[2]->img, y, x);
	else if (x > 0 && x < data->width && y == 0 && data->map[1][x] == '1')
		print_image(data, data->wall[7]->img, y, x);
	else if (x > 0 && x < data->width && y == 0)
		print_image(data, data->wall[3]->img, y, x);
	else
		print_walls_corner(data, y, x);
}

void	print_player(t_data *data, int key, int y, int x)
{
	if (key == KEY_DOWN)
		print_image(data, data->player->run[SUD][(data->frame_run % 8)]->img, y,
			x);
	else if (key == KEY_RIGHT)
		print_image(data, data->player->idle[OUEST][0]->img, y, x);
	else if (key == KEY_UP)
		print_image(data, data->player->idle[NORD][0]->img, y, x);
	else if (key == KEY_LEFT)
		print_image(data, data->player->idle[EST][0]->img, y, x);
	if (data->player->old_direction != data->player->direction)
		data->frame_run = 0;
}

void	print_UI(t_data *data)
{
	set_image_UI(data->heart[0], data->wall[4]);
	set_image_UI(data->heart[1], data->wall[4]);
	set_image_UI(data->collect[4], data->wall[3]);
	print_image(data, data->heart[0]->img, 0, 0);
	print_image(data, data->collect[4]->img, 0, 3);
	print_numbers(data, data->player->collected, 4, 0);
}

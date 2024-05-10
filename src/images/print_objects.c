/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:00:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/06 09:26:03 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

void	print_player(t_data *data, int key, int i, int j)
{
	if (key == KEY_DOWN)
		print_image(data, data->player->run[SUD][(data->frame_run % 8)]->img, i,
			j);
	else if (key == KEY_RIGHT)
		print_image(data, data->player->idle[OUEST][0]->img, i, j);
	else if (key == KEY_UP)
		print_image(data, data->player->idle[NORD][0]->img, i, j);
	else if (key == KEY_LEFT)
		print_image(data, data->player->idle[EST][0]->img, i, j);
	if (data->player->old_direction != data->player->direction)
		data->frame_run = 0;
}

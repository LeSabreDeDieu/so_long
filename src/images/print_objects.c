/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:00:27 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/25 15:33:12 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_walls_corner(t_data *data, int y, int x)
{
	if (x == 0 && (y == 0 || y == data->height))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall[4]->img, x * 64, y * 64);
	else if (x == data->width && (y == 0 || y == data->height))
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall[5]->img, x * 64, y * 64);
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall[6]->img, x * 64, y * 64);
}

void	print_walls(t_data *data, int y, int x)
{
	if (x == 0 && y > 0 && y < data->height)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall[0]->img, x * 64, y * 64);
	else if (x == data->width && y > 0 && y < data->height)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall[1]->img, x * 64, y * 64);
	else if (x > 0 && x < data->width && y == data->height)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall[2]->img, x * 64, y * 64);
	else if (x > 0 && x < data->width && y == 0 && data->map[1][x] == '1')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall[7]->img, x * 64, y * 64);
	else if (x > 0 && x < data->width && y == 0)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->wall[3]->img, x * 64, y * 64);
	else
		print_walls_corner(data, y, x);
}

void	print_player(t_data *data, int key, int i, int j)
{
	if (key == KEY_DOWN)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player->imgs[0][0]->img, j * 64, i * 64);
	}
	else if (key == KEY_RIGHT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player->imgs[1][0]->img, j * 64, i * 64);
	}
	else if (key == KEY_UP)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player->imgs[2][0]->img, j * 64, i * 64);
	}
	else if (key == KEY_LEFT)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player->imgs[3][0]->img, j * 64, i * 64);
	}
	if (data->player->old_direction != data->player->direction)
		data->frame = 0;
}

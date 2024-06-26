/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:27:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/22 14:37:15 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "images.h"
#include "so_long.h"

void	print_image(t_data *data, void *img, int y, int x)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr[0], img, x * 64, y
		* 64);
}

static void	print_mob(t_data *data, int x, int y)
{
	static int	k = 0;

	data->mob_direction[k] = rand_number(0, 3);
	print_image(data, data->mob[data->mob_direction[k]][0]->img, x, y);
	k++;
}

static void	print_all_images_utils(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		print_walls(data, i, j);
	else if (data->map[i][j] == 'E')
	{
		print_image(data, data->exit->imgs[0]->img, i, j);
		data->exit->pos->x = j;
		data->exit->pos->y = i;
	}
	else if (data->map[i][j] == 'C')
		print_image(data, data->collect[0]->img, i, j);
	else if (data->map[i][j] == 'M')
		print_mob(data, i, j);
	else if (data->map[i][j] == 'P')
	{
		print_image(data, data->player->idle[data->player->direction][0]->img,
			i, j);
		data->player->pos->x = j;
		data->player->pos->y = i;
	}
	else
		print_image(data, data->floor->img, i, j);
	print_ui(data);
}

void	re_print_image(t_data *data, int key, int y, int x)
{
	if (key == KEY_DOWN)
		y--;
	if (key == KEY_LEFT)
		x++;
	if (key == KEY_UP)
		y++;
	if (key == KEY_RIGHT)
		x--;
	if (data->map[y][x] == '0')
		print_image(data, data->floor->img, y, x);
}

void	init_screen(t_data *data)
{
	int	i;
	int	j;

	load_image(data);
	i = 0;
	while (i <= data->height)
	{
		j = 0;
		while (j <= data->width)
		{
			print_all_images_utils(data, i, j);
			j++;
		}
		i++;
	}
}

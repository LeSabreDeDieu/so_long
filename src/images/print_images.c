/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:27:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/26 15:38:23 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_image(t_data *data, void *img, int i, int j)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, img, j * 64, i * 64);
}

static void	print_all_images_utils(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		print_walls(data, i, j);
	else if (data->map[i][j] == 'E')
	{
		print_image(data, data->exit->imgs[0]->img, i, j);
		data->exit->x = j;
		data->exit->y = i;
	}
	else if (data->map[i][j] == 'C')
		print_image(data, data->collect[0]->img, i, j);
	else if (data->map[i][j] == 'P')
	{
		print_image(data, data->player->idle[data->player->direction][0]->img,
			i, j);
		data->player->x = j;
		data->player->y = i;
	}
	else
		print_image(data, data->floor->img, i, j);
}

void	re_print_image(t_data *data, int key, int i, int j)
{
	if (key == KEY_DOWN)
		i--;
	if (key == KEY_LEFT)
		j++;
	if (key == KEY_UP)
		i++;
	if (key == KEY_RIGHT)
		j--;
	if (data->map[i][j] == '0')
		print_image(data, data->floor->img, i, j);
}

void	init_screen(t_data *data)
{
	int	i;
	int	j;

	set_img(data);
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

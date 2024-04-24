/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 13:27:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/22 11:07:29 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	print_all_images_utils(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
		print_walls(data, i, j);
	else if (data->map[i][j] == 'E')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit->imgs[0]->img, j * 64, i * 64);
		data->exit->x = j;
		data->exit->y = i;
	}
	else if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collect->img, j * 64, i * 64);
	else if (data->map[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->player->imgs[0]->img, j * 64, i * 64);
		data->player->x = j;
		data->player->y = i;
	}
	else
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor->img, j * 64, i * 64);
}

static void	re_print_all_images_utils(t_data *data, int key, int i, int j)
{
	if (data->map[i][j] == '1')
		print_walls(data, i, j);
	if (data->map[i][j] == '0')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->floor->img, j * 64, i * 64);
	if (data->map[i][j] == 'E')
	{
		if (data->player->collected == data->nb_collectable)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->exit->imgs[1]->img, data->exit->x * 64,
				data->exit->y * 64);
		else
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->exit->imgs[0]->img, j * 64, i * 64);
	}
	if (data->map[i][j] == 'C')
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->collect->img, j * 64, i * 64);
	if (data->map[i][j] == 'P')
		print_player(data, key, i, j);
}	

void	print_all_images(t_data *data)
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

void	re_print_all_images(t_data *data, int key)
{
	int	i;
	int	j;

	refresh_map(data, key);
	i = 0;
	while (i <= data->height)
	{
		j = 0;
		while (j <= data->width)
		{
			re_print_all_images_utils(data, key, i, j);
			j++;
		}
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:59:02 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/25 16:54:27 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_player(t_data *data)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		data->player->imgs[data->player->direction][data->frame]->img,
		data->player->x * 64, data->player->y * 64);
}

void	animate_exit(t_data *data)
{
	if (data->player->collected == data->nb_collectable)
	{
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->exit->imgs[1]->img, data->exit->x * 64, data->exit->y * 64);
		if (data->player->x == data->exit->x
			&& data->player->y == data->exit->y)
		{
			ft_printf("%s\n", YOU_WIN);
			on_destroy(data);
		}
	}
	else
	{
		if (data->player->x != data->exit->x
			&& data->player->y != data->exit->y)
			mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
				data->exit->imgs[0]->img, data->exit->x * 64, data->exit->y * 64);
	}
}

void	animate_collect(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'C')
			{
				mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
					data->collect[(data->frame % 4)]->img, j * 64, i * 64);
			}
			j++;
		}
		i++;
	}
}

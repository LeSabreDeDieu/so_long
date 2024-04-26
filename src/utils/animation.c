/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:59:02 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/26 16:22:30 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_player(t_data *data)
{
	if (data->frame != -1)
		print_image(data,
			data->player->idle[data->player->direction][data->frame]->img,
			data->player->y, data->player->x);
}

void	animate_exit(t_data *data)
{
	if (data->player->collected == data->nb_collectable)
		print_image(data, data->exit->imgs[1]->img, data->exit->y,
			data->exit->x);
	else
	{
		if (data->player->x != data->exit->x
			&& data->player->y != data->exit->y)
			print_image(data, data->exit->imgs[0]->img, data->exit->y,
				data->exit->x);
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
				print_image(data, data->collect[(data->frame_collec % 4)]->img,
					i, j);
			}
			j++;
		}
		i++;
	}
}

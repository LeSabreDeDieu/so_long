/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 13:59:02 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/14 12:31:36 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	animate_player(t_data *data)
{
	if (data->frame != -1)
		print_image(data,
			data->player->idle[data->player->direction][(data->frame % 8)]->img,
			data->player->pos->y, data->player->pos->x);
}

void	animate_exit(t_data *data)
{
	if (data->player->collected == data->nb_collectable)
	{
		print_image(data, data->exit->imgs[1]->img, data->exit->pos->y,
			data->exit->pos->x);
		return ;
	}
	if (data->player->pos->x != data->exit->pos->x
		|| data->player->pos->y != data->exit->pos->y)
		print_image(data, data->exit->imgs[0]->img, data->exit->pos->y,
			data->exit->pos->x);
}

void	animate_mob(t_data *data)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'M')
			{
				print_image(data,
					data->mob[data->mob_direction[k]][(data->frame_collec
						% 4)]->img, i, j);
				k++;
			}
			j++;
		}
		i++;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_mouv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:50:13 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/14 09:06:50 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	verif_collision(t_data *data, int i, int j)
{
	if (data->player->pos->x == (unsigned int)j
		&& data->player->pos->y == (unsigned int)i)
	{
		print_image(data, data->heart[1]->img, 0, 0);
		data->dead = 1;
	}
	if (data->map[i][j] == '1' || data->map[i][j] == 'C'
		|| data->map[i][j] == 'M')
		return (0);
	return (1);
}

static void	do_mouv_mob(t_data *data, int direction, int i, int j)
{
	if (data->map[i][j] == 'M')
		print_image(data, data->floor->img, i, j);
	if (direction == NORD && verif_collision(data, i, j - 1))
	{
		data->map[i][j] = '0';
		data->map[i][--j] = 'M';
	}
	if (direction == SUD && verif_collision(data, i, j + 1))
	{
		data->map[i][j] = '0';
		data->map[i][++j] = 'M';
	}
	if (direction == EST && verif_collision(data, i + 1, j))
	{
		data->map[i][j] = '0';
		data->map[++i][j] = 'M';
	}
	if (direction == OUEST && verif_collision(data, i - 1, j))
	{
		data->map[i][j] = '0';
		data->map[--i][j] = 'M';
	}
	print_image(data, data->enemy[direction][0]->img, i, j);
}

static void	refresh_map_mob(t_data *data, int i, int j, int k)
{
	int	direction;

	direction = rand_number(0, 11);
	if (direction >= 4)
		return ;
	data->mob_direction[k] = direction;
	do_mouv_mob(data, direction, i, j);
}

void	mob_mouv(t_data *data)
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
			if (data->map[i][j] == 'M' && (unsigned int)k < data->nb_mobs)
			{
				refresh_map_mob(data, i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

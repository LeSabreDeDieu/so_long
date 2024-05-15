/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_mouv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 08:50:13 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/14 12:31:36 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	verif_collision(t_data *data, int y, int x)
{
	if (data->player->pos->x == (unsigned int)x
		&& data->player->pos->y == (unsigned int)y)
	{
		print_image(data, data->heart[1]->img, 0, 0);
		data->dead = 1;
	}
	if (data->map[y][x] == '1' || data->map[y][x] == 'C'
		|| data->map[y][x] == 'M')
		return (0);
	return (1);
}

static void	do_mouv_mob(t_data *data, int direction, int y, int x)
{
	if (data->map[y][x] == 'M')
		print_image(data, data->floor->img, y, x);
	if (direction == NORD && verif_collision(data, y, x - 1))
	{
		data->map[y][x] = '0';
		data->map[y][--x] = 'M';
	}
	if (direction == SUD && verif_collision(data, y, x + 1))
	{
		data->map[y][x] = '0';
		data->map[y][++x] = 'M';
	}
	if (direction == EST && verif_collision(data, y + 1, x))
	{
		data->map[y][x] = '0';
		data->map[++y][x] = 'M';
	}
	if (direction == OUEST && verif_collision(data, y - 1, x))
	{
		data->map[y][x] = '0';
		data->map[--y][x] = 'M';
	}
	print_image(data, data->mob[direction][0]->img, y, x);
}

static void	refresh_map_mob(t_data *data, int y, int x, int k)
{
	int	direction;

	direction = rand_number(0, 11);
	if (direction >= 4)
		return ;
	data->mob_direction[k] = direction;
	do_mouv_mob(data, direction, y, x);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:17:07 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/25 16:28:58 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_exit(t_data *data)
{
	data->exit = ft_calloc(1, sizeof(t_player));
	if (!data->exit)
		return ;
	data->exit->imgs[0] = ft_calloc(1, sizeof(t_img));
	if (!data->exit->imgs[0])
		return ;
	data->exit->imgs[1] = ft_calloc(1, sizeof(t_img));
	if (!data->exit->imgs[1])
		return ;
}

static void	init_wall(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		data->wall[i] = ft_calloc(1, sizeof(t_img));
		if (!data->wall[i])
			return ;
		i++;
	}
}

static void	init_player(t_data *data)
{
	int	i;
	int	j;

	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return ;
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 8)
		{
			data->player->imgs[i][j] = ft_calloc(1, sizeof(t_img));
			if (!data->player->imgs[i][j])
				return ;
			j++;
		}
		i++;
	}
}

static void	init_floor_and_collect(t_data *data)
{
	int	i;

	data->floor = ft_calloc(1, sizeof(t_img));
	if (!data->floor)
		return ;
	i = 0;
	while (i < 4)
	{
		data->collect[i] = ft_calloc(1, sizeof(t_img));
		if (!data->collect[i])
			return ;
		i++;
	}
}

void	init_images(t_data *data)
{
	init_exit(data);
	init_wall(data);
	init_floor_and_collect(data);
	init_player(data);
	data->player->direction = SUD;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_settings_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:33:12 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/07 13:44:29 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_free_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (data->wall[i]->img)
			mlx_destroy_image(data->mlx_ptr, data->wall[i]->img);
		free(data->wall[i]);
		i++;
	}
}

void	destroy_free_exit(t_data *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (data->exit->imgs[i]->img)
			mlx_destroy_image(data->mlx_ptr, data->exit->imgs[i]->img);
		free(data->exit->imgs[i]);
		i++;
	}
	free(data->exit->pos);
	free(data->exit);
}

void	destroy_free_collect(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (data->collect[i]->img)
			mlx_destroy_image(data->mlx_ptr, data->collect[i]->img);
		free(data->collect[i]);
		i++;
	}
}

void	destroy_free_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 8)
		{
			if (data->player->idle[i][j]->img)
				mlx_destroy_image(data->mlx_ptr, data->player->idle[i][j]->img);
			if (data->player->run[i][j]->img)
				mlx_destroy_image(data->mlx_ptr, data->player->run[i][j]->img);
			free(data->player->idle[i][j]);
			free(data->player->run[i][j]);
			j++;
		}
		i++;
	}
	free(data->player->pos);
	free(data->player);
}

void	destroy_free_enemy(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (data->enemy[i][j]->img)
				mlx_destroy_image(data->mlx_ptr, data->enemy[i][j]->img);
			free(data->enemy[i][j]);
			j++;
		}
		i++;
	}
}

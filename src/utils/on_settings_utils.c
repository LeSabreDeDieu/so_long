/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:33:12 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/22 11:09:05 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_free_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < 8)
	{
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
		mlx_destroy_image(data->mlx_ptr, data->exit->imgs[i]->img);
		free(data->exit->imgs[i]);
		i++;
	}
	free(data->exit);
}

void	destroy_free_player(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx_ptr, data->player->imgs[i]->img);
		free(data->player->imgs[i]);
		i++;
	}
	free(data->player);
}

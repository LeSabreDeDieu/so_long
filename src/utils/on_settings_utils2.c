/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_settings_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:48:29 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/17 13:09:12 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_free_numbers(t_data *data)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (data->numbers[i])
		{
			if (data->numbers[i]->img)
				mlx_destroy_image(data->mlx_ptr, data->numbers[i]->img);
			free(data->numbers[i]);
		}
		i++;
	}
}

void	destroy_free_leftover(t_data *data)
{
	if (data->floor)
	{
		if (data->floor->img)
			mlx_destroy_image(data->mlx_ptr, data->floor->img);
		free(data->floor);
	}
	if (data->mob_direction)
		free(data->mob_direction);
}

void	destroy_window(t_data *data)
{
	if (data->win_ptr[1])
	{
		if (data->win_lose)
		{
			if (data->win_lose->img)
				mlx_destroy_image(data->mlx_ptr, data->win_lose->img);
			free(data->win_lose);
		}
		mlx_destroy_window(data->mlx_ptr, data->win_ptr[1]);
	}
	mlx_destroy_window(data->mlx_ptr, data->win_ptr[0]);
}

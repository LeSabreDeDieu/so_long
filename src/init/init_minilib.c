/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:25:14 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/13 11:56:40 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	clear_all(t_data *data)
{
	free(data->mob_direction);
	mlx_destroy_display(data->mlx_ptr);
	free_tab_str(data->map);
	free(data->mlx_ptr);
	exit_error(SCREENTOOBIG);
}

int	init_minilib(t_data *data)
{
	int	height_screen;
	int	width_screen;

	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (0);
	mlx_get_screen_size(data->mlx_ptr, &width_screen, &height_screen);
	if ((data->width + 1) * 64 > width_screen || (data->height + 1)
		* 64 > height_screen)
		clear_all(data);
	data->win_ptr = mlx_new_window(data->mlx_ptr, ((data->width + 1) * 64),
			((data->height + 1) * 64), "so_long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 0);
	return (1);
}

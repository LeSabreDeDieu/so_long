/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_minilib.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:25:14 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/19 14:18:36 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		(free(data->mlx_ptr), exit_error(SCREENTOOBIG));
	data->win_ptr = mlx_new_window(data->mlx_ptr, ((data->width + 1) * 64),
			((data->height + 1) * 64), "so_long");
	if (!data->win_ptr)
		return (free(data->mlx_ptr), 0);
	return (1);
}

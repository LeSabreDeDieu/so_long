/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_settings.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:34:15 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/22 10:35:05 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *data)
{
	destroy_free_walls(data);
	destroy_free_exit(data);
	destroy_free_player(data);
	mlx_destroy_image(data->mlx_ptr, data->floor->img);
	free(data->floor);
	mlx_destroy_image(data->mlx_ptr, data->collect->img);
	free(data->collect);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free_tab_str(data->map);
	free(data->mlx_ptr);
	exit(0);
}

int	on_keypress(int keysym, t_data *data)
{
	if (keysym == ESC)
		on_destroy(data);
	if (keysym == KEY_W || keysym == KEY_UP)
		re_print_all_images(data, KEY_UP);
	if (keysym == KEY_A || keysym == KEY_LEFT)
		re_print_all_images(data, KEY_LEFT);
	if (keysym == KEY_S || keysym == KEY_DOWN)
		re_print_all_images(data, KEY_DOWN);
	if (keysym == KEY_D || keysym == KEY_RIGHT)
		re_print_all_images(data, KEY_RIGHT);
	return (0);
}

int	on_keyrelease(int keysym, t_data *data)
{
	(void) keysym;
	if (data->nb_collectable == data->player->collected
		&& data->player->x == data->exit->x && data->player->y == data->exit->y)
		on_destroy(data);
	return (0);
}

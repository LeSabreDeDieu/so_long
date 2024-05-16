/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:33:37 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/16 14:58:37 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "images.h"
#include "so_long.h"
#include <X11/X.h>

int	init_win_lose_win(t_data *data)
{
	char	*win_str;

	win_str = "You win !";
	if (data->dead == 1)
	{
		data->win_lose = set_image(data, LOSE);
		win_str = "You lose !";
	}
	else
		data->win_lose = set_image(data, WIN);
	data->win_ptr[1] = mlx_new_window(data->mlx_ptr, 1024, 1024, win_str);
	if (!data->win_ptr[1])
		return (0);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr[1],
		data->win_lose->img, 0, 0);
	mlx_hook(data->win_ptr[1], KeyPress, KeyPressMask, &on_keypress_1, data);
	mlx_hook(data->win_ptr[1], DestroyNotify, StructureNotifyMask, &on_destroy,
		data);
	return (1);
}

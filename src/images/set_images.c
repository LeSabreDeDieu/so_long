/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:44:44 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/25 16:26:11 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_wall_2(t_data *data)
{
	data->wall[4]->img = mlx_xpm_file_to_image(data->mlx_ptr, CORNERWALLLEFT,
			&data->wall[4]->height, &data->wall[4]->width);
	if (!data->wall[4]->img)
		on_destroy(data);
	data->wall[5]->img = mlx_xpm_file_to_image(data->mlx_ptr, CORNERWALLRIGHT,
			&data->wall[5]->height, &data->wall[5]->width);
	if (!data->wall[5]->img)
		on_destroy(data);
	data->wall[6]->img = mlx_xpm_file_to_image(data->mlx_ptr, MIDWALL,
			&data->wall[6]->height, &data->wall[6]->width);
	if (!data->wall[6]->img)
		on_destroy(data);
	data->wall[7]->img = mlx_xpm_file_to_image(data->mlx_ptr, MIDWALLCOL,
			&data->wall[7]->height, &data->wall[7]->width);
	if (!data->wall[7]->img)
		on_destroy(data);
}

static void	set_wall(t_data *data)
{
	data->wall[0]->img = mlx_xpm_file_to_image(data->mlx_ptr, LEFTWALL,
			&data->wall[0]->height, &data->wall[0]->width);
	if (!data->wall[0]->img)
		on_destroy(data);
	data->wall[1]->img = mlx_xpm_file_to_image(data->mlx_ptr, RIGHTWALL,
			&data->wall[0]->height, &data->wall[0]->width);
	if (!data->wall[1]->img)
		on_destroy(data);
	data->wall[2]->img = mlx_xpm_file_to_image(data->mlx_ptr, BOTWALL,
			&data->wall[0]->height, &data->wall[0]->width);
	if (!data->wall[2]->img)
		on_destroy(data);
	data->wall[3]->img = mlx_xpm_file_to_image(data->mlx_ptr, TOPWALL,
			&data->wall[0]->height, &data->wall[0]->width);
	if (!data->wall[3]->img)
		on_destroy(data);
	set_wall_2(data);
}

static void	set_coin(t_data *data)
{
	data->collect[0]->img = mlx_xpm_file_to_image(data->mlx_ptr, COIN,
			&data->collect[0]->height, &data->collect[0]->width);
	if (!data->collect[0]->img)
		on_destroy(data);
	data->collect[1]->img = mlx_xpm_file_to_image(data->mlx_ptr, COIN1,
			&data->collect[0]->height, &data->collect[0]->width);
	if (!data->collect[1]->img)
		on_destroy(data);
	data->collect[2]->img = mlx_xpm_file_to_image(data->mlx_ptr, COIN2,
			&data->collect[0]->height, &data->collect[0]->width);
	if (!data->collect[2]->img)
		on_destroy(data);
	data->collect[3]->img = mlx_xpm_file_to_image(data->mlx_ptr, COIN3,
			&data->collect[0]->height, &data->collect[0]->width);
	if (!data->collect[3]->img)
		on_destroy(data);
}

static void	set_player_images(t_data *data)
{
	set_player_down(data);
	set_player_left(data);
	set_player_right(data);
	set_player_up(data);
}

void	set_img(t_data *data)
{
	data->floor->img = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR,
			&data->floor->height, &data->floor->width);
	if (!data->floor->img)
		on_destroy(data);
	data->exit->imgs[0]->img = mlx_xpm_file_to_image(data->mlx_ptr, EXIT,
			&data->exit->imgs[0]->height, &data->exit->imgs[0]->width);
	if (!data->exit->imgs[0]->img)
		on_destroy(data);
	data->exit->imgs[1]->img = mlx_xpm_file_to_image(data->mlx_ptr, EXITLADDER,
			&data->exit->imgs[0]->height, &data->exit->imgs[0]->width);
	if (!data->exit->imgs[1]->img)
		on_destroy(data);
	set_coin(data);
	set_wall(data);
	set_player_images(data);
}

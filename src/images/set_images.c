/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:44:44 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/22 10:48:52 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_wall_2(t_data *data)
{
	data->wall[4]->img = mlx_xpm_file_to_image(data->mlx_ptr, CORNERWALLLEFT,
			&data->collect->height, &data->collect->width);
	if (!data->wall[4]->img)
		on_destroy(data);
	data->wall[5]->img = mlx_xpm_file_to_image(data->mlx_ptr, CORNERWALLRIGHT,
			&data->collect->height, &data->collect->width);
	if (!data->wall[5]->img)
		on_destroy(data);
	data->wall[6]->img = mlx_xpm_file_to_image(data->mlx_ptr, MIDWALL,
			&data->collect->height, &data->collect->width);
	if (!data->wall[6]->img)
		on_destroy(data);
	data->wall[7]->img = mlx_xpm_file_to_image(data->mlx_ptr, MIDWALLCOL,
			&data->collect->height, &data->collect->width);
	if (!data->wall[7]->img)
		on_destroy(data);
}

static void	set_wall(t_data *data)
{
	data->wall[0]->img = mlx_xpm_file_to_image(data->mlx_ptr, LEFTWALL,
			&data->collect->height, &data->collect->width);
	if (!data->wall[0]->img)
		on_destroy(data);
	data->wall[1]->img = mlx_xpm_file_to_image(data->mlx_ptr, RIGHTWALL,
			&data->collect->height, &data->collect->width);
	if (!data->wall[1]->img)
		on_destroy(data);
	data->wall[2]->img = mlx_xpm_file_to_image(data->mlx_ptr, BOTWALL,
			&data->collect->height, &data->collect->width);
	if (!data->wall[2]->img)
		on_destroy(data);
	data->wall[3]->img = mlx_xpm_file_to_image(data->mlx_ptr, TOPWALL,
			&data->collect->height, &data->collect->width);
	if (!data->wall[3]->img)
		on_destroy(data);
	set_wall_2(data);
}

static void	set_player(t_data *data)
{
	data->player->imgs[0]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERDOWN, &data->player->imgs[0]->height,
			&data->player->imgs[0]->width);
	if (!data->player->imgs[0]->img)
		on_destroy(data);
	data->player->imgs[1]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERLEFT, &data->player->imgs[1]->height,
			&data->player->imgs[1]->width);
	if (!data->player->imgs[1]->img)
		on_destroy(data);
	data->player->imgs[2]->img = mlx_xpm_file_to_image(data->mlx_ptr, PLAYERUP,
			&data->player->imgs[2]->height, &data->player->imgs[2]->width);
	if (!data->player->imgs[2]->img)
		on_destroy(data);
	data->player->imgs[3]->img = mlx_xpm_file_to_image(data->mlx_ptr,
			PLAYERRIGHT, &data->player->imgs[3]->height,
			&data->player->imgs[3]->width);
	if (!data->player->imgs[3]->img)
		on_destroy(data);
}

void	set_img(t_data *data)
{
	data->collect->img = mlx_xpm_file_to_image(data->mlx_ptr, COIN,
			&data->collect->height, &data->collect->width);
	if (!data->collect->img)
		on_destroy(data);
	data->floor->img = mlx_xpm_file_to_image(data->mlx_ptr, FLOOR,
			&data->collect->height, &data->collect->width);
	if (!data->floor->img)
		on_destroy(data);
	data->exit->imgs[0]->img = mlx_xpm_file_to_image(data->mlx_ptr, EXIT,
			&data->collect->height, &data->collect->width);
	if (!data->exit->imgs[0]->img)
		on_destroy(data);
	data->exit->imgs[1]->img = mlx_xpm_file_to_image(data->mlx_ptr, EXITLADDER,
			&data->collect->height, &data->collect->width);
	if (!data->exit->imgs[1]->img)
		on_destroy(data);
	set_wall(data);
	set_player(data);
}

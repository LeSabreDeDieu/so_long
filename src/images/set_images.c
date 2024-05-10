/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:44:44 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/07 13:32:09 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "images.h"

void	*set_image(t_data *data, char *path, int height, int width)
{
	void	*img;

	img = mlx_xpm_file_to_image(data->mlx_ptr, path, &height, &width);
	if (!img)
		on_destroy(data);
	return (img);
}

static void	load_wall(t_data *data)
{
	data->wall[0]->img = set_image(data, LEFTWALL, data->wall[0]->height,
			data->wall[0]->width);
	data->wall[1]->img = set_image(data, RIGHTWALL, data->wall[1]->height,
			data->wall[1]->width);
	data->wall[2]->img = set_image(data, BOTWALL, data->wall[2]->height,
			data->wall[2]->width);
	data->wall[3]->img = set_image(data, TOPWALL, data->wall[3]->height,
			data->wall[3]->width);
	data->wall[4]->img = set_image(data, CORNERWALLLEFT, data->wall[4]->height,
			data->wall[4]->width);
	data->wall[5]->img = set_image(data, CORNERWALLRIGHT, data->wall[5]->height,
			data->wall[5]->width);
	data->wall[6]->img = set_image(data, MIDWALL, data->wall[6]->height,
			data->wall[6]->width);
	data->wall[7]->img = set_image(data, MIDWALLCOL, data->wall[7]->height,
			data->wall[7]->width);
}

static void	load_coin(t_data *data)
{
	data->collect[0]->img = set_image(data, COIN, data->collect[0]->height,
			data->collect[0]->width);
	data->collect[1]->img = set_image(data, COIN1, data->collect[0]->height,
			data->collect[0]->width);
	data->collect[2]->img = set_image(data, COIN2, data->collect[0]->height,
			data->collect[0]->width);
	data->collect[3]->img = set_image(data, COIN3, data->collect[0]->height,
			data->collect[0]->width);
}

static void	load_player(t_data *data)
{
	load_player_down(data);
	load_player_left(data);
	load_player_right(data);
	load_player_up(data);
}

void	load_image(t_data *data)
{
	data->floor->img = set_image(data, FLOOR, data->floor->height,
			data->floor->width);
	data->exit->imgs[0]->img = set_image(data, EXIT,
			data->exit->imgs[0]->height, data->exit->imgs[0]->width);
	data->exit->imgs[1]->img = set_image(data, EXITLADDER,
			data->exit->imgs[0]->height, data->exit->imgs[0]->width);
	load_coin(data);
	load_wall(data);
	load_player(data);
	load_enemy(data);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 10:44:44 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/13 13:00:08 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "images.h"
#include "so_long.h"

t_img	*set_image(t_data *data, char *path)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	if (!img)
		return (NULL);
	img->img = mlx_xpm_file_to_image(data->mlx_ptr, path, &img->height,
			&img->width);
	if (!img->img)
		on_destroy(data);
	img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_length,
			&img->endian);
	return (img);
}

static void	load_wall(t_data *data)
{
	data->wall[0] = set_image(data, LEFTWALL);
	data->wall[1] = set_image(data, RIGHTWALL);
	data->wall[2] = set_image(data, BOTWALL);
	data->wall[3] = set_image(data, TOPWALL);
	data->wall[4] = set_image(data, CORNERWALLLEFT);
	data->wall[5] = set_image(data, CORNERWALLRIGHT);
	data->wall[6] = set_image(data, MIDWALL);
	data->wall[7] = set_image(data, MIDWALLCOL);
}

static void	load_coin(t_data *data)
{
	data->collect[0] = set_image(data, COIN);
	data->collect[1] = set_image(data, COIN1);
	data->collect[2] = set_image(data, COIN2);
	data->collect[3] = set_image(data, COIN3);
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
	data->floor = set_image(data, FLOOR);
	data->exit->imgs[0] = set_image(data, EXIT);
	data->exit->imgs[1] = set_image(data, EXITLADDER);
	data->heart[0] = set_image(data, HALF_HEART);
	data->heart[1] = set_image(data, EMPTY_HEART);
	load_coin(data);
	load_wall(data);
	load_player(data);
	load_enemy(data);
}

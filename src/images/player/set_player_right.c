/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/07 11:35:33 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "images.h"

static void	set_player_run_right(t_data *data)
{
	data->player->run[1][0]->img = set_image(data, PLAYERDOWNRUN,
			data->player->run[1][0]->height, data->player->run[1][0]->width);
	data->player->run[1][1]->img = set_image(data, PLAYERDOWNRUN1,
			data->player->run[1][1]->height, data->player->run[1][1]->width);
	data->player->run[1][2]->img = set_image(data, PLAYERDOWNRUN2,
			data->player->run[1][2]->height, data->player->run[1][2]->width);
	data->player->run[1][3]->img = set_image(data, PLAYERDOWNRUN3,
			data->player->run[1][3]->height, data->player->run[1][3]->width);
	data->player->run[1][4]->img = set_image(data, PLAYERDOWNRUN4,
			data->player->run[1][4]->height, data->player->run[1][4]->width);
	data->player->run[1][5]->img = set_image(data, PLAYERDOWNRUN5,
			data->player->run[1][5]->height, data->player->run[1][5]->width);
	data->player->run[1][6]->img = set_image(data, PLAYERDOWNRUN6,
			data->player->run[1][6]->height, data->player->run[1][6]->width);
	data->player->run[1][7]->img = set_image(data, PLAYERDOWNRUN7,
			data->player->run[1][7]->height, data->player->run[1][7]->width);
}

void	load_player_right(t_data *data)
{
	data->player->idle[1][0]->img = set_image(data, PLAYERRIGHT,
			data->player->idle[1][0]->height, data->player->idle[1][0]->width);
	data->player->idle[1][1]->img = set_image(data, PLAYERRIGHT1,
			data->player->idle[1][1]->height, data->player->idle[1][1]->width);
	data->player->idle[1][2]->img = set_image(data, PLAYERRIGHT2,
			data->player->idle[1][2]->height, data->player->idle[1][2]->width);
	data->player->idle[1][3]->img = set_image(data, PLAYERRIGHT3,
			data->player->idle[1][3]->height, data->player->idle[1][3]->width);
	data->player->idle[1][4]->img = set_image(data, PLAYERRIGHT4,
			data->player->idle[1][4]->height, data->player->idle[1][4]->width);
	data->player->idle[1][5]->img = set_image(data, PLAYERRIGHT5,
			data->player->idle[1][5]->height, data->player->idle[1][5]->width);
	data->player->idle[1][6]->img = set_image(data, PLAYERRIGHT6,
			data->player->idle[1][6]->height, data->player->idle[1][6]->width);
	data->player->idle[1][7]->img = set_image(data, PLAYERRIGHT7,
			data->player->idle[1][7]->height, data->player->idle[1][7]->width);
	set_player_run_right(data);
}

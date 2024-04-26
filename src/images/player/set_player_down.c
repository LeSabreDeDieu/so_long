/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/26 15:42:54 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_player_run_down(t_data *data)
{
	data->player->run[0][0]->img = set_image(data, PLAYERDOWNRUN,
			data->player->run[0][0]->height, data->player->run[0][0]->width);
	data->player->run[0][1]->img = set_image(data, PLAYERDOWNRUN1,
			data->player->run[0][1]->height, data->player->run[0][1]->width);
	data->player->run[0][2]->img = set_image(data, PLAYERDOWNRUN2,
			data->player->run[0][2]->height, data->player->run[0][2]->width);
	data->player->run[0][3]->img = set_image(data, PLAYERDOWNRUN3,
			data->player->run[0][3]->height, data->player->run[0][3]->width);
	data->player->run[0][4]->img = set_image(data, PLAYERDOWNRUN4,
			data->player->run[0][4]->height, data->player->run[0][4]->width);
	data->player->run[0][5]->img = set_image(data, PLAYERDOWNRUN5,
			data->player->run[0][5]->height, data->player->run[0][5]->width);
	data->player->run[0][6]->img = set_image(data, PLAYERDOWNRUN6,
			data->player->run[0][6]->height, data->player->run[0][6]->width);
	data->player->run[0][7]->img = set_image(data, PLAYERDOWNRUN7,
			data->player->run[0][7]->height, data->player->run[0][7]->width);
}

void	set_player_down(t_data *data)
{
	data->player->idle[0][0]->img = set_image(data, PLAYERDOWN,
			data->player->idle[0][0]->height, data->player->idle[0][0]->width);
	data->player->idle[0][1]->img = set_image(data, PLAYERDOWN1,
			data->player->idle[0][1]->height, data->player->idle[0][1]->width);
	data->player->idle[0][2]->img = set_image(data, PLAYERDOWN2,
			data->player->idle[0][2]->height, data->player->idle[0][2]->width);
	data->player->idle[0][3]->img = set_image(data, PLAYERDOWN3,
			data->player->idle[0][3]->height, data->player->idle[0][3]->width);
	data->player->idle[0][4]->img = set_image(data, PLAYERDOWN4,
			data->player->idle[0][4]->height, data->player->idle[0][4]->width);
	data->player->idle[0][5]->img = set_image(data, PLAYERDOWN5,
			data->player->idle[0][5]->height, data->player->idle[0][5]->width);
	data->player->idle[0][6]->img = set_image(data, PLAYERDOWN6,
			data->player->idle[0][6]->height, data->player->idle[0][6]->width);
	data->player->idle[0][7]->img = set_image(data, PLAYERDOWN7,
			data->player->idle[0][7]->height, data->player->idle[0][7]->width);
	set_player_run_down(data);
}

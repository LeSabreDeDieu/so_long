/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/26 15:38:23 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_right(t_data *data)
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
}

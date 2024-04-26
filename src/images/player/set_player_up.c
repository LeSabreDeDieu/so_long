/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/26 15:38:23 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_up(t_data *data)
{
	data->player->idle[2][0]->img = set_image(data, PLAYERUP,
			data->player->idle[2][0]->height, data->player->idle[2][0]->width);
	data->player->idle[2][1]->img = set_image(data, PLAYERUP1,
			data->player->idle[2][1]->height, data->player->idle[2][1]->width);
	data->player->idle[2][2]->img = set_image(data, PLAYERUP2,
			data->player->idle[2][2]->height, data->player->idle[2][2]->width);
	data->player->idle[2][3]->img = set_image(data, PLAYERUP3,
			data->player->idle[2][3]->height, data->player->idle[2][3]->width);
	data->player->idle[2][4]->img = set_image(data, PLAYERUP4,
			data->player->idle[2][4]->height, data->player->idle[2][4]->width);
	data->player->idle[2][5]->img = set_image(data, PLAYERUP5,
			data->player->idle[2][5]->height, data->player->idle[2][5]->width);
	data->player->idle[2][6]->img = set_image(data, PLAYERUP6,
			data->player->idle[2][6]->height, data->player->idle[2][6]->width);
	data->player->idle[2][7]->img = set_image(data, PLAYERUP7,
			data->player->idle[2][7]->height, data->player->idle[2][7]->width);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/26 15:38:23 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_player_left(t_data *data)
{
	data->player->idle[3][0]->img = set_image(data, PLAYERLEFT,
			data->player->idle[3][0]->height, data->player->idle[3][0]->width);
	data->player->idle[3][1]->img = set_image(data, PLAYERLEFT1,
			data->player->idle[3][1]->height, data->player->idle[3][1]->width);
	data->player->idle[3][2]->img = set_image(data, PLAYERLEFT2,
			data->player->idle[3][2]->height, data->player->idle[3][2]->width);
	data->player->idle[3][3]->img = set_image(data, PLAYERLEFT3,
			data->player->idle[3][3]->height, data->player->idle[3][3]->width);
	data->player->idle[3][4]->img = set_image(data, PLAYERLEFT4,
			data->player->idle[3][4]->height, data->player->idle[3][4]->width);
	data->player->idle[3][5]->img = set_image(data, PLAYERLEFT5,
			data->player->idle[3][5]->height, data->player->idle[3][5]->width);
	data->player->idle[3][6]->img = set_image(data, PLAYERLEFT6,
			data->player->idle[3][6]->height, data->player->idle[3][6]->width);
	data->player->idle[3][7]->img = set_image(data, PLAYERLEFT7,
			data->player->idle[3][7]->height, data->player->idle[3][7]->width);
}

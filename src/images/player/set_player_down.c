/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_down.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/13 09:50:45 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "images.h"

void	load_player_down(t_data *data)
{
	data->player->idle[0][0] = set_image(data, PLAYERDOWN);
	data->player->idle[0][1] = set_image(data, PLAYERDOWN1);
	data->player->idle[0][2] = set_image(data, PLAYERDOWN2);
	data->player->idle[0][3] = set_image(data, PLAYERDOWN3);
	data->player->idle[0][4] = set_image(data, PLAYERDOWN4);
	data->player->idle[0][5] = set_image(data, PLAYERDOWN5);
	data->player->idle[0][6] = set_image(data, PLAYERDOWN6);
	data->player->idle[0][7] = set_image(data, PLAYERDOWN7);
	data->player->run[0][0] = set_image(data, PLAYERDOWNRUN);
	data->player->run[0][1] = set_image(data, PLAYERDOWNRUN1);
	data->player->run[0][2] = set_image(data, PLAYERDOWNRUN2);
	data->player->run[0][3] = set_image(data, PLAYERDOWNRUN3);
	data->player->run[0][4] = set_image(data, PLAYERDOWNRUN4);
	data->player->run[0][5] = set_image(data, PLAYERDOWNRUN5);
	data->player->run[0][6] = set_image(data, PLAYERDOWNRUN6);
	data->player->run[0][7] = set_image(data, PLAYERDOWNRUN7);
}

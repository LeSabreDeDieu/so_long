/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_up.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/13 09:55:02 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "images.h"

void	load_player_up(t_data *data)
{
	data->player->idle[2][0] = set_image(data, PLAYERUP);
	data->player->idle[2][1] = set_image(data, PLAYERUP1);
	data->player->idle[2][2] = set_image(data, PLAYERUP2);
	data->player->idle[2][3] = set_image(data, PLAYERUP3);
	data->player->idle[2][4] = set_image(data, PLAYERUP4);
	data->player->idle[2][5] = set_image(data, PLAYERUP5);
	data->player->idle[2][6] = set_image(data, PLAYERUP6);
	data->player->idle[2][7] = set_image(data, PLAYERUP7);
}

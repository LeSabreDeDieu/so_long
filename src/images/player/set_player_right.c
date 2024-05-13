/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_right.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/13 09:53:36 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "images.h"

void	load_player_right(t_data *data)
{
	data->player->idle[1][0] = set_image(data, PLAYERRIGHT);
	data->player->idle[1][1] = set_image(data, PLAYERRIGHT1);
	data->player->idle[1][2] = set_image(data, PLAYERRIGHT2);
	data->player->idle[1][3] = set_image(data, PLAYERRIGHT3);
	data->player->idle[1][4] = set_image(data, PLAYERRIGHT4);
	data->player->idle[1][5] = set_image(data, PLAYERRIGHT5);
	data->player->idle[1][6] = set_image(data, PLAYERRIGHT6);
	data->player->idle[1][7] = set_image(data, PLAYERRIGHT7);
}

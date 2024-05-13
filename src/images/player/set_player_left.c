/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_left.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 14:12:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/13 09:53:41 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "images.h"

void	load_player_left(t_data *data)
{
	data->player->idle[3][0] = set_image(data, PLAYERLEFT);
	data->player->idle[3][1] = set_image(data, PLAYERLEFT1);
	data->player->idle[3][2] = set_image(data, PLAYERLEFT2);
	data->player->idle[3][3] = set_image(data, PLAYERLEFT3);
	data->player->idle[3][4] = set_image(data, PLAYERLEFT4);
	data->player->idle[3][5] = set_image(data, PLAYERLEFT5);
	data->player->idle[3][6] = set_image(data, PLAYERLEFT6);
	data->player->idle[3][7] = set_image(data, PLAYERLEFT7);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemy_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:21:47 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/14 12:31:36 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "images.h"

void	load_enemy(t_data *data)
{
	data->mob[0][0] = set_image(data, ENEMYDOWN0);
	data->mob[0][1] = set_image(data, ENEMYDOWN1);
	data->mob[0][2] = set_image(data, ENEMYDOWN2);
	data->mob[0][3] = set_image(data, ENEMYDOWN3);
	data->mob[1][0] = set_image(data, ENEMYRIGHT0);
	data->mob[1][1] = set_image(data, ENEMYRIGHT1);
	data->mob[1][2] = set_image(data, ENEMYRIGHT2);
	data->mob[1][3] = set_image(data, ENEMYRIGHT3);
	data->mob[2][0] = set_image(data, ENEMYUP0);
	data->mob[2][1] = set_image(data, ENEMYUP1);
	data->mob[2][2] = set_image(data, ENEMYUP2);
	data->mob[2][3] = set_image(data, ENEMYUP3);
	data->mob[3][0] = set_image(data, ENEMYLEFT0);
	data->mob[3][1] = set_image(data, ENEMYLEFT1);
	data->mob[3][2] = set_image(data, ENEMYLEFT2);
	data->mob[3][3] = set_image(data, ENEMYLEFT3);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_enemy_image.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:21:47 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/07 13:42:09 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "images.h"

static void	load_enemy_2(t_data *data)
{
	data->enemy[2][0]->img = set_image(data, ENEMYUP0,
			data->enemy[2][0]->height, data->enemy[2][0]->width);
	data->enemy[2][1]->img = set_image(data, ENEMYUP1,
			data->enemy[2][1]->height, data->enemy[2][1]->width);
	data->enemy[2][2]->img = set_image(data, ENEMYUP2,
			data->enemy[2][2]->height, data->enemy[2][2]->width);
	data->enemy[2][3]->img = set_image(data, ENEMYUP3,
			data->enemy[2][3]->height, data->enemy[2][3]->width);
	data->enemy[3][0]->img = set_image(data, ENEMYLEFT0,
			data->enemy[3][0]->height, data->enemy[3][0]->width);
	data->enemy[3][1]->img = set_image(data, ENEMYLEFT1,
			data->enemy[3][1]->height, data->enemy[3][1]->width);
	data->enemy[3][2]->img = set_image(data, ENEMYLEFT2,
			data->enemy[3][2]->height, data->enemy[3][2]->width);
	data->enemy[3][3]->img = set_image(data, ENEMYLEFT3,
			data->enemy[3][3]->height, data->enemy[3][3]->width);
}

void	load_enemy(t_data *data)
{
	data->enemy[0][0]->img = set_image(data, ENEMYDOWN0,
			data->enemy[0][0]->height, data->enemy[0][0]->width);
	data->enemy[0][1]->img = set_image(data, ENEMYDOWN1,
			data->enemy[0][1]->height, data->enemy[0][1]->width);
	data->enemy[0][2]->img = set_image(data, ENEMYDOWN2,
			data->enemy[0][2]->height, data->enemy[0][2]->width);
	data->enemy[0][3]->img = set_image(data, ENEMYDOWN3,
			data->enemy[0][3]->height, data->enemy[0][3]->width);
	data->enemy[1][0]->img = set_image(data, ENEMYRIGHT0,
			data->enemy[1][0]->height, data->enemy[1][0]->width);
	data->enemy[1][1]->img = set_image(data, ENEMYRIGHT1,
			data->enemy[1][1]->height, data->enemy[1][1]->width);
	data->enemy[1][2]->img = set_image(data, ENEMYRIGHT2,
			data->enemy[1][2]->height, data->enemy[1][2]->width);
	data->enemy[1][3]->img = set_image(data, ENEMYRIGHT3,
			data->enemy[1][3]->height, data->enemy[1][3]->width);
	load_enemy_2(data);
}

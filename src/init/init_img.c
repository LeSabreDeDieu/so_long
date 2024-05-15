/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 17:17:07 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/15 10:12:46 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_images(t_data *data)
{
	data->exit = ft_calloc(1, sizeof(t_exit));
	if (!data->exit)
		return ;
	data->exit->pos = ft_calloc(1, sizeof(t_pos));
	if (!data->exit->pos)
		return ;
	data->player = ft_calloc(1, sizeof(t_player));
	if (!data->player)
		return ;
	data->player->pos = ft_calloc(1, sizeof(t_pos));
	if (!data->player->pos)
		return ;
	data->player->direction = SUD;
}

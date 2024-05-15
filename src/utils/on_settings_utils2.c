/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_settings_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:48:29 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/15 11:49:20 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_free_numbers(t_data *data)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (data->numbers[i]->img)
			mlx_destroy_image(data->mlx_ptr, data->numbers[i]->img);
		free(data->numbers[i]);
		i++;
	}
}

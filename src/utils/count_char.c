/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 09:01:37 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/10 09:08:07 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	char_counter(t_data *data, int counter[4], int i, int j)
{
	if (data->map[i][j] == 'P')
		counter[0]++;
	if (data->map[i][j] == 'E')
		counter[1]++;
	if (data->map[i][j] == 'C')
		counter[2]++;
	if (data->map[i][j] == 'M')
		counter[3]++;
}

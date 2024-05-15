/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 16:33:37 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/15 17:05:12 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	init_win_lose_win(t_data *data)
{
	char	*win_str;

	win_str = "You Win !";
	if (data->dead == 1)
		win_str = "You lose !";
	data->win_ptr[1] = mlx_new_window(data->mlx_ptr, 800, 800, win_str);
	if (!data->win_ptr[1])
		return (0);
	mlx_loop(data->mlx_ptr);
	return (1);
}

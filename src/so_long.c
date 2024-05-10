/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:15:30 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/07 11:56:02 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <X11/X.h>

void	usage(void)
{
	ft_printf("Usage : ./so_long [chemin relatif de la map]\n");
	exit(1);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2)
		usage();
	ft_bzero(&data, sizeof(data));
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
		exit_error(NOTBER);
	check_valid_map(&data, argv[1]);
	if (!init_minilib(&data))
		return (1);
	init_images(&data);
	init_screen(&data);
	mlx_loop_hook(data.mlx_ptr, &on_refresh, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &on_keypress, &data);
	mlx_hook(data.win_ptr, DestroyNotify, StructureNotifyMask, &on_destroy,
		&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}

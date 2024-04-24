/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:40:36 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/24 12:08:33 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_tab_str(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_visited_map(char **map, int height)
{
	int	i;

	i = 0;
	while (i < height)
		free(map[i++]);
	free(map);
}

void	get_player_pos(t_data *data, int pos[2])
{
	int	i;
	int	j;

	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == 'P')
			{
				pos[0] = j;
				pos[1] = i;
			}
			j++;
		}
		i++;
	}
}

bool	is_valid_path(t_data *data, char **visited, int x, int y)
{
	if (x <= 0 || x >= data->height || y <= 0 || y >= data->width)
		return (false);
	if (data->map[x][y] == '1' || visited[x][y])
		return (false);
	if (data->map[x][y] == 'E')
		return (true);
	visited[x][y] = true;
	if (is_valid_path(data, visited, x + 1, y) || is_valid_path(data, visited, x
			- 1, y) || is_valid_path(data, visited, x, y + 1)
		|| is_valid_path(data, visited, x, y - 1))
		return (true);
	return (false);
}

char	**init_visited_map(t_data *data)
{
	int		i;
	char	**tmp;

	tmp = ft_calloc(data->height + 1, sizeof(char *));
	i = 0;
	while (i <= data->height)
		tmp[i++] = ft_calloc(data->width + 1, sizeof(char));
	return (tmp);
}

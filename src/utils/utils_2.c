/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/17 09:28:44 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/17 10:31:01 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_collectables(t_data *data, char **visited, int x, int y)
{
	if (x < 0 || x >= data->height || y < 0 || y >= data->width)
		return (0);
	if (data->map[x][y] == '1' || visited[x][y])
		return (0);
	if (data->map[x][y] == 'C')
	{
		data->nb_collectable--;
	}
	visited[x][y] = 1;
	check_collectables(data, visited, x + 1, y);
	check_collectables(data, visited, x - 1, y);
	check_collectables(data, visited, x, y + 1);
	check_collectables(data, visited, x, y - 1);
	return (0);
}

int	find_exit(t_data *data, char **visited, int x, int y)
{
	if (x < 0 || x >= data->height || y < 0 || y >= data->width)
		return (0);
	if (data->map[x][y] == '1' || visited[x][y])
		return (0);
	if (data->map[x][y] == 'E')
		return (1);
	visited[x][y] = 1;
	if (find_exit(data, visited, x + 1, y) || find_exit(data, visited, x - 1, y)
		|| find_exit(data, visited, x, y + 1) || find_exit(data, visited, x, y
			- 1))
		return (1);
	return (0);
}

static void	reset_map(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
			map[i][j++] = 0;
		i++;
	}
}

int	is_valid_path(t_data *data, int start_x, int start_y)
{
	char	**visited;
	int		result;
	int		i;

	i = 0;
	visited = ft_calloc(data->height + 1, sizeof(char *));
	while (i < data->height)
		visited[i++] = ft_calloc(data->width + 1, sizeof(char));
	check_collectables(data, visited, start_x, start_y);
	if (data->nb_collectable > 0)
	{
		free_tab_str(visited);
		return (0);
	}
	reset_map(visited, data->height, data->width);
	result = find_exit(data, visited, start_x, start_y);
	i = 0;
	while (i < data->height)
		free(visited[i++]);
	free(visited);
	return (result);
}

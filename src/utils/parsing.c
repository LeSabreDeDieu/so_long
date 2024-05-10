/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:09:37 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/10 10:13:53 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>

static char	*get_map(char *path)
{
	int		fd;
	char	*line;
	char	*tmp;
	char	*map;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		exit_error(FILENOTFOUND);
	map = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!map)
			map = line;
		else
		{
			tmp = ft_strjoin(map, line);
			free(map);
			free(line);
			map = tmp;
		}
	}
	return (close(fd), map);
}

static void	check_empty_line(char *map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			exit_error(EMPTYLINE);
		}
		i++;
	}
}

static void	check_size_line(char *map[])
{
	size_t	size_line;
	size_t	i;

	size_line = ft_strlen(map[0]);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) != size_line)
		{
			free_tab_str(map);
			exit_error(NOTRECT);
		}
		i++;
	}
}

static void	check_bordered(t_data *data)
{
	size_t	i;

	if (!(right_line(data->map[0])) && !(right_line(data->map[data->height])))
	{
		free_tab_str(data->map);
		exit_error(NOTBORDERED);
	}
	i = 0;
	while (data->map[i])
	{
		if (data->map[i][0] != '1' || data->map[i][data->width] != '1')
		{
			free_tab_str(data->map);
			exit_error(NOTBORDERED);
		}
		i++;
	}
}

void	check_valid_map(t_data *data, char *path)
{
	char	*map_tmp;
	char	**visited_map;
	int		player_pos[2];

	map_tmp = get_map(path);
	check_empty_line(map_tmp);
	data->map = ft_split(map_tmp, '\n');
	free(map_tmp);
	if (!data->map)
		exit_error(FAILURE);
	check_chars(data);
	check_size_line(data->map);
	get_height_width(data, data->map);
	check_bordered(data);
	visited_map = init_visited_map(data);
	ft_bzero(player_pos, sizeof(int));
	get_player_pos(data, player_pos);
	if (!is_valid_path(data, visited_map, player_pos[1], player_pos[0]))
	{
		free_tab_str(data->map);
		free_visited_map(visited_map, data->height + 1);
		exit_error(NOVALIDPATH);
	}
	free_visited_map(visited_map, data->height + 1);
}

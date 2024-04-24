/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 11:10:54 by sgabsi            #+#    #+#             */
/*   Updated: 2024/04/22 11:17:05 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	verif_nb_chars(t_data *data, int counter[3])
{
	if (counter[0] < 1 || counter[1] < 1 || counter[2] < 1)
	{
		free_tab_str(data->map);
		exit_error(MISSING);
	}
	if (counter[0] > 1 || counter[1] > 1)
	{
		free_tab_str(data->map);
		exit_error(TOOMANY);
	}
	data->nb_collectable = counter[2];
}

static void	is_in_list(t_data *data, char *chars, int i, int j)
{
	if (ft_strchr(chars, data->map[i][j]) == NULL)
	{
		free_tab_str(data->map);
		exit_error(CHARERROR);
	}
}

void	check_chars(t_data *data)
{
	int		i;
	int		j;
	char	*chars;
	int		counter[3];

	i = 0;
	ft_bzero(counter, sizeof(counter));
	chars = "10CPE";
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			is_in_list(data, chars, i, j);
			if (data->map[i][j] == 'P')
				counter[0]++;
			if (data->map[i][j] == 'E')
				counter[1]++;
			if (data->map[i][j] == 'C')
				counter[2]++;
			j++;
		}
		i++;
	}
	verif_nb_chars(data, counter);
}

int	right_line(char *line)
{
	size_t	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	get_height_width(t_data *data, char *map[])
{
	int	i;

	i = 0;
	while (map[i])
		i++;
	data->height = i - 1;
	data->width = ft_strlen(map[0]) - 1;
}

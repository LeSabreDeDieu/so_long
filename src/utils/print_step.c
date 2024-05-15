/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 10:17:18 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/15 11:55:00 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_number_size(int n)
{
	int	size;

	size = 0;
	if (n <= 0)
		size++;
	while (n != 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

void	set_image_numbers(t_img *numbers, t_img *bot_wall)
{
	ssize_t	i;

	i = 0;
	while (i < numbers->line_length * numbers->height)
	{
		if (numbers->addr[i] == 0)
			numbers->addr[i] = bot_wall->addr[i];
		i++;
	}
}

void	print_step(t_data *data, int nb_step)
{
	char	*nb_step_str;
	char	tmp[2];
	int		nb_img;
	int		i;
	int		actual_number;

	i = 0;
	ft_bzero(tmp, sizeof(char) * 2);
	nb_img = get_number_size(nb_step);
	nb_step_str = ft_itoa(nb_step);
	while (i < nb_img)
	{
		tmp[0] = nb_step_str[i];
		actual_number = ft_atoi(tmp);
		print_image(data, data->numbers[actual_number]->img, data->height,
			i + 1);
		i++;
	}
	free(nb_step_str);
}

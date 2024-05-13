/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 12:14:34 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/10 14:44:23 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static int	generate_seed(void)
{
	int		fd;
	int		rand;
	size_t	nb_read;

	fd = open("/dev/random", O_RDONLY);
	if (fd == -1)
	{
		return (-1);
	}
	nb_read = read(fd, &rand, sizeof(rand));
	if (nb_read != sizeof(rand))
	{
		close(fd);
		return (-1);
	}
	close(fd);
	return (rand);
}

int	rand_number(int min, int max)
{
	int	seed;
	int	rand;

	seed = generate_seed();
	if (seed < 0)
		seed *= -1;
	rand = (seed % (max - min + 1)) + min;
	return (rand);
}

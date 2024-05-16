/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgabsi <sgabsi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:16:30 by sgabsi            #+#    #+#             */
/*   Updated: 2024/05/16 15:18:58 by sgabsi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	exit_error2(int error)
{
	if (error == MISSING)
	{
		ft_putstr_fd("Il manque soit des collectables, soit un joueur,", 2);
		ft_putendl_fd("soit une sortie", 2);
	}
	if (error == TOOMANY)
		ft_putendl_fd("Il y a trop de joueurs ou de sorties", 2);
	if (error == NOTRECT)
		ft_putendl_fd("La map n'est pas rectangulaire", 2);
	if (error == NOTBORDERED)
		ft_putendl_fd("La map n'a pas de bordure complete", 2);
	if (error == NOVALIDPATH)
		ft_putendl_fd("Il n'existe pas de chemin valide pour finir le jeu", 2);
	if (error == VOIDMAP)
		ft_putendl_fd("La map est vide", 2);
}

void	exit_error(int error)
{
	ft_putendl_fd("Error", 2);
	if (error == NOTBER)
		ft_putendl_fd("La map n'est pas au format .ber !", 2);
	if (error == SCREENTOOBIG)
		ft_putendl_fd("La map est trop grande !", 2);
	if (error == FILENOTFOUND)
		ft_putendl_fd("La map n'existe pas !", 2);
	if (error == CHARERROR)
	{
		ft_putstr_fd("La map contient des caracteres differents de ", 2);
		ft_putendl_fd("1, 0, C, P et E !", 2);
	}
	if (error == EMPTYLINE)
		ft_putendl_fd("Il y a une ligne vide dans la map !", 2);
	exit_error2(error);
	exit(FAILURE);
}

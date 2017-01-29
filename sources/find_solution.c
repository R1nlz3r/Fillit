/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 05:28:22 by mapandel          #+#    #+#             */
/*   Updated: 2017/01/29 10:20:19 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_try_soluce(t_fillit *f)
{
	//à toi de jouer (c'est l'heure du dududu-duel)
	//return (1) pour indiquer qu'on a réussi à tout rentrer
	//sinon return(0) pour incrémenter la taille de la map
	(void)f;//<- retire ça, c'est juste pour utiliser le paramètre et passer le flag -Werror
	return (1);
}

static int		ft_init_map(t_fillit *f)
{
	int		i;

	i = 0;
	if (!(f->map = ft_memalloc(sizeof(char**) * f->mapsize)))
		ft_exit();
	while (i < f->mapsize)
	{
		if (!(f->map[i] = ft_strnew(f->mapsize)))
			ft_exit();
		f->map[i] = ft_strfill(f->map[i], '.', f->mapsize);
		++i;
	}
	return (ft_try_soluce(f));
}

void	ft_find_solution(t_fillit *f)
{
	while(!(ft_init_map(f)))
		++f->mapsize;
}

//find_solution						check (on incrémente la map ici)
//init_map							check
	//try_soluce (aka poser tous les tétriminos sur la map et voir si ça rentre)
		//crush_on_solution (Pour poser un tétriminos sur la map)

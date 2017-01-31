/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 05:28:22 by mapandel          #+#    #+#             */
/*   Updated: 2017/01/31 12:02:31 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static void		ft_put_on_map(t_fillit *f)
{
	f->line = f->postetrix[f->tet];
	while (f->line < 4)
	{
		f->carac = f->postetriy[f->tet];
		while (f->carac < 4)
		{
			if (f->tetri[f->tet][f->line][f->carac] == '#')
				f->map[f->line + f->mapx - f->postetrix[f->tet]][f->carac + f->mapy - f->postetriy[f->tet]] = 'A' + f->tet;
			++f->carac;
		}
		++f->line;
	}
}

static int		ft_try_to_put_on_map(t_fillit *f)
{
	f->line = f->postetrix[f->tet];
	while (f->line < 4)
	{
		f->carac = f->postetriy[f->tet];
		while (f->carac < 4)
		{
			if (f->tetri[f->tet][f->line][f->carac] == '#'
				&& (f->line - f->postetrix[f->tet] + f->mapx >= f->mapsize
				|| f->carac - f->postetriy[f->tet] + f->mapy >= f->mapsize
				|| f->map[f->line - f->postetrix[f->tet] + f->mapx][f->carac - f->postetriy[f->tet] + f->mapy] != '.'))
				return (0);
			++f->carac;
		}
		++f->line;
	}
	ft_put_on_map(f);
	return (1);
}

static int		ft_iter_on_map(t_fillit *f)
{
	f->tet = 0;
	while (f->tet < 26 && f->tetri[f->tet][0][0])
	{
		f->mapx = 0;
		f->booltetonmap = 0;
		while (f->mapx < f->mapsize && !f->booltetonmap)
		{
			f->mapy = 0;
			while (f->mapy < f->mapsize && !f->booltetonmap)
			{
				f->booltetonmap = ft_try_to_put_on_map(f);
				++f->mapy;
			}
			++f->mapx;
		}
		if (!f->booltetonmap)
			return (0);
		++f->tet;
	}
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
	return (ft_iter_on_map(f));
}

void	ft_find_solution(t_fillit *f)
{
	while(!(ft_init_map(f)))
		++f->mapsize;
	ft_putmap(f->map, f->mapsize);
}

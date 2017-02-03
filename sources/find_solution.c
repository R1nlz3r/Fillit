/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_solution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mapandel <mapandel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 05:28:22 by mapandel          #+#    #+#             */
/*   Updated: 2017/02/03 03:30:08 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_del_on_map(t_fillit *f)
{
	int		x;
	int		y;

	--f->tet;
	x = 0;
	while (x < f->mapsize)
	{
		y = 0;
		while (y < f->mapsize)
		{
			if (f->map[x][y] == f->tet + 'A')
				f->map[x][y] = '.';
			++y;
		}
		++x;
	}
}

static void		ft_put_on_map(t_fillit *f)
{
	f->line = f->postetrix[f->tet];
	while (f->line < 4)
	{
		f->carac = f->postetriy[f->tet];
		while (f->carac < 4)
		{
			if (f->tetri[f->tet][f->line][f->carac] == '#')
				f->map[f->line + f->mapx[f->tet] - f->postetrix[f->tet]][f->carac + f->mapy[f->tet] - f->postetriy[f->tet]] = 'A' + f->tet;
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
				&& (f->line - f->postetrix[f->tet] + f->mapx[f->tet] >= f->mapsize
				|| f->carac - f->postetriy[f->tet] + f->mapy[f->tet] >= f->mapsize
				|| f->map[f->line - f->postetrix[f->tet] + f->mapx[f->tet]][f->carac - f->postetriy[f->tet] + f->mapy[f->tet]] != '.'))
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
		if (f->mapx[f->tet] == f->mapsize)
			f->mapx[f->tet] = 0;
		f->booltetonmap = 0;
		while (f->mapx[f->tet] < f->mapsize && !f->booltetonmap)
		{
			if (f->mapy[f->tet] == f->mapsize)
				f->mapy[f->tet] = 0;
			while (f->mapy[f->tet] < f->mapsize && !f->booltetonmap)
			{
				f->booltetonmap = ft_try_to_put_on_map(f);
				++f->mapy[f->tet];
			}
			if (!f->booltetonmap || f->mapy[f->tet] == f->mapsize)
				++f->mapx[f->tet];
		}
		if (!f->booltetonmap && !f->tet)
			return(0);
		else if (!f->booltetonmap)
			ft_del_on_map(f);
		else
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
	{
		++f->mapsize;
		ft_tabfill(f->mapx, 0, 26);
		ft_tabfill(f->mapy, 0, 26);
	}
	ft_putmap(f->map, f->mapsize);
	exit(0);
}

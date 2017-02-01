/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlanduyt <vlanduyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:41:48 by vlanduyt          #+#    #+#             */
/*   Updated: 2017/02/01 09:18:25 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_find_pos_tetriminos(t_fillit *f)
{
	f->tet = 0;
	while (f->tet < 26 && f->tetri[f->tet][0][0])
	{
		f->line = 0;
		while (f->line < 4)
		{
			f->carac = 0;
			while (f->carac < 4)
			{
				if (f->tetri[f->tet][f->line][f->carac] == '#'
					&& f->postetrix[f->tet] > f->line)
					f->postetrix[f->tet] = f->line;
				if (f->tetri[f->tet][f->line][f->carac] == '#'
					&& f->postetriy[f->tet] > f->carac)
					f->postetriy[f->tet] = f->carac;
				++f->carac;
			}
			++f->line;
		}
		++f->tet;
	}
	ft_find_solution(f);
}

static void		ft_check_valid_tetriminos_2(t_fillit *f)
{
	int		tmp;

	tmp = f->sharp;
	if (f->tetri[f->tet][f->line][f->carac] == '#')
	{
		if (f->carac != 0 && (f->tetri[f->tet][f->line][f->carac - 1] == '#'))
			++f->sharp;
		if (f->line != 0 && (f->tetri[f->tet][f->line - 1][f->carac] == '#'))
			++f->sharp;
		if (f->line != 4 && (f->tetri[f->tet][f->line + 1][f->carac] == '#'))
			++f->sharp;
		if (f->carac != 4 && (f->tetri[f->tet][f->line][f->carac + 1] == '#'))
			++f->sharp;
		if (tmp == f->sharp)
			ft_exit();
	}
}

static void		ft_check_valid_tetriminos(t_fillit *f)
{
	f->tet = 0;
	while (f->tet < 26 && f->tetri[f->tet][0][0])
	{
		f->line = 0;
		f->sharp = 0;
		while (f->line < 4)
		{
			f->carac = 0;
			while (f->carac < 4)
			{
				ft_check_valid_tetriminos_2(f);
				++f->carac;
			}
			++f->line;
		}
		if (f->sharp < 5)
			ft_exit();
		++f->tet;
	}
	ft_find_pos_tetriminos(f);
}

static void		ft_check_carac_tetriminos(t_fillit *f)
{
	f->tet = 0;
	while (f->tet < 26 && f->tetri[f->tet][0][0])
	{
		f->line = 0;
		f->sharp = 0;
		while (f->line < 4)
		{
			f->carac = 0;
			while (f->carac < 4)
			{
				if (f->tetri[f->tet][f->line][f->carac] == '#')
					++f->sharp;
				else if (!(f->tetri[f->tet][f->line][f->carac] == '.'))
					ft_exit();
				++f->carac;
			}
			++f->line;
		}
		if (f->sharp != 4)
			ft_exit();
		++f->tet;
	}
	ft_check_valid_tetriminos(f);
}

void	ft_split_tetriminos(t_fillit *f)
{
	while (1)
	{
		if (f->line < 4 && f->tet < 26 && (f->lenline = read(f->fd, f->buf, 5))
			&& ft_strlen(f->buf) == 5 && f->buf[4] == '\n')
		{
			ft_strncpy(f->tetri[f->tet][f->line++], f->buf, 4);
			ft_strclr(f->buf);
		}
		else if (f->line == 4 && (f->lenline = read(f->fd, f->buf, 1))
			&& ft_strlen(f->buf) == 1 && f->buf[0] == '\n')
		{
			f->line = 0;
			++f->tet;
		}
		else if (!f->lenline)
			break ;
		else
			ft_exit();
	}
	if (f->line != 4)
		ft_exit();
	ft_check_carac_tetriminos(f);
}

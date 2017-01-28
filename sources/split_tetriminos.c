/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlanduyt <vlanduyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:41:48 by vlanduyt          #+#    #+#             */
/*   Updated: 2017/01/28 03:35:23 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_check_valid_tetriminos(t_fillit *f)
{
	f->tet = 0;
	while (f->tet < 26 && f->tetri[f->tet][f->line][f->carac])
	{
		f->line = 0;
		while (f->line < 4)
		{
			f->carac = 0;
			while (f->carac < 4)
			{
				if (f->tetri[f->tet][f->line][f->carac] == '#'
					&& !((f->carac != 0 && (f->tetri[f->tet][f->line][f->carac - 1] == '#'))
					|| (f->line != 0 && (f->tetri[f->tet][f->line - 1][f->carac] == '#'))
					|| (f->line != 4 && (f->tetri[f->tet][f->line + 1][f->carac] == '#'))
					|| (f->carac != 4 && (f->tetri[f->tet][f->line][f->carac + 1] == '#'))))
						exit (-1);
				++f->carac;
			}
			++f->line;
		}
		++f->tet;
	}
}

static void		ft_check_carac_tetriminos(t_fillit *f)
{
	f->tet = 0;
	while (f->tet < 26 && f->tetri[f->tet][f->line][f->carac])
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
				else if (!(f->tetri[f->tet][f->line][f->carac] == '.')
					|| f->sharp > 4)
					exit (-1);
				++f->carac;
			}
			++f->line;
		}
		if (f->sharp < 4)
			exit (-1);
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
			exit (-1);
	}
	if (f->line != 4)
		exit (-1);
	ft_check_carac_tetriminos(f);
}

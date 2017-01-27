/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlanduyt <vlanduyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:41:48 by vlanduyt          #+#    #+#             */
/*   Updated: 2017/01/27 06:18:16 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_check_carac_tetriminos(t_fillit *fillit)
{
	fillit->counttetri = 0;
	while (fillit->counttetri < 26)
	{
		fillit->countlines = 0;
		fillit->countsharps = 0;
		while (fillit->countlines < 4)
		{
			fillit->countcaracs = 0;
			while (fillit->countcaracs < 4 && fillit->tetri[fillit->counttetri]
				[fillit->countlines][fillit->countcaracs])
			{
				if (fillit->tetri[fillit->counttetri][fillit->countlines]
					[fillit->countcaracs] == '#')
					++fillit->countsharps;
				if (!(fillit->tetri[fillit->counttetri][fillit->countlines]
					[fillit->countcaracs] == '#'
					|| fillit->tetri[fillit->counttetri][fillit->countlines]
					[fillit->countcaracs] == '.') || fillit->countsharps > 4)
						exit (-1);
				++fillit->countcaracs;
			}
			++fillit->countlines;
		}
		++fillit->counttetri;
	}
	//Maintenant go check si les dieses sont bien collés(serrés) entre eux
}

void	ft_split_tetriminos(t_fillit *fillit)
{
	while (1)
	{
		if (fillit->countlines < 4 && fillit->counttetri < 26
			&& (fillit->lenline = read(fillit->fd, fillit->line, 5))
			&& ft_strlen(fillit->line) == 5 && fillit->line[4] == '\n')
		{
			ft_strncpy(fillit->tetri[fillit->counttetri]
				[fillit->countlines++], fillit->line, 4);
			ft_strclr(fillit->line);
		}
		else if (fillit->countlines == 4
			&& (fillit->lenline = read(fillit->fd, fillit->line, 1))
			&& ft_strlen(fillit->line) == 1 && fillit->line[0] == '\n')
		{
			fillit->countlines = 0;
			++fillit->counttetri;
		}
		else if (!fillit->lenline)
			break ;
		else
			exit (-1);
	}
	if (fillit->countlines != 4)
		exit (-1);
	ft_check_carac_tetriminos(fillit);
}

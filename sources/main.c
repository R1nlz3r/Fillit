/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlanduyt <vlanduyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:25:51 by vlanduyt          #+#    #+#             */
/*   Updated: 2017/02/03 11:37:27 by vlanduyt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				ft_exit(void)
{
	ft_putendl("error");
	exit(-1);
}

static t_fillit		*ft_init_fillit(t_fillit *f, char **argv)
{
	if (!(f = ft_memalloc(sizeof(t_fillit)))
		|| (f->fd = open(argv[1], 2)) == -1
		|| read(f->fd, 0, 0) || !(f->buf = ft_strnew(5)))
		ft_exit();
	ft_bzero(f->tetri, sizeof(f->tetri));
	ft_tabfill(f->postetrix, 4, 26);
	ft_tabfill(f->postetriy, 4, 26);
	ft_tabfill(f->mapx, 0, 26);
	ft_tabfill(f->mapy, 0, 26);
	f->lenline = 0;
	f->tet = 0;
	f->line = 0;
	f->carac = 0;
	f->sharp = 0;
	f->map = NULL;
	f->mapsize = 2;
	f->booltetonmap = 0;
	return (f);
}

int					main(int argc, char **argv)
{
	t_fillit	*f;

	f = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: fillit target_file");
		exit(-1);
	}
	f = ft_init_fillit(f, argv);
	ft_split_tetriminos(f);
	return (0);
}

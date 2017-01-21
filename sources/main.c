/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlanduyt <vlanduyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:25:51 by vlanduyt          #+#    #+#             */
/*   Updated: 2017/01/21 19:15:33 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_fillit		*ft_init_fillit(t_fillit *fillit, char **argv)
{
	if (!(fillit = ft_memalloc(sizeof(t_fillit)))
		|| (fillit->fd = open(argv[1], 2)) == -1
		|| !(fillit->tetri = ft_memalloc(sizeof(t_fillit_tetri))))
		exit(-1);
	fillit->tetristart = NULL;
	fillit->countlines = 0;
	fillit->counttetri = 0;
	return (fillit);
}

int		main(int argc, char **argv)
{
	t_fillit	*fillit;

	fillit = NULL;
	if (argc != 2)
	{
		ft_putendl("usage: fillit target_file");
		exit(-1);
	}
	fillit = ft_init_fillit(fillit, argv);
	ft_split_tetriminos(fillit);
	return (0);
}

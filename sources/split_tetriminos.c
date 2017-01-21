/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_tetriminos.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlanduyt <vlanduyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 19:41:48 by vlanduyt          #+#    #+#             */
/*   Updated: 2017/01/21 19:18:09 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_split_tetriminos(t_fillit *fillit)
{
	while ((get_next_line(fillit->fd, &fillit->line)))
	{
		if (fillit->countlines < 5 && ft_strlen(fillit->line) == 4
			&& fillit->counttetri < 26)
		{
			if (fillit->countlines == 0
				&& !(fillit->tetri->piece = ft_memalloc(sizeof(char**) * 4)))
				exit (-1);
			fillit->tetri->piece[fillit->countlines] = ft_strdup(fillit->line);
			++fillit->countlines;
		}
		else if (fillit->countlines == 4 && !fillit->line[0])
		{
			fillit->countlines = 0;
			if (!fillit->tetristart)
				fillit->tetristart = fillit->tetri;
			if (!(fillit->tetri->next = ft_memalloc(sizeof(t_fillit_tetri*))))
				exit (-1);
			fillit->tetri = fillit->tetri->next;
			++fillit->counttetri;
		}
		else
			exit (-1);
	}
	//go check si les tériminos sont bien des tétriminos
	//+ si tous les caractères sont bien formatés
	//(ça pourrait être utile)
	//check si \n final en plus --> erreur
}

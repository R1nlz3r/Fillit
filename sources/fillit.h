/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlanduyt <vlanduyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:17:22 by vlanduyt          #+#    #+#             */
/*   Updated: 2017/01/30 11:10:29 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct				s_fillit
{
	int						fd;
	char					*buf;
	int						lenline;
	char					tetri[26][4][4];
	int						postetrix[26];
	int 					postetriy[26];
	int						tet;
	int						line;
	int						carac;
	int						sharp;
	int						mapsize;
	int						mapx;
	int						mapy;
	char					**map;
	int						booltetonmap;
}							t_fillit;

void	ft_find_solution(t_fillit *f);
void	ft_exit(void);
void	ft_split_tetriminos(t_fillit *f);

#endif

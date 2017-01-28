/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlanduyt <vlanduyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:17:22 by vlanduyt          #+#    #+#             */
/*   Updated: 2017/01/28 04:36:20 by mapandel         ###   ########.fr       */
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
	int						tet;
	int						line;
	int						carac;
	int						sharp;
}							t_fillit;

void	ft_exit(void);
void	ft_split_tetriminos(t_fillit *fillit);

#endif

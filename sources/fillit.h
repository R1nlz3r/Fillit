/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlanduyt <vlanduyt@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 17:17:22 by vlanduyt          #+#    #+#             */
/*   Updated: 2017/01/12 15:14:14 by mapandel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct				s_fillit_tetri
{
	char					**piece;
	struct s_fillit_tetri	*next;
}							t_fillit_tetri;

typedef struct				s_fillit
{
	int						fd;
	t_fillit_tetri			*tetri;
	char					*line;
	int						countlines;
	int						counttetri;
}							t_fillit;

void	ft_split_tetriminos(t_fillit *fillit);

#endif

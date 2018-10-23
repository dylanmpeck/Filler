/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:13:38 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/22 21:26:26 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FILLER_H
# define _FILLER_H
# include "libft.h"
# include <fcntl.h>

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_piece
{
	int			height;
	int			width;
	int			size;
	int			first_turn;
	int			**heat;
	char		**data;
}				t_piece;

typedef	struct	s_player
{
	char		id;
	t_point		start;
}				t_player;

typedef	struct	s_filler
{
	t_player	player;
	t_player	enemy;
	t_point		point;
	t_piece		piece;
	t_piece		board;
	int			distance;
	int			total_heat;
	int			valid;
}				t_filler;

void			store_adj_val(t_piece *board, t_point pos,
								int distance, char enemy);
void			store_values(t_piece *board, int i, int j, char enemy);
void			create_heat_map(t_piece *board);
void			update_heat_map(t_piece *board, t_player enemy);
void			check_validity(t_filler *filler, int i, int j);
void			place(t_filler filler);
#endif

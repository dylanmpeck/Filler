/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_validity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:11:58 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/22 21:25:27 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	piece_not_valid(char board_pos, char piece_pos, char enemy)
{
	if (board_pos == '\0')
		return (1);
	if ((board_pos == enemy || board_pos == enemy + 32) && piece_pos != '.')
		return (1);
	return (0);
}

static int	check_piece(t_filler *filler, int i, int j)
{
	int		k;
	int		m;
	int		pid_count;

	pid_count = 0;
	k = 0;
	while (k < filler->piece.height)
	{
		m = 0;
		while (m < filler->piece.width)
		{
			if (piece_not_valid(filler->board.data[i + k][j + m],
						filler->piece.data[k][m], filler->enemy.id))
				return (0);
			if ((filler->board.data[i + k][j + m] == filler->player.id ||
					filler->board.data[i + k][j + m] == filler->player.id + 32)
					&& filler->piece.data[k][m] == '*')
				pid_count++;
			if (filler->piece.data[k][m] != '.')
				filler->distance += filler->board.heat[i + k][j + m];
			m++;
		}
		k++;
	}
	return (pid_count);
}

void		check_validity(t_filler *filler, int i, int j)
{
	int		pid_count;

	filler->distance = 0;
	if (i + filler->piece.height > filler->board.height
			|| j + filler->piece.width > filler->board.width)
		return ;
	pid_count = check_piece(filler, i, j);
	if (pid_count == 1)
	{
		filler->valid = 1;
		if (filler->distance < filler->total_heat)
		{
			filler->total_heat = filler->distance;
			filler->point.x = i;
			filler->point.y = j;
		}
	}
}

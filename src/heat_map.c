/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:04:38 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/22 21:22:55 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	store_values(t_piece *board, int i, int j, char enemy)
{
	int		distance;
	int		count;
	t_point	pos;

	board->heat[i][j] = 0;
	distance = 1;
	pos.x = i;
	pos.y = j;
	count = (board->height > board->width ? board->height : board->width);
	while (count > 0)
	{
		store_adj_val(board, pos, distance, enemy);
		distance++;
		count--;
	}
}

void	update_heat_map(t_piece *board, t_player enemy)
{
	int		i;
	int		j;

	i = 0;
	while (i < board->height)
	{
		j = 0;
		while (j < board->width)
		{
			if (board->data[i][j] == enemy.id + 32
				|| board->data[i][j] == enemy.id)
				store_values(board, i, j, enemy.id);
			j++;
		}
		i++;
	}
}

void	create_heat_map(t_piece *board)
{
	int		i;

	i = 0;
	board->heat = (int **)malloc(board->height * sizeof(int *));
	while (i < board->height)
	{
		board->heat[i] = (int *)malloc(board->width * sizeof(int));
		ft_memset(board->heat[i], 0, sizeof(board->heat[i]));
		i++;
	}
}

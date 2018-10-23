/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adjacent_values.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 19:35:32 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/22 21:22:29 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	store_below(t_piece *board, t_point pos, int distance, char enemy)
{
	int		index;

	index = 0;
	while (index <= distance)
	{
		if (pos.y - index >= 0)
			if (board->data[pos.x + distance][pos.y - index] != enemy &&
				board->data[pos.x + distance][pos.y - index] != enemy + 32)
				if (distance < board->heat[pos.x + distance][pos.y - index]
						|| board->first_turn)
					board->heat[pos.x + distance][pos.y - index] = distance;
		index++;
	}
	index = 0;
	while (index <= distance)
	{
		if (pos.y + index < board->width)
			if (board->data[pos.x + distance][pos.y + index] != enemy &&
				board->data[pos.x + distance][pos.y + index] != enemy + 32)
				if (distance < board->heat[pos.x + distance][pos.y + index]
					|| board->first_turn)
					board->heat[pos.x + distance][pos.y + index] = distance;
		index++;
	}
}

static void	store_above(t_piece *board, t_point pos, int distance, char enemy)
{
	int		index;

	index = 0;
	while (index <= distance)
	{
		if (pos.y - index >= 0)
			if (board->data[pos.x - distance][pos.y - index] != enemy &&
				board->data[pos.x - distance][pos.y - index] != enemy + 32)
				if (distance < board->heat[pos.x - distance][pos.y - index]
						|| board->first_turn)
					board->heat[pos.x - distance][pos.y - index] = distance;
		index++;
	}
	index = 0;
	while (index <= distance)
	{
		if (pos.y + index < board->width)
			if (board->data[pos.x - distance][pos.y + index] != enemy &&
				board->data[pos.x - distance][pos.y + index] != enemy + 32)
				if (distance < board->heat[pos.x - distance][pos.y + index]
						|| board->first_turn)
					board->heat[pos.x - distance][pos.y + index] = distance;
		index++;
	}
}

static void	store_left(t_piece *board, t_point pos, int distance, char enemy)
{
	int		index;

	index = 0;
	while (index <= distance)
	{
		if (pos.x - index >= 0)
			if (board->data[pos.x - index][pos.y - distance] != enemy &&
				board->data[pos.x - index][pos.y - distance] != enemy + 32)
				if (distance < board->heat[pos.x - index][pos.y - distance]
						|| board->first_turn)
					board->heat[pos.x - index][pos.y - distance] = distance;
		index++;
	}
	index = 0;
	while (index <= distance)
	{
		if (pos.x + index < board->height)
			if (board->data[pos.x + index][pos.y - distance] != enemy &&
				board->data[pos.x + index][pos.y - distance] != enemy + 32)
				if (distance < board->heat[pos.x + index][pos.y - distance]
						|| board->first_turn)
					board->heat[pos.x + index][pos.y - distance] = distance;
		index++;
	}
}

static void	store_right(t_piece *board, t_point pos, int distance, char enemy)
{
	int		index;

	index = 0;
	while (index <= distance)
	{
		if (pos.x - index >= 0)
			if (board->data[pos.x - index][pos.y + distance] != enemy &&
				board->data[pos.x - index][pos.y + distance] != enemy + 32)
				if (distance < board->heat[pos.x - index][pos.y + distance]
						|| board->first_turn)
					board->heat[pos.x - index][pos.y + distance] = distance;
		index++;
	}
	index = 0;
	while (index <= distance)
	{
		if (pos.x + index < board->height)
			if (board->data[pos.x + index][pos.y + distance] != enemy &&
				board->data[pos.x + index][pos.y + distance] != enemy + 32)
				if (distance < board->heat[pos.x + index][pos.y + distance]
						|| board->first_turn)
					board->heat[pos.x + index][pos.y + distance] = distance;
		index++;
	}
}

void		store_adj_val(t_piece *board, t_point pos, int distance, char enemy)
{
	int		index;

	index = 0;
	if (pos.x + distance < board->height)
		store_below(board, pos, distance, enemy);
	if (pos.x - distance >= 0)
		store_above(board, pos, distance, enemy);
	if (pos.y - distance >= 0)
		store_left(board, pos, distance, enemy);
	if (pos.y + distance < board->width)
		store_right(board, pos, distance, enemy);
}

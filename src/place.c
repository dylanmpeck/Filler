/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 21:17:47 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/22 21:34:56 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	free_data(t_filler *filler)
{
	int		i;

	i = 0;
	while (i < filler->board.height)
	{
		ft_strdel(&filler->board.data[i]);
		free(filler->board.heat[i]);
		i++;
	}
	free(filler->board.data);
	filler->board.data = NULL;
	free(filler->board.heat);
	i = 0;
	while (i < filler->piece.height)
	{
		ft_strdel(&filler->piece.data[i]);
		i++;
	}
	free(filler->piece.data);
	filler->piece.data = NULL;
}

static void	print_coordinates(t_filler filler)
{
	if (filler.valid)
	{
		ft_putnbr(filler.point.x);
		ft_putchar(' ');
		ft_putnbr(filler.point.y);
		ft_putchar('\n');
	}
	if (filler.valid == 0)
	{
		free_data(&filler);
		ft_putstr("0 0\n");
		exit(0);
	}
}

void		place(t_filler filler)
{
	int		i;
	int		j;

	i = 0;
	filler.valid = 0;
	filler.total_heat = 10000000;
	while (i < filler.board.height)
	{
		j = 0;
		while (j < filler.board.width)
		{
			check_validity(&filler, i, j);
			j++;
		}
		i++;
	}
	print_coordinates(filler);
}

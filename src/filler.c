/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpeck <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 15:17:14 by dpeck             #+#    #+#             */
/*   Updated: 2018/10/22 21:22:46 by dpeck            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	free_piece(t_piece **piece)
{
	int		i;

	i = 0;
	if ((*piece)->data == NULL)
		return ;
	while (i < (*piece)->height)
	{
		ft_strdel(&((*piece)->data[i]));
		i++;
	}
	free((*piece)->data);
	(*piece)->data = NULL;
}

static void	get_info(char *line, int pad, t_piece *piece)
{
	int		i;

	i = 0;
	free_piece(&piece);
	line = ft_strchr(line, ' ') + 1;
	piece->height = ft_atoi(line);
	piece->width = ft_atoi(ft_strchr(line, ' '));
	piece->size = piece->height * piece->width;
	if (pad > 0)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	piece->data = ft_memalloc(piece->height * sizeof(char *));
	while (i < piece->height)
	{
		get_next_line(0, &line);
		piece->data[i] = ft_strsub(line, pad, piece->width);
		i++;
		ft_strdel(&line);
	}
}

static void	find_start(t_filler *filler)
{
	int		i;
	int		j;

	i = 0;
	while (i < filler->board.height)
	{
		j = 0;
		while (j < filler->board.width)
		{
			if (filler->board.data[i][j] == filler->player.id)
			{
				filler->player.start.x = i;
				filler->player.start.y = j;
			}
			if (filler->board.data[i][j] == filler->enemy.id)
			{
				filler->enemy.start.x = i;
				filler->enemy.start.y = j;
			}
			j++;
		}
		i++;
	}
}

static void	game_loop(t_filler filler)
{
	char	*line;
	int		ret;

	filler.board.first_turn = 1;
	while ((ret = get_next_line(0, &line)) > -1)
	{
		if (!ft_strncmp(line, "Plateau ", 8))
		{
			get_info(line, 4, &filler.board);
			if (filler.board.first_turn)
				find_start(&filler);
			if (filler.board.first_turn)
				create_heat_map(&filler.board);
			update_heat_map(&filler.board, filler.enemy);
			filler.board.first_turn = 0;
		}
		if (!ft_strncmp(line, "Piece ", 6))
		{
			get_info(line, 0, &filler.piece);
			place(filler);
		}
		ft_strdel(&line);
	}
}

int			main(void)
{
	t_filler	filler;
	char		*line;

	ft_bzero(&filler, sizeof(t_filler));
	if (get_next_line(0, &line) && line && ft_strlen(line) > 10
		&& !ft_strncmp(line, "$$$ exec p", 9) && (line[10] == '1'
				|| line[10] == '2'))
	{
		filler.player.id = (line[10] == '1' ? 'O' : 'X');
		filler.enemy.id = (line[10] == '1' ? 'X' : 'O');
		ft_strdel(&line);
		game_loop(filler);
	}
	else
		return (1);
	return (0);
}

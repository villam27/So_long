/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:49:37 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/18 13:39:50 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"

t_game_data	*ini_game(t_ilx_window *win, t_ilx_renderer *ren, t_game_input *in)
{
	t_game_data	*game;

	game = malloc(sizeof(t_game_data));
	if (!game)
		return (NULL);
	game->win = win;
	game->ren = ren;
	game->inputs = in;
	game->player = create_player();
	game->levels = NULL;
	return (game);
}

void		addlevel_game(t_game_data **game, t_level_data *level)
{
	if ((*game)->levels)
		free_level((*game)->levels);
	(*game)->levels = create_level(*game);
}

void	close_game(t_game_data *game)
{
	destroy_player(game->player);
	ilx_destroy_renderer(game->win, game->ren);
	ilx_destroy_window(game->win);
	//remove levels
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 11:49:37 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/29 17:33:50 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"

static t_game_data	*create_game(t_ilx_window *win, t_ilx_renderer *ren,
	t_game_input *in)
{
	t_game_data	*game;

	game = malloc(sizeof(t_game_data));
	if (!game)
		return (NULL);
	game->win = win;
	game->ren = ren;
	game->inputs = in;
	game->background = NULL;
	game->player = NULL;
	game->hud = NULL;
	game->enemies = NULL;
	game->levels = NULL;
	return (game);
}

t_game_data	*ini_game(t_ilx_window *win, t_ilx_renderer *ren, t_game_input *in,
	char *path)
{
	t_game_data	*game;

	game = create_game(win, ren, in);
	if (!game)
		return (NULL);
	game->levels = create_level(path, win);
	if (!game->levels)
		return (close_game(game), NULL);
	game->player = create_player(game, game->levels->map->data->player_pos.x,
			game->levels->map->data->player_pos.y);
	if (!game->player)
		return (close_game(game), NULL);
	game->background = ilx_create_texture(win, "assets/bg.xpm");
	if (!game->background)
		return (close_game(game), NULL);
	game->hud = init_hud(win);
	if (!game->hud)
		return (close_game(game), NULL);
	game->enemies = create_enemies(game->levels->map->data->enemies, win);
	if (!game->enemies)
		return (close_game(game), NULL);
	set_all_pos(game);
	return (game);
}

void	close_game(t_game_data *game)
{
	if (game->player)
		destroy_player(game->player, game->win);
	if (game->levels)
		free_level(game);
	if (game->background)
		ilx_destroy_texture(game->win, game->background);
	if (game->hud)
		destroy_hud(game->win, game->hud);
	if (game->enemies)
		destroy_enemies(game->enemies, game->win);
	ilx_destroy_renderer(game->win, game->ren);
	ilx_destroy_window(game->win);
	free(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 01:10:24 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/26 18:14:19 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"

void	input(t_game_data *game)
{
	player_input(game);
}

void	update(t_game_data *game)
{
	player_update(game);
	level_update(game);
}

void	render(t_game_data *game)
{
	char	*step;

	ilx_clear_renderer(game->ren, game->levels->camera_offsets.x,
		game->levels->camera_offsets.y);
	ilx_draw_texture(game->ren, -game->levels->camera_offsets.x,
		-game->levels->camera_offsets.y, game->background);
	level_render(game);
	player_render(game);
	ilx_draw_px(game->ren, 10, 10, 0xff0000);
	mlx_put_image_to_window(game->win->mlx, game->win->mlx_win,
		game->ren->img, game->levels->camera_offsets.x,
		game->levels->camera_offsets.y);
	mlx_string_put(game->win->mlx, game->win->mlx_win,
		20, 20, 0xfffff, "MOVEMENTS:");
	step = ft_itoa(game->player->steps);
	mlx_string_put(game->win->mlx, game->win->mlx_win, 80, 20, 0xfffff, step);
	free(step);
}

int	win_close(t_game_data *game)
{
	close_game(game);
	exit(EXIT_SUCCESS);
	return (0);
}

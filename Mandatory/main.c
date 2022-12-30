/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alboudje <alboudje@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:55:09 by alboudje          #+#    #+#             */
/*   Updated: 2022/12/30 15:30:02 by alboudje         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "player.h"
#include "map.h"

static int	next_frame(t_game_data *data)
{
	if (data->inputs->exit)
		win_close(data);
	input(data);
	update(data);
	render(data);
	return (0);
}

static void	init_input(t_game_input *in)
{
	in->down = 0;
	in->up = 0;
	in->left = 0;
	in->right = 0;
	in->exit = 0;
	in->jetpack = 0;
}

static int	init_all(t_game_data **game, t_game_input *in, char *path)
{
	t_ilx_window	*win;
	t_ilx_renderer	*ren;

	init_input(in);
	win = ilx_create_window(800, 600, "so_long");
	if (!(win))
		return (1);
	ren = ilx_create_renderer(win);
	if (!(ren))
	{
		ilx_destroy_window(win);
		return (1);
	}
	*game = ini_game(win, ren, in, path);
	if (*game)
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game_input	inputs;
	t_game_data		*game;
	char			*ext;
	t_map			*map;

	ext = NULL;
	map = NULL;
	if (argc == 2)
	{
		map = open_map(argv[1]);
		ext = ft_strrchr(argv[1], '.');
	}
	if (map && ext && !ft_strncmp(".ber", ext, 5)
		&& !init_all(&game, &inputs, argv[1]))
	{
		destroy_map(map);
		mlx_hook(game->win->mlx_win, 17, 0, win_close, game);
		mlx_hook(game->win->mlx_win, 2, 1L << 0, input_key_down, &inputs);
		mlx_hook(game->win->mlx_win, 3, 1L << 1, input_key_up, &inputs);
		mlx_loop_hook(game->win->mlx, next_frame, game);
		mlx_loop(game->win->mlx);
	}
	destroy_map(map);
	ft_putstr_fd("Error: restart the game with valid map or path!\n", 2);
	return (EXIT_FAILURE);
}

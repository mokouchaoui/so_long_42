/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:13:10 by mokoucha          #+#    #+#             */
/*   Updated: 2022/04/21 03:13:12 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int ac, char **av)
{
	t_data	game;

	if (check_norm_arg_is_ok(ac, av[1], &game) == 0)
		write_error_type(&game);
	game.mlx = mlx_init();
	define_all_png_to_image(&game);
	game.error = NO_ERROR;
	game.player.countmove = 0;
	parsing_map(&game, av[1]);
	game.map.leny = (ft_strlen(game.map.tile) / game.map.lenx);
	game.img_width = game.sizetile * game.map.lenx;
	game.img_height = game.sizetile * game.map.leny;
	game.windows = mlx_new_window(game.mlx, game.img_width,
			game.img_height, "so_long");
	game.img = mlx_new_image(game.mlx, game.img_width, game.img_height);
	push_tile_to_win(&game);
	mlx_hook(game.windows, X_EVENT_KEY_PRESS, 0, key_hook, &game);
	mlx_hook(game.windows, X_EVENT_KEY_EXIT, 0, exit_normal, &game);
	mlx_loop (game.mlx);
	free(game.map.tile);
	return (0);
}

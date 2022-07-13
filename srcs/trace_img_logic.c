/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace_img_logic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:12:18 by mokoucha          #+#    #+#             */
/*   Updated: 2022/04/21 03:12:27 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	trace_player_to_win(t_data *game, int posx, int posy, int i)
{
	int	hpng;

	hpng = game->sizetile;
	mlx_put_image_to_window(game->mlx, game->windows, \
				game->player.png.img, hpng * posx, hpng * posy);
	game->player.posi = i;
	game->player.posx = posx;
	game->player.posy = posy;
	return (0);
}

int	pttw_norm(t_data *game, int posx, int posy, int index)
{
	int	sizepng;

	sizepng = game->sizetile;
	if (game->map.tile[index] != GROUND)
		mlx_put_image_to_window(game->mlx, game->windows,
			game->wall.img, sizepng * posx, sizepng * posy);
	if (game->map.tile[index] != WALL)
		mlx_put_image_to_window(game->mlx, game->windows,
			game->ground.img, sizepng * posx, sizepng * posy);
	if (game->map.tile[index] == ITEM)
		mlx_put_image_to_window(game->mlx, game->windows,
			game->item.img, sizepng * posx, sizepng * posy);
	else if (game->map.tile[index] == DOOR)
		mlx_put_image_to_window(game->mlx, game->windows,
			game->door.img, sizepng * posx, sizepng * posy);
	else if (game->map.tile[index] == PLAYER)
		trace_player_to_win(game, posx, posy, index);
	return (0);
}

int	push_tile_to_win(t_data *game)
{
	int		posx;
	int		posy;
	int		index;
	int		sizepng;

	sizepng = game->sizetile;
	posx = 0;
	posy = 0;
	index = 0;
	while (game->map.tile[index])
	{
		if (posx == game->map.lenx)
		{
			posx = 0;
			posy++;
		}
		pttw_norm(game, posx, posy, index);
		posx++;
		index++;
	}
	return (0);
}

int	push_windows(t_data *game)
{
	push_tile_to_win(game);
	return (0);
}

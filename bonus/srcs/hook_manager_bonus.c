/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_manager_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:32:15 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:34:54 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	player_move_counter(t_data *game)
{
	game->player.countmove++;
	ft_putnbr(game->player.countmove);
	ft_putchar('\n');
	put_counter_in_windows(game, ft_itoa(game->player.countmove));
}

int	collision_management(t_data *game, int target)
{
	int	nb_item;

	nb_item = ft_str_search_char(game->map.tile, ITEM);
	if (game->map.tile[target] != WALL && game->map.tile[target] != DOOR \
		&& game->map.tile[target] != ENEMY)
	{
		game->map.tile[game->player.posi] = GROUND;
		game->map.tile[target] = PLAYER;
		push_tile_to_win(game);
		player_move_counter(game);
	}
	else if (game->map.tile[target] == DOOR)
	{
		if (nb_item <= 0)
		{
			player_move_counter(game);
			exit_normal(game);
		}
	}
	else if (game->map.tile[target] == ENEMY)
	{
		player_move_counter(game);
		exit_gameover(game);
	}
	return (0);
}

int	key_hook(int kc, t_data *game)
{
	int	target;

	target = 0;
	if (kc == touch_w || kc == touch_up)
		target = game->player.posi - game->map.lenx;
	else if (kc == touch_s || kc == touch_down)
		target = game->player.posi + game->map.lenx;
	else if (kc == touch_d || kc == touch_right)
		target = game->player.posi + 1;
	else if (kc == touch_a || kc == touch_left)
		target = game->player.posi - 1;
	else if (kc == touch_esc)
		exit_normal(game);
	collision_management(game, target);
	return (0);
}

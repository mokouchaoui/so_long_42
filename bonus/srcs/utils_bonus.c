/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 05:39:44 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:49:46 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/**
 * @brief Prend une str et cherche si le char c est dedans
 * 
 * @param str 
 * @param c 
 * @return int return number result
 */
int	ft_str_search_char(char *str, char c)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (str[i])
	{
		if (str[i] == c)
			counter++;
		i++;
	}
	if (counter > 0)
		return (counter);
	return (0);
}

int	exit_normal(t_data *game)
{
	free(game->map.tile);
	mlx_destroy_image(game->mlx, game->img);
	mlx_destroy_window(game->mlx, game->windows);
	exit (0);
}

int	exit_gameover(t_data *game)
{
	int	center_x;
	int	center_y;

	center_x = ((game->map.lenx * game->sizetile) / 2);
	center_y = ((game->map.leny * game->sizetile) / 2);
	ft_putstr("GAME OVER\n");
	mlx_string_put(game->mlx, game->windows, center_x - 100, center_y, \
	0xffff0000, "GAME OVER ");
	mlx_do_sync(game->mlx);
	usleep(750000);
	exit_normal(game);
	return (0);
}

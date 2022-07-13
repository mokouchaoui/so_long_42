/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:12:10 by mokoucha          #+#    #+#             */
/*   Updated: 2022/04/21 03:12:24 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

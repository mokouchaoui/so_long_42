/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch_mlx_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:32:42 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:34:54 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/**
 * @brief path mlx for pixel line problem
 * 
 * @param game 
 */
void	patch_mlx(t_data *game)
{
	game->sizetile = game->wall.h - 1;
}

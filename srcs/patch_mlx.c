/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patch_mlx.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:12:36 by mokoucha          #+#    #+#             */
/*   Updated: 2022/04/21 03:12:39 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

/**
 * @brief path mlx for pixel line problem
 * 
 * @param game 
 */
void	patch_mlx(t_data *game)
{
	game->sizetile = game->wall.h - 1;
}

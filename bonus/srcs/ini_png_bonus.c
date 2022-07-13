/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_png_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:32:20 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:34:54 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_if_file_enemy_player_exist(t_data *game)
{
	int	fd;

	fd = open(game->player.png.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
		fd = open(game->enemy.png.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
}

void	check_if_file_exist(t_data *game)
{
	int	fd;

	fd = open(game->ground.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	fd = open(game->wall.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	fd = open(game->door.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	fd = open(game->item.path, O_RDONLY);
	if (fd < 0)
		game->error = ERROR_MISSING_FILE;
	close (fd);
	check_if_file_enemy_player_exist(game);
	if (game->error != NO_ERROR)
		write_error_type(game);
}

static void	filename_path(t_data *game)
{
	ft_strlcpy(game->ground.path, "./srcs/png/ground.png", 28);
	ft_strlcpy(game->wall.path, "./srcs/png/wall.png", 26);
	ft_strlcpy(game->item.path, "./srcs/png/item.png", 26);
	ft_strlcpy(game->door.path, "./srcs/png/door.png", 26);
	ft_strlcpy(game->player.png.path, "./srcs/png/player.png", 28);
	ft_strlcpy(game->enemy.png.path, "./srcs/png/enemy.png", 27);
}

/**
 * @brief save all png file for project in mlx img
 * 
 * @param game 
 */
void	define_all_png_to_image(t_data *game)
{
	game->error = NO_ERROR;
	filename_path(game);
	check_if_file_exist(game);
	game->ground.img = mlx_png_file_to_image(game->mlx, game->ground.path,
			&game->ground.w, &game->ground.h);
	game->wall.img = mlx_png_file_to_image(game->mlx, game->wall.path,
			&game->wall.w, &game->wall.h);
	game->item.img = mlx_png_file_to_image(game->mlx, game->item.path,
			&game->item.w, &game->item.h);
	game->door.img = mlx_png_file_to_image(game->mlx, game->door.path,
			&game->door.w, &game->door.h);
	game->player.png.img = mlx_png_file_to_image(game->mlx,
			game->player.png.path, &game->player.png.w, &game->player.png.h);
	game->enemy.png.img = mlx_png_file_to_image(game->mlx,
			game->enemy.png.path, &game->enemy.png.w, &game->enemy.png.h);
	patch_mlx(game);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:32:36 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:34:54 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

/**
 * @brief fill *tile str with all char map, whitout space or new line
 * 
 * @param game 
 * @param fd
 * @return int 
 */
int	fill_data_map(t_data *game, int fd)
{
	static int		lentmp = 0;
	char			*tmp;

	game->line = get_next_line(fd);
	if (!game->line)
		return (0);
	game->map.lenx = ft_strlen(game->line);
	if (game->line[game->map.lenx - 1] == '\n')
	{
		game->line[game->map.lenx - 1] = '\0';
		game->map.lenx--;
	}
	if (lentmp != game->map.lenx && game->map.bool == 1)
	{
		game->error = ERROR_MAP_NO_RECT;
		write_error_type(game);
	}
	lentmp = game->map.lenx;
	tmp = ft_strdup(game->map.tile);
	free(game->map.tile);
	game->map.tile = ft_strjoin(tmp, game->line);
	free(tmp);
	free(game->line);
	game->map.bool = 1;
	return (0);
}

/**
 * @brief copy toute la map dans game.map.tile
 * et gère la detection des erreurs de file ou mapping 
 *  ATTENTION free game.map.tile a faire
 * @param game 
 * @param pathfile 
 * @return int 
 */
int	parsing_map(t_data	*game, char *pathfile)
{
	int		fd;

	game->map.bool = 0;
	fd = ft_open_file(pathfile, game);
	game->map.tile = ft_strdup("");
	game->map.leny = 1;
	while (1)
	{
		if (fill_data_map(game, fd))
			write_error_type(game);
		if (game->line == NULL)
			break ;
	}
	if (check_chars_is_valid(game) && game->line)
		write_error_type(game);
	if (check_minimum_required(game))
		write_error_type(game);
	if (check_wall_close_map(game, 0))
		write_error_type(game);
	return (0);
}

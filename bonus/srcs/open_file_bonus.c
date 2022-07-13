/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:32:29 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:34:54 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	ft_open_file(char *path, t_data *game)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		game->error = ERROR_MAP_NOT_EXIST;
		write_error_type(game);
	}
	return (fd);
}

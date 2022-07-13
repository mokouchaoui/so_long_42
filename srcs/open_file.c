/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 03:13:02 by mokoucha          #+#    #+#             */
/*   Updated: 2022/04/21 03:13:04 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

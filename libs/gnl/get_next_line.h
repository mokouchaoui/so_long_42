/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokoucha <mokoucha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/15 17:00:26 by mokoucha          #+#    #+#             */
/*   Updated: 2022/05/15 17:00:33 by mokoucha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H 
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char		*get_next_line(int fd);
void		ft_strjoin_gnl(char **dst, char *src1, char *src2, size_t buf_end);
int			ft_buf_process(char *bufp);
int			ft_strichr_nl(char *str);
char		*ft_strdup_gnl(const char *s1);
size_t		ft_strlen_gnl(const char *str);

#endif
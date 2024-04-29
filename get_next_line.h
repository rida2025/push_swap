/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 13:49:45 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/24 12:08:49 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_strchr(char *str, char c);
int		ft_strlenx(char *str);
char	*ft_strjoinx(char *remain, char *buffer);
char	*ft_strdup(char *str);
char	*ft_read_file(int fd, char *remain);
char	*ft_get_line(char *remain);
char	*ft_remove_line(char *remain);

#endif

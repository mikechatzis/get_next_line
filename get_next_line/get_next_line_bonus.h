/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:40:48 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/30 13:48:46 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# define FD_SIZE 4096
# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		retvalcalc(char **s, char **line, int ret, int fd);
int		writeline(char **s, char **line);
void	ft_strdel(char **as);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);

#endif

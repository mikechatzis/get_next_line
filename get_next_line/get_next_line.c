/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:40:45 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/30 13:47:27 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	cx;

	cx = (unsigned char)c;
	while (*s != '\0' && *s != cx)
	{
		s++;
	}
	if (*s == '\0' && cx != '\0')
		return (NULL);
	else
		return ((char *)s);
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}

int	writeline(char **s, char **line)
{
	int		l;
	char	*tmp;

	l = 0;
	while ((*s)[l] != '\n' && (*s)[l])
		l++;
	if ((*s)[l] == '\n')
	{
		*line = ft_substr(*s, 0, l);
		tmp = ft_strdup(&((*s)[l + 1]));
		free(*s);
		*s = tmp;
	}
	else
	{	
		*line = ft_strdup(*s);
		ft_strdel(s);
		return (0);
	}	
	return (1);
}

int	retvalcalc(char **s, char **line, int ret, int fd)
{
	char	*zero;

	zero = "\0";
	if (fd < 0 || line == NULL || ret < 0)
		return (-1);
	if (ret == 0 && s[fd] == NULL)
	{
		*line = ft_strdup(zero);
		return (0);
	}
	else
		return (writeline(&s[fd], line));
}

int	get_next_line(int fd, char **line)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*s[FD_SIZE];
	char		*tmp;
	int			ret;

	ret = 1;
	while (ret > 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		buffer[ret] = '\0';
		if (ret <= 0)
			break ;
		if (s[fd] == NULL)
			s[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(s[fd], buffer);
			free(s[fd]);
			s[fd] = tmp;
		}
		if (ft_strchr(s[fd], '\n'))
			break ;
	}
	return (retvalcalc(s, line, ret, fd));
}

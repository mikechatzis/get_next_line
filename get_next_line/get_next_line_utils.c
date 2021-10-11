/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchatzip <mchatzip@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 13:40:52 by mchatzip          #+#    #+#             */
/*   Updated: 2021/06/30 14:08:34 by mchatzip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *c)
{
	int	len;

	len = 0;
	while (*c != '\0')
	{
		c++;
		len++;
	}
	return (len);
}

void	*ft_memcpy(void *str, const void *c, size_t n)
{
	unsigned char	*arr;
	const char		*i;
	int				k;

	arr = (unsigned char *)str ;
	i = (const char *)c;
	k = 0;
	while (n > 0)
	{
		arr[k] = i[k];
		k++;
		n--;
	}
	arr[k] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	int		i;
	int		k;

	k = 0;
	i = 0;
	cat = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (cat == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{	
		cat[i] = s1[i];
		i++;
	}
	while (s2[k] != '\0')
	{	
		cat[i] = s2[k];
		i++;
		k++;
	}
	cat[i] = '\0';
	return (cat);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;

	i = 0;
	sub = NULL;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (sub);
	if (s[start] == '\0')
	{
		sub[i] = '\0';
		return (sub);
	}
	while (i < len && start < ft_strlen((char *)s))
	{
		sub[i] = s[start];
		start++;
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dst;

	len = ft_strlen(src) + 1;
	dst = malloc((len) + 1);
	if (dst == NULL)
		return (NULL);
	ft_memcpy(dst, src, len);
	return (dst);
}

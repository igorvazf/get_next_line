/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igvaz-fe <igvaz-fe@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 12:02:05 by igvaz-fe          #+#    #+#             */
/*   Updated: 2021/08/20 14:00:16 by igvaz-fe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	dest = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (!dest)
		return (0);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	len;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	j = 0;
	str = malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i++] = s2[j++];
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	slen;

	if (!s)
		return (NULL);
	i = 0;
	slen = ft_strlen(s);
	if (((slen - start) > len) && (start < slen))
		sub = malloc((len * sizeof(char) + 1));
	else if (start > slen)
		sub = malloc(sizeof(char));
	else
		sub = malloc(((slen - start) * sizeof(char) + 1));
	if (!sub)
		return (NULL);
	if ((start < slen))
	{
		while ((i < len) && s[start])
			sub[i++] = s[start++];
	}
	sub[i] = '\0';
	return (sub);
}

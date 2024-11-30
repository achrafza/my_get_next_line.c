/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:46:37 by azahid            #+#    #+#             */
/*   Updated: 2024/11/30 17:59:33 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdarg.h>
#include <libc.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	int				i;
	unsigned int	l;

	l = ft_strlen(s);
	if (s == NULL && len < l)
		return (NULL);
	if (len > l - start)
		len = l - start;
	if (l <= start)
		return (ft_strdup(""));
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (len-- && *(s + start))
	{
		*(str + i) = *(s + start);
		i++;
		s++;
	}
	*(str + i) = 0;
	return (str);
}

char	*newstr(char *str, int i)
{
	int		len;
	char	*new;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	new = ft_substr(str, i + 1, len);
	if (!new)
		return (free(str), str = NULL);
	free(str);
	return (new);
}

char	*qssem(int *value, char *str, int fd, int *i)
{
	char	*temp;
	char	*ss;

	ss = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ss)
		return (free(str), str = NULL);
	*value = read(fd, ss, BUFFER_SIZE);
	ss[*value] = 0;
	temp = ft_strjoin(str, ss);
	if (!temp)
		return (free(ss), free(str), str = NULL);
	free(ss);
	ss = NULL;
	free(str);
	*i = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str;
	char		*temp;
	int			i;
	int			value;

	while (fd >= 0 && BUFFER_SIZE > 0 && read(fd, NULL, 0) >= 0)
	{
		str = qssem(&value, str, fd, &i);
		if (!str)
			return (NULL);
		while (str[i] && str[i] != '\n')
			i++;
		if (str[i] == '\n')
		{
			temp = ft_substr(str, 0, i + 1);
			if (!(temp))
				return (free(str), str = NULL);
			return (str = newstr(str, i), temp);
		}
		if (value <= 0 && *str)
			return (temp = ft_strdup(str), free(str), str = NULL, temp);
		if (value <= 0 && !*str)
			return (free(str), str = NULL, NULL);
	}
	return (free(str), str = NULL);
}

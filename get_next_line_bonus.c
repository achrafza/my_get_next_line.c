/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:23:43 by azahid            #+#    #+#             */
/*   Updated: 2024/12/07 02:23:44 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <stdarg.h>
#include <libc.h>
#include <limits.h>

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

char	*qssem(int *value, char *str[], int fd, int *i)
{
	char	*temp;
	char	*ss;

	ss = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!ss)
		return (free(str[fd]), str[fd] = NULL);
	*value = read(fd, ss, BUFFER_SIZE);
	ss[*value] = 0;
	temp = ft_strjoin(str[fd], ss);
	if (!temp)
		return (free(ss), free(str[fd]), str[fd] = NULL);
	free(ss);
	ss = NULL;
	free(str[fd]);
	*i = 0;
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*t;
	int			i;
	int			value;

	while (fd >= 0 && BUFFER_SIZE > 0 && read(fd, NULL, 0) >= 0)
	{
		str[fd] = qssem(&value, str, fd, &i);
		if (!str[fd])
			return (NULL);
		while (str[fd][i] && str[fd][i] != '\n')
			i++;
		if (str[fd][i] == '\n')
		{
			t = ft_substr(str[fd], 0, i + 1);
			if (!(t))
				return (free(str[fd]), str[fd] = NULL);
			return (str[fd] = newstr(str[fd], i), t);
		}
		if (value <= 0 && *str[fd])
			return (t = ft_strdup(str[fd]), free(str[fd]), str[fd] = NULL, t);
		if (value <= 0 && !*str[fd])
			return (free(str[fd]), str[fd] = NULL, NULL);
	}
	return (free(str[fd]), str[fd] = NULL);
}

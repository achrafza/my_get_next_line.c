/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:46:37 by azahid            #+#    #+#             */
/*   Updated: 2024/11/19 03:22:16 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include<stdio.h>
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
char *newstr(char * str,int i)
{
    int len = ft_strlen(str);
    char *new = ft_substr(str,i+1,len - i - 1);
    free(str);
    return new;
}
char    *get_next_line(int fd)
{
    static char *str;
    char        ss[BUFFER_SIZE + 1];
    char        *temp;
    int         i = 0;
    int         value = 1;

    if(!str)
        str = ft_strdup("");
    while (fd >= 0 && BUFFER_SIZE > 0 && value)
    {
        i = 0;
        value = read(fd, ss, BUFFER_SIZE);
        if(value < 0)
            return NULL;
        ss[value] = 0;
        temp = ft_strjoin(str,ss);
        free(str);
        str = temp;
        while(str[i] && str[i] != '\n')
            i++;
        if(str[i] == '\n')
        {
            if(value == 0)
                return (temp = ft_strdup(str),free(str),str = NULL,temp);
            temp = ft_substr(str, 0, i);
            str = newstr(str,i);
            return temp;
        }
    }
    return NULL;
}


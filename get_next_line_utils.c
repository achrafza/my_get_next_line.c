/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azahid <azahid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 01:44:24 by azahid            #+#    #+#             */
/*   Updated: 2024/11/30 17:55:31 by azahid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			destlen;
	size_t			srclen;

	i = 0;
	j = 0;
	srclen = ft_strlen(src);
	if (size == 0)
		return (srclen);
	destlen = ft_strlen(dest);
	if (size < destlen)
		return (size + srclen);
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0' && i < size - 1)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (destlen + srclen);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	len;

	len = ft_strlen(src);
	if (!dstsize)
		return (len);
	while (--dstsize && *src)
		*(dst++) = *(src++);
	*dst = 0;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		strlen;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return ((char *)ft_strdup(s2));
	if (!s2)
		return ((char *)ft_strdup(s1));
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (!str)
		return (NULL);
	strlen = ft_strlcpy(str, s1, len1 + 1);
	strlen = ft_strlcat(str, s2, len2 + len1 + 1);
	return (str);
}

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*str;

	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	len = 0;
	while (s1[len])
	{
		str[len] = s1[len];
		len++;
	}
	str[len] = 0;
	return (str);
}

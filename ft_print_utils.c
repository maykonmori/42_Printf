/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:41:08 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 19:33:37 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(char *str)
{
	size_t	aux;

	aux = 0;
	while (str[aux])
		++aux;
	return (aux);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	if (!src)
		return (0);
	i = ft_strlen((char *)src);
	if (dstsize)
	{
		while (dstsize && *src)
		{
			*(dst++) = *(src++);
			dstsize--;
		}
		*dst = '\0';
	}
	return (i);
}

char	*ft_strjoin(char const	*s1, char const	*s2)
{
	size_t	ss1;
	size_t	ss2;
	char	*dest;

	if (!s1 || !s2)
		return (NULL);
	ss1 = ft_strlen((char *)s1);
	ss2 = ft_strlen((char *)s2);
	dest = (char *)malloc((ss1 + ss2 + 1) * sizeof(*dest));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, s1, (ss1 + 1));
	ft_strlcpy((dest + ss1), s2, (ss2 + 1));
	return (dest);
}

char	*ft_convert_base(size_t n, char *base)
{
	int		base_len;
	int		len;
	char	*n_base;
	size_t	aux;

	base_len = ft_strlen(base);
	len = 0;
	aux = n;
	if (n == 0)
		len = 1;
	while (aux != 0)
	{
		aux /= base_len;
		len++;
	}
	n_base = (char *)malloc((len + 1) * sizeof(*base));
	if (!n_base)
		return (NULL);
	n_base[len] = '\0';
	while (len--)
	{
		n_base[len] = base[n % (size_t)base_len];
		n /= (size_t)base_len;
	}
	return (n_base);
}

char	*ft_uitoa(unsigned int un)
{
	char			*str;
	int				len;
	unsigned int	n;

	n = un;
	len = 0;
	if (un == 0)
		len = 1;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	str = (char *)malloc((len + 1) * sizeof(*str));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len-- > 0)
	{
		str[len] = (un % 10) + '0';
		un /= 10;
	}
	return (str);
}

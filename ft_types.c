/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:41:11 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 18:04:45 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	type_c(int c)
{
	int aux;

	aux = write(1, &c, sizeof(char));
	return (aux);
}

int	type_s(char *s)
{
	if (!s)
		s = "(null)";
	return (write(1, s, ft_strlen(s) * sizeof(char)));
}

int	type_p(unsigned long p)
{
	char	*str;
	char	*temp;
	int		len;

	str = ft_convert_base(p, "0123456789abcdef");
	temp = str;
	str = ft_strjoin("0x", temp);
	free(temp);
	len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}

int	type_d(int d)
{
	char	*str;
	char	sign;
	int		len;

	sign = 0;
	len = 0;
	if (d < 0)
	{
		str = ft_uitoa(-(long)d);
		sign = 1;
	}
	else
		str = ft_uitoa(d);
	if (sign == 1)
		len += write(1, "-", sizeof(char));
	len += write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}

int	type_ux(unsigned int x, char	*base)
{
	char	*str;
	int		len;

	str = ft_convert_base(x, base);
	len = write(1, str, ft_strlen(str) * sizeof(char));
	free(str);
	return (len);
}

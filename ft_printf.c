/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:41:21 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 19:44:33 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type(va_list arg, char type);

int	ft_printf(const char *format, ...)
{
	va_list	arg;
	int		len;
	int		i;

	va_start(arg, format);
	len = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len += type(arg, format[i]);
		}
		else
			len += write(1, &format[i], 1);
		i++;
	}
	va_end(arg);
	return (len);
}

static int	type(va_list arg, char type)
{
	if (type == 'c')
		return (type_c(va_arg(arg, int)));
	else if (type == 's')
		return (type_s(va_arg(arg, char *)));
	else if (type == 'p')
		return (type_p(va_arg(arg, unsigned long)));
	else if (type == 'd' || type == 'i')
		return (type_d(va_arg(arg, int)));
	else if (type == 'u')
		return (type_ux(va_arg(arg, unsigned int), "0123456789"));
	else if (type == 'x')
		return (type_ux(va_arg(arg, unsigned int), "0123456789abcdef"));
	else if (type == 'X')
		return (type_ux(va_arg(arg, unsigned int), "0123456789ABCDEF"));
	else if (type == '%')
		return (write(1, "%", 1));
	else
		return (0);
}

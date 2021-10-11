/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:42:20 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/10 18:21:01 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	ret;

	puts("____________________\n");
	printf("%s\n", "print original");
	ret = printf("%d\n", 42);
	printf("ret %d\n", ret);
	puts("____________________\n");
	ft_printf("%s\n", "nosso print");
	ret = ft_printf("%d\n", 42);
	ft_printf("ret %d\n", ret);
	return (0);
}

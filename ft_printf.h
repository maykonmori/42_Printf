/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjose-ye <mjose-ye@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 18:41:04 by edpaulin          #+#    #+#             */
/*   Updated: 2021/10/11 19:44:27 by mjose-ye         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

int		type_c(int c);
int		type_s(char *s);
int		type_p(unsigned long p);
int		type_d(int d);
int		type_ux(unsigned int x, char	*base);

size_t	ft_strlen(char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(char const	*s1, char const	*s2);
char	*ft_convert_base(size_t n, char *base);
char	*ft_uitoa(unsigned int un);

#endif

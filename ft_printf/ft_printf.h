/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:15:43 by mjina             #+#    #+#             */
/*   Updated: 2023/02/14 17:16:31 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

char	uitoa(unsigned int n);
int		ft_printf(const char *str, ...);
int		printchar(char c);
int		printstring(char *str);
int		printdecimal(va_list arg);
int		printint(int nbr);
int		printuint(int nbr);
int		printhex(unsigned int nbr, char format);
int		printadress(unsigned long int n, int i);

#endif

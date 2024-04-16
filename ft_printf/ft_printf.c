/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:43:57 by mjina             #+#    #+#             */
/*   Updated: 2023/02/15 13:43:58 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

static int	checkconversion(char c, va_list argument)
{
	if (c == 'c')
		return (printchar(va_arg(argument, int)));
	else if (c == 's')
		return (printstring(va_arg(argument, char *)));
	else if (c == 'p')
		return (printadress(va_arg(argument, unsigned long int), 0));
	else if (c == 'd')
		return (printint(va_arg(argument, int)));
	else if (c == 'i')
		return (printint(va_arg(argument, int)));
	else if (c == 'u')
		return (printuint(va_arg(argument, int)));
	else if (c == 'x')
		return (printhex(va_arg(argument, unsigned int), c));
	else if (c == 'X')
		return (printhex(va_arg(argument, unsigned int), c));
	else if (c == '%')
		return (write(1, "%", 1));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	size_t	i;
	va_list	ap;

	i = 0;
	ret = 0;
	va_start(ap, str);
	while (i < ft_strlen(str))
	{
		if (str[i] == '%')
		{
			ret += checkconversion(str[++i], ap);
			i++;
		}
		else
		{
			write(1, &str[i], 1);
			ret++;
			i++;
		}
	}
	va_end(ap);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_strings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:41:33 by mjina             #+#    #+#             */
/*   Updated: 2023/02/16 13:41:34 by mjina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	printchar(char c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	printstring(char *str)
{
	if (!str)
		str = "(null)";
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	hexlen(unsigned int nbr)
{
	int	i;

	i = 0;
	while (nbr > 0)
	{
		nbr /= 16;
		i++;
	}
	return (i);
}

static void	fillhex(unsigned int nbr, char format)
{
	if (nbr >= 16)
		fillhex(nbr / 16, format);
	if (nbr % 16 <= 9)
		ft_putchar_fd(nbr % 16 + '0', 1);
	else if (format == 'x')
		ft_putchar_fd(nbr % 16 - 10 + 'a', 1);
	else if (format == 'X')
		ft_putchar_fd(nbr % 16 - 10 + 'A', 1);
}

int	printhex(unsigned int nbr, char format)
{
	if (nbr == 0)
		return (write(1, "0", 1));
	else
		fillhex(nbr, format);
	return (hexlen(nbr));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 09:57:06 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/25 18:45:15 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/b_printf.h"

int	ft_puts(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (ft_puts("(null)"));
	while (*(s + i))
		i += ft_putchar(*(s + i));
	return (i);
}

int	ft_putarg(va_list arg)
{
	return (ft_putchar(va_arg(arg, int)));
}

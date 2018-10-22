/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 10:25:09 by dstolz            #+#    #+#             */
/*   Updated: 2018/09/28 10:35:14 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <unistd.h>

void	ft_putstr_fd(const char *s, int fd)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (*(s + i))
			i++;
		write(fd, s, i);
	}
}
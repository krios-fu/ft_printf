/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_punlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:45:45 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/29 19:09:32 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int			ft_hexalen_p(unsigned long nb)
{
	int				count;
	unsigned long	n;

	n = nb;
	count = 0;
	if (n >= 16)
	{
		while (n >= 16)
		{
			++count;
			n /= 16;
		}
	}
	if (n >= 0)
		count++;
	return (count);
}

int					ft_punlen(char *str)
{
	unsigned long	*c;

	c = (unsigned long *)&str;
	return (ft_hexalen_p(*c));
}

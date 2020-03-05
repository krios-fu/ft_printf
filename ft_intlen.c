/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:23:11 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/28 12:42:41 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t	ft_intlen(long nb)
{
	size_t		count;

	count = 0;
	if (nb == 0)
	{
		count++;
		return (count);
	}
	if (nb < 0)
	{
		nb = nb * -1;
		count++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

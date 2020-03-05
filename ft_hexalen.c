/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexalen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:09:48 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/29 16:58:56 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int					ft_hexalen(unsigned long nb)
{
	int				count;
	unsigned int	n;

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

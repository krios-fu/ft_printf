/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/11 17:22:07 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/26 19:19:32 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	l;

	if (n == 0 || dst == src)
		return (dst);
	l = 0;
	while (l < n)
	{
		((char *)dst)[l] = ((char *)src)[l];
		l++;
	}
	return (dst);
}

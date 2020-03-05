/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatolower.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 14:47:13 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/29 19:09:53 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_hexatolower(size_t nb)
{
	size_t	n;
	char	c;

	n = nb;
	if (n >= 16)
		ft_hexatolower(n / 16);
	n = n % 16;
	c = n < 10 ? n + '0' : n + 87;
	ft_putchar_fd(c, 1);
}

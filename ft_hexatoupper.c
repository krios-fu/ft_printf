/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexatoupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 16:04:32 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/29 19:09:24 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		ft_hexatoupper(unsigned int nb)
{
	size_t	n;
	char	c;

	n = nb;
	if (n >= 16)
		ft_hexatoupper(n / 16);
	n = n % 16;
	c = n < 10 ? n + '0' : n + 55;
	ft_putchar_fd(c, 1);
}

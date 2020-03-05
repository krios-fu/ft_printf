/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 17:46:14 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/28 13:04:50 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_putunbr_fd(int n, int fd)
{
	unsigned r;

	r = n;
	if (r > 9)
	{
		ft_putunbr_fd(r / 10, fd);
		ft_putunbr_fd(r % 10, fd);
	}
	else
		ft_putchar_fd(r + '0', fd);
}

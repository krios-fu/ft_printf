/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:50:41 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/29 19:09:26 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_x(t_printf *p, ssize_t x)
{
	int	len;
	int	space;
	int	zero;

	len = ft_hexalen(x);
	space = p->width - ((p->precision <= len) ? len : p->precision);
	space = (p->precision == 0 && p->width > 0 &&
		p->dot == '1') ? p->width : space;
	zero = p->precision - len;
	while (space-- > 0 && p->tab != '-')
		p->len_str += write(1, (p->zero_space != '0' ||
			(p->dot == '1' && p->precision >= 0)) ? " " : "0", 1);
	while (--zero >= 0)
		p->len_str += write(1, "0", 1);
	(x == 0 && p->precision == 0 && p->dot == '1') ? 0 : ft_hexatolower(x);
	while (space-- >= 0)
		p->len_str += write(1, " ", 1);
	p->len_str += len;
	if (x == 0 && p->precision == 0 && p->dot == '1' && p->width >= 0)
		--p->len_str;
}

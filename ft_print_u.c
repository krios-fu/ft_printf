/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 18:16:50 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/28 12:58:54 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_print_u(t_printf *p, int nb)
{
	int			len;
	int			space;
	int			zero;
	unsigned	r;

	r = nb;
	nb = r;
	len = ft_intlen(r);
	space = p->width - ((p->precision <= len) ? len : p->precision);
	zero = p->precision - len;
	space += (nb == 0 && p->precision == 0 &&
		p->dot == '1' && p->width > 0) ? 1 : 0;
	while (space-- > 0 && p->tab != '-')
		p->len_str += write(1, (p->zero_space != '0' ||
			(p->dot == '1' && p->precision >= 0)) ? " " : "0", 1);
	while (--zero >= 0)
		p->len_str += write(1, "0", 1);
	(nb == 0 && p->precision == 0 && p->dot == '1') ? 0 : ft_putunbr_fd(nb, 1);
	while (space-- >= 0)
		p->len_str += write(1, " ", 1);
	p->len_str += len;
	if (nb == 0 && p->precision == 0 && p->dot == '1' && p->width >= 0)
		--p->len_str;
}

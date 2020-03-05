/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_i.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 06:50:48 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/28 12:46:00 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			ft_print_di(t_printf *p, int nb)
{
	int			len;
	int			space;
	int			zero;
	int			flag;

	len = ft_intlen(nb);
	space = p->width - ((p->precision <= len) ? len : p->precision);
	space += (nb == 0 && p->precision == 0
		&& p->dot == '1' && p->width > 0) ? 1 : 0;
	space -= (nb < 0 && p->precision >= len) ? 1 : 0;
	zero = (nb < 0) ? (p->precision - len) + 1 : (p->precision - len);
	flag = (nb < 0 && (space > p->precision && p->zero_space == '0'))
						? write(1, "-", 1) : 0;
	while (space-- > 0 && p->tab != '-')
		p->len_str += write(1, (p->zero_space != '0' ||
			(p->dot == '1' && p->precision >= 0)) ? " " : "0", 1);
	(nb < 0 && flag == 0) ? write(1, "-", 1) : 0;
	while (--zero >= 0)
		p->len_str += write(1, "0", 1);
	(nb == 0 && p->precision == 0 && p->dot == '1') ? 0 : ft_putnbr_fd(nb, 1);
	while (space-- >= 0)
		p->len_str += write(1, " ", 1);
	p->len_str += len;
	if (nb == 0 && p->precision == 0 && p->dot == '1' && p->width >= 0)
		--p->len_str;
}

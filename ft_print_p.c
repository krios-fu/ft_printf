/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 04:40:52 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/28 12:47:37 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"
#include "stdio.h"

void	ft_print_p(t_printf *p, char *str)
{
	int	len;
	int	space;
	int	zero;

	len = ft_punlen(str) + 2;
	space = p->width - ((p->precision <= len) ? len : p->precision);
	space = (p->precision == 0 && p->width > 0
			&& p->dot == '1') ? p->width - 2 : space;
	zero = p->precision - len + 2;
	while (space-- > 0 && p->tab != '-')
		p->len_str += write(1, (p->zero_space != '0' ||
				(p->dot == '1' && p->precision >= 0)) ? " " : "0", 1);
	write(1, "0x", 2);
	while (--zero >= 0)
		p->len_str += write(1, "0", 1);
	(str == NULL && p->precision == 0 && p->dot == '1')
				? 0 : ft_addresspunter(str);
	while (space-- >= 0)
		p->len_str += write(1, " ", 1);
	p->len_str += len;
	if (str == NULL && p->precision == 0 && p->dot == '1' && p->width >= 0)
		--p->len_str;
}

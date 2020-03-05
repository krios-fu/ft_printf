/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:32:05 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/28 12:44:44 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_print_char(t_printf *p, char c)
{
	int	len;
	int	space;
	int	zero;

	len = 1;
	space = p->width - len;
	zero = p->width - len;
	while (space-- > 0 && p->tab != '-')
		p->len_str += write(1, (p->zero_space != '0' ||
			(p->dot == '1' && p->precision >= 0)) ? " " : "0", 1);
	p->len_str += write(1, &c, 1);
	while (space-- >= 0)
		p->len_str += write(1, " ", 1);
}

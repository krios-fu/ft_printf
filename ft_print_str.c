/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 03:47:40 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/28 12:55:40 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*ft_print_str_(char *str)
{
	char	*str1;

	if (str == NULL)
		str1 = ft_strdup("(null)\0");
	else
		str1 = ft_strdup(str);
	return (str1);
}

void		ft_print_str(t_printf *p, char *str)
{
	int		len;
	int		space;
	int		zero;
	char	*str1;

	str1 = ft_print_str_(str);
	len = ft_strlen(str1);
	space = p->width - ((p->precision > 0 &&
		p->precision < len) ? p->precision : len);
	zero = p->precision - len;
	space = (p->precision == 0 && p->width > 0
		&& p->dot == '1') ? p->width : space;
	space = (len == 0 && p->width == 0) ? 0 : space;
	while (space-- > 0 && p->tab != '-')
		p->len_str += write(1, (p->zero_space != '0' ||
			(p->dot == '1' && p->precision >= 0)) ? " " : "0", 1);
	p->len_str += write(1, str1, (len < p->precision ||
		(p->precision == 0 && p->dot != '1')) ? len : p->precision);
	if (p->dot == '1' && p->precision == 0 && p->width == 0)
		p->len_str += write(1, str1, p->precision);
	if (p->dot == '1' && p->precision < 0 && p->width >= 0)
		p->len_str += write(1, str1, len) + 1;
	while (space-- >= 0)
		p->len_str += write(1, " ", 1);
	free(str1);
}

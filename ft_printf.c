/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: krios-fu <krios-fu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:51:14 by krios-fu          #+#    #+#             */
/*   Updated: 2020/02/29 19:09:30 by krios-fu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	ft_setformat_(t_printf *p)
{
	if (ft_isdigit(*p->str) && *p->str != '0'
								&& p->width == 0 && p->dot != '1')
		p->width = ft_atoi(p->str);
	if (*p->str == '.')
	{
		p->dot = '1';
		p->str++;
		if (*p->str == '*')
			p->precision = va_arg(p->ap, int);
		if (ft_isdigit(*p->str))
			p->precision = ft_atoi(p->str);
	}
}

void	ft_setformat(t_printf *p, int nb)
{
	p->precision = 0;
	p->width = 0;
	p->zero_space = ' ';
	p->tab = ' ';
	p->dot = '0';
	while (!ft_isalpha(*p->str))
	{
		++p->str;
		if (*p->str == '-')
			p->tab = '-';
		if (*p->str == '0' && p->tab != '-' && p->width == 0)
			p->zero_space = '0';
		if (*p->str == '*')
		{
			nb = va_arg(p->ap, int);
			p->width = (nb < 0) ? (nb * -1) : nb;
			p->tab = (nb < 0) ? '-' : p->tab;
		}
		ft_setformat_(p);
		if (*p->str == '%')
			break ;
	}
}

void	ft_getformat(t_printf *p)
{
	if (p->type == 'd' || p->type == 'i')
		ft_print_di(p, va_arg(p->ap, int));
	if (p->type == 's')
		ft_print_str(p, va_arg(p->ap, char *));
	if (p->type == 'c')
		ft_print_char(p, va_arg(p->ap, int));
	if (p->type == 'u')
		ft_print_u(p, va_arg(p->ap, int));
	if (p->type == 'x')
		ft_print_x(p, va_arg(p->ap, unsigned int));
	if (p->type == 'X')
		ft_print_xup(p, va_arg(p->ap, unsigned int));
	if (p->type == 'p')
		ft_print_p(p, va_arg(p->ap, char *));
	if (p->type == '%')
		ft_print_char(p, 37);
}

void	ft_format_printf(t_printf *p)
{
	p->len_str = 0;
	while (*p->str)
	{
		if (*p->str == '%')
		{
			ft_setformat(p, 0);
			p->zero_space = (p->precision >= 0 && p->zero_space == '0'
							&& p->type == 'd') ? ' ' : p->zero_space;
			p->type = *p->str;
			ft_getformat(p);
		}
		else
			p->len_str += write(1, p->str, 1);
		++p->str;
	}
}

int		ft_printf(const char *str, ...)
{
	t_printf	pformat;

	pformat.str = (char *)str;
	va_start(pformat.ap, str);
	ft_format_printf(&pformat);
	va_end(pformat.ap);
	return (pformat.len_str);
}

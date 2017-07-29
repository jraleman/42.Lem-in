/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_printf.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/28 20:15:53 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/28 20:15:54 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		set_color(int c)

{

	ft_putstr("\033[");

	ft_putnbr(c);

	ft_putchar('m');

}



void		putcstr(char const *s, size_t col)

{

	set_color(col);

	ft_putstr(s);

	set_color(0);

}



void		ft_printfcolor(const char *format, ...)

{

	va_list p;

	char	*tmp;



	va_start(p, format);

	while (*format != '\0')

	{

		if (*format == '%')

		{

			if ((*(format + 1)) == 's')

				putcstr(va_arg(p, char*), va_arg(p, size_t));

			else if ((*(format + 1)) == 'd')

			{

				putcstr(tmp = ft_itoa(va_arg(p, int)), va_arg(p, size_t));

				ft_memdel((void**)&tmp);

			}

			format += 1;

		}

		else

			write(1, format, 1);

		format += 1;

	}

	va_end(p);

}


void		ft_printfbasic(const char *format, ...)

{

	va_list p;

	char	*str;



	va_start(p, format);

	while (*format != '\0')

	{

		if (*format == '%')

		{

			if ((*(format + 1)) == 's')

				ft_putstr(va_arg(p, char*));

			else if ((*(format + 1)) == 'd')

			{

				str = ft_itoa(va_arg(p, int));

				ft_putstr(str);

				ft_memdel((void**)&str);

			}

			format += 1;

		}

		else

			write(1, format, 1);

		format += 1;

	}

	va_end(p);

}

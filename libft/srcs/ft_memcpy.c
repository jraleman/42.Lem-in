/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 11:45:40 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/03/05 15:55:41 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d_str;
	const unsigned char	*s_str;

	d_str = (unsigned char *)dst;
	s_str = (const unsigned char *)src;
	while (n--)
		*d_str++ = *s_str++;
	return (dst);
}

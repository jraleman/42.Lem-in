/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrecfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 01:07:07 by jaleman           #+#    #+#             */
/*   Updated: 2017/07/27 01:07:07 by jaleman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_rec_free(t_list *first)
{
	if (first)
	{
		ft_lst_rec_free(first->next);
		free(first);
	}
}

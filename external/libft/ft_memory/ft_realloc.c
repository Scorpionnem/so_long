/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbatty <mbatty@student.42angouleme.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 09:24:29 by mbatty            #+#    #+#             */
/*   Updated: 2025/11/12 09:28:31 by mbatty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t ptr_size, size_t add_size)
{
	void	*res;
	int		min;

	if (ptr_size < 0 || ptr_size + add_size < 0)
		return (NULL);
	res = ft_calloc(ptr_size + add_size, 1);
	if (!res)
		return (NULL);
	if (ptr_size != 0)
	{
		min = ptr_size;
		if (add_size < 0)
			min = ptr_size + add_size;
		ft_memcpy(res, ptr, min);
	}
	free(ptr);
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:08:42 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/17 11:08:34 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*ptr;

	i = 0;
	ptr = NULL;
	ptr = malloc(size);
	if (ptr == NULL)
		return (NULL);
	else
	{
		ptr = ft_memset(ptr, 0, size);
		while (i < size)
		{
			ptr[i] = '\0';
			i++;
		}
	}
	return ((void *)ptr);
}

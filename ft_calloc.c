/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:40:48 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/21 09:47:14 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n > 0)
	{
		*ptr = 0;
		n--;
		ptr++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*space;

	space = malloc(count * size);
	if (space == NULL)
		return (NULL);
	ft_bzero(space, (count * size));
	return (space);
}

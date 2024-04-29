/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:37:24 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/28 11:40:38 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	check_all(char **strs)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (strs[i])
	{
		if (ft_checkouflow((char *)strs[i]) == 'b')
			return ('b');
		i++;
	}
	return ('g');
}

char	check_valid(char **strs)
{
	if (check_all(strs) == 'b')
		return ('b');
	return ('g');
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_all_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 17:59:55 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/31 12:15:07 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_all_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}

char	*join_all_strs(char **strs)
{
	int		i;
	char	*str;

	i = 1;
	str = malloc(1);
	if (!str)
		exit (1);
	str[0] = '\0';
	while (strs[i])
	{
		if (!ft_check_all_space(strs[i]))
			return (free(str), NULL);
		str = ft_strjoin(str, strs[i]);
		if (!str || !*str)
			return (free(str), NULL);
		if (strs[i + 1])
		{
			str = ft_strjoin(str, " ");
			if (!str)
				return (NULL);
		}
		i++;
	}
	return (str);
}

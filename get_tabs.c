/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tabs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:36:26 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/21 11:33:31 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strings2(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

int	*get_tabs(char **strs)
{
	int		i;
	char	*str;
	char	**numbers_strs;
	int		*tap;

	i = 0;
	str = join_all_strs(strs);
	if (!str)
		exit (1);
	numbers_strs = ft_split(str, ' ');
	if (!numbers_strs)
	{
		free(str);
		exit (1);
	}
	tap = convert_to_taps(numbers_strs);
	if (!tap)
	{
		free(str);
		free_strings2(numbers_strs);
		exit (1);
	}
	return (free(str), free_strings2(numbers_strs), tap);
}

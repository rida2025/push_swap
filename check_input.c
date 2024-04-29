/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:43:09 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/28 13:12:55 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_strings(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
		free(strs[i]);
	free(strs);
}

int	check_input(char **strs, int argc)
{
	int		check;
	char	*str;
	char	**numbers_strs;

	if (argc < 2)
		exit(0);
	check = 0;
	str = NULL;
	numbers_strs = NULL;
	str = join_all_strs(strs);
	if (!str)
		return (1);
	numbers_strs = ft_split(str, ' ');
	if (!numbers_strs)
		return (free(str), 1);
	if (check_allnumbers(numbers_strs) == 1)
		return (free_strings(numbers_strs), free(str), 1);
	check = last_check(numbers_strs);
	if (check == 0)
		return (free(str), free_strings(numbers_strs), 1);
	return (free(str), free_strings(numbers_strs), 0);
}

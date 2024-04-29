/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_allnumbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 14:25:26 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/28 13:14:16 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*1 mean error*/
int	check_number(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!(str[i] && (str[i] >= '0' && str[i] <= '9')))
		return (1);
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		i++;
	if (str[i] != '\0')
		return (1);
	return (0);
}

int	check_allnumbers(char **strs)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (strs[i])
	{
		if (check_number(strs[i]) == 0)
			i++;
		else
			return (1);
	}
	if (check_valid(strs) == 'b')
		return (1);
	return (0);
}

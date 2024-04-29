/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   last_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 13:01:28 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/27 12:40:09 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*create_tap(int *taps, char **strs, int numbers)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (i < numbers)
	{
		if (strs[i] == NULL)
		{
			free(taps);
			return (NULL);
		}
		taps[i] = ft_atoi(strs[i]);
		i++;
	}
	taps[i] = 0;
	return (taps);
}

int	*convert_to_taps(char **strs)
{
	int	*tabs;
	int	numbers;

	numbers = 0;
	while (strs[numbers])
		numbers++;
	tabs = (int *)malloc((numbers + 1) * sizeof(int));
	if (!tabs)
		exit (1);
	tabs = create_tap(tabs, strs, numbers);
	if (!tabs)
		exit (1);
	return (tabs);
}

char	ft_check_repeated(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] == tab[j] && i != j)
				return (free(tab), 'b');
			j++;
		}
		i++;
		j = 0;
	}
	return ('g');
}

int	last_check(char **strs)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	j = 0;
	tab = convert_to_taps(strs);
	while (strs[i])
	{
		while (strs[j])
		{
			if (!(ft_strcmp(strs[i], strs[j])) && i != j)
				return (free(tab), 0);
			j++;
		}
		i++;
		j = 0;
	}
	if (ft_check_repeated(tab, i) == 'b')
		return (0);
	return (free(tab), 1);
}

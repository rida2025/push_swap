/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utilits2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 12:27:34 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/21 11:39:17 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_btoa(t_stack **stacka, t_stack **stackb, t_stack *node_needed)
{
	while (node_needed->how_far != 0)
	{
		if (node_needed->how_far > 0)
			stack_rb(stackb, 0);
		else
			stack_rrb(stackb, 0);
	}
	stack_pa(stacka, stackb, 0);
}

int	find_nearest(t_stack *stack1, t_stack *stack2)
{
	int		i;
	int		j;

	i = stack1->how_far;
	if (!stack2)
		return (1);
	j = stack2->how_far;
	if (i < 0)
		i *= -1;
	if (j < 0)
		j *= -1;
	return (i < j);
}

int	get_size(char **strs)
{
	int		size;
	char	*str;
	char	**numbers_strs;

	size = 0;
	str = NULL;
	numbers_strs = NULL;
	str = join_all_strs(strs);
	if (!str)
		exit (1);
	numbers_strs = ft_split(str, ' ');
	if (!numbers_strs)
	{
		free(str);
		exit (1);
	}
	while (numbers_strs[size])
		size++;
	return (free(str), ft_freestrings(numbers_strs), free(numbers_strs), size);
}

int	stack_size(t_stack **stackA)
{
	t_stack	*tmp;
	int		i;

	tmp = *stackA;
	i = 0;
	while (tmp)
	{
		i++;
		tmp = tmp->rear;
	}
	return (i);
}

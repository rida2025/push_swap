/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:50:18 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/31 12:08:53 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_stack_sorted(t_stack **stacka, t_stack **stackb)
{
	t_stack	*tmp;

	tmp = *stacka;
	if (*stackb)
		return (1);
	while (tmp)
	{
		if (tmp->rear && tmp->value > tmp->rear->value)
			return (1);
		tmp = tmp->rear;
	}
	return (0);
}

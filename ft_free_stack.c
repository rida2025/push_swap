/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 11:31:41 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/21 10:26:49 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!*stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->rear;
		free(tmp);
	}
	free(*stack);
}

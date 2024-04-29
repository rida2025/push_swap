/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:44:33 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/31 13:27:26 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		size;
	int		*tabs;
	t_stack	*stacka;
	t_stack	*stackb;

	stacka = NULL;
	stackb = NULL;
	tabs = NULL;
	size = 1;
	if (check_input(argv, argc) == 1)
		return (write(2, "Error\n", 6), 0);
	tabs = get_tabs(argv);
	size = get_size(argv);
	init_stack(&stacka, tabs, size - 1);
	free(tabs);
	if (is_stack_sorted(&stacka, &stackb) == 0)
	{
		ft_free_stack(&stacka);
		exit(0);
	}
	ft_sort_stack(&stacka, &stackb);
	ft_free_stack(&stacka);
	return (0);
}

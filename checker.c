/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 16:15:22 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/31 12:09:31 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack **stacka, char **argv)
{
	int		*tabs;
	int		size;

	tabs = NULL;
	size = 0;
	tabs = get_tabs(argv);
	size = get_size(argv);
	init_stack(stacka, tabs, size - 1);
	free(tabs);
}

char	**get_operations(int fd)
{
	int		i;
	char	*line;
	char	*str;
	char	**operations;

	i = 0;
	line = NULL;
	str = NULL;
	operations = NULL;
	str = ft_strdup("");
	if (!str)
		exit (1);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		str = ft_strjoin(str, line);
		i++;
		free(line);
	}
	operations = ft_split(str, '\n');
	return (free(str), operations);
}

int	check_operations(char **strs)
{
	int	i;

	i = -1;
	while (strs[++i])
	{
		if (check_operation(strs[i]) == 0)
			return (1);
	}
	return (0);
}

void	sort_stack_withop(t_stack **stka, t_stack **stkb, char **ops, int i)
{
	while (ops[++i])
	{
		if (ft_strcmp(ops[i], "sa") == 0)
			stack_sa(stka, 2);
		else if (ft_strcmp(ops[i], "sb") == 0)
			stack_sb(stkb, 2);
		else if (ft_strcmp(ops[i], "ss") == 0)
			stack_ss(stka, stkb, 2);
		else if (ft_strcmp(ops[i], "pa") == 0)
			stack_pa(stka, stkb, 2);
		else if (ft_strcmp(ops[i], "pb") == 0)
			stack_pb(stka, stkb, 2);
		else if (ft_strcmp(ops[i], "ra") == 0)
			stack_ra(stka, 2);
		else if (ft_strcmp(ops[i], "rb") == 0)
			stack_rb(stkb, 2);
		else if (ft_strcmp(ops[i], "rr") == 0)
			stack_rr(stka, stkb, 2);
		else if (ft_strcmp(ops[i], "rra") == 0)
			stack_rra(stka, 2);
		else if (ft_strcmp(ops[i], "rrb") == 0)
			stack_rrb(stkb, 2);
		else if (ft_strcmp(ops[i], "rrr") == 0)
			stack_rrr(stka, stkb, 2);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stacka;
	t_stack	*stackb;
	char	**operations;

	stacka = NULL;
	stackb = NULL;
	operations = NULL;
	if (check_input(argv, argc) == 1)
		return (write(2, "Error\n", 6), 0);
	create_stack(&stacka, argv);
	operations = get_operations(0);
	if (!operations)
		return (ft_free_stack(&stacka), 0);
	if (check_operations(operations) == 1)
		return (ft_free_stack(&stacka), free_strings(operations), \
	write(2, "Error\n", 6), 0);
	sort_stack_withop(&stacka, &stackb, operations, -1);
	if (is_stack_sorted(&stacka, &stackb) == 1)
		return (free_strings(operations), ft_free_stack(&stacka), \
	ft_free_stack(&stackb), write(1, "KO\n", 3), 0);
	write(1, "OK\n", 3);
	return (ft_free_stack(&stacka), free_strings(operations), 0);
}

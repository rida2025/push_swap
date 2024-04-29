/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:16:21 by mel-jira          #+#    #+#             */
/*   Updated: 2023/12/31 11:32:37 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				value_index;
	int				stack_index;
	int				how_far;
	struct s_stack	*top;
	struct s_stack	*rear;
}	t_stack;

//======== parsing the input ========

int		check_input(char **strs, int argc);
int		get_size(char **strs);
char	*join_all_strs(char **strs);
char	**ft_split(char const *s, char c);
size_t	ft_strlen(const char *s);
int		check_allnumbers(char **strs);
int		last_check(char **strs);
char	check_valid(char **strs);
char	ft_checkouflow(char *str);
int		ft_atoi(char *str);
int		*convert_to_taps(char **strs);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		*get_tabs(char **strs);
int		*create_tap(int *taps, char **strs, int numbers);
char	*ft_strjoin(char const *s1, char const *s2);
int		stack_size(t_stack **stacka);
void	ft_freestrings(char **strs);
int		ft_strcmp(const char *s1, const char *s2);
char	*ft_strdup(char *str);
void	free_strings(char **strs);
void	*ft_calloc(size_t count, size_t size);
int		check_operation(char *strs);
//======== stack ========

void	init_stack(t_stack **stacka, int *tab, int size);
int		is_stack_sorted(t_stack **stacka, t_stack **stackb);
void	ft_sort_stack(t_stack **stacka, t_stack **stackb);
void	ft_free_stack(t_stack **stack);
//======== stack operation ========

void	stack_sa(t_stack **stacka, int signel);
void	stack_sb(t_stack **stackb, int signel);
void	stack_ss(t_stack **stacka, t_stack **stackb, int signel);
void	stack_pa(t_stack **stacka, t_stack **stackb, int signel);
void	stack_pb(t_stack **stacka, t_stack **stackb, int signel);
void	stack_ra(t_stack **stacka, int signel);
void	stack_rb(t_stack **stackb, int signel);
void	stack_rr(t_stack **stacka, t_stack **stackb, int signel);
void	stack_rra(t_stack **stacka, int signel);
void	stack_rrb(t_stack **stackb, int signel);
void	stack_rrr(t_stack **stacka, t_stack **stackb, int signel);
//======== stack operation helper ========

void	helper_pa1(t_stack **stacka, t_stack **stackb);
void	helper_pa2(t_stack **stacka, t_stack **stackb);
void	helper_pb1(t_stack **stacka, t_stack **stackb);
void	helper_pb2(t_stack **stacka, t_stack **stackb);

//======== sort utiltis ========

void	sort_value_index(t_stack **stack);
void	sort_stack_index(t_stack **stack);
void	sort_howfar(t_stack **stack, int size);
void	repair_stack(t_stack **stack);
//======== sort utiltis 2========

void	send_btoa(t_stack **stacka, t_stack **stackb, t_stack *node_needed);
int		find_nearest(t_stack *stack1, t_stack *stack2);
//======== sorting functions ========

void	sort_2(t_stack **stacka);
void	sort_3(t_stack **stacka);
void	sort_5(t_stack **stacka, t_stack **stackb, int size);
void	sort_100(t_stack **stacka, t_stack **stackb, int size);
void	sort_all(t_stack **stacka, t_stack **stackb, int size);

#endif
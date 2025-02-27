/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a-khairi <a-khairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 15:46:03 by a-khairi          #+#    #+#             */
/*   Updated: 2025/01/21 15:46:03 by a-khairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

typedef struct s_stack
{
	struct s_stack	*prev;
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_list
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*last_a;
	t_stack		*last_b;
	int			size_a;
	int			size_b;
}				t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Swap operations
void	sa(t_list *list, int print);
void	sb(t_list *list, int print);
void	ss(t_list *list, int print);

// Push operations
void	pa(t_list *list, int print);
void	pb(t_list *list, int print);

// Rotate operations
void	ra(t_list *list, int print);
void	rb(t_list *list, int print);
void	rr(t_list *list, int print);

// Reverse rotate operations
void	rra(t_list *list, int print);
void	rrb(t_list *list, int print);
void	rrr(t_list *list, int print);

// Utility functions check input
long	ft_atoi(char *str);
int		ft_isdigit(int c);
int		ft_isallspace(char *str);
int		ft_str_digit(char *s);
int		ft_check_dup(char **avgs);

// Check input
char	**ft_split(const char *str, char c);
int		check_len(int ac, char **av);
void	p_error(void);
void	free_av(char **avgs);
int		ft_size_av(char **avgs);
char	*cat_input(int ac, char **av);

// Sort utility
t_stack	*ft_lstnew(int data);
t_stack	*ft_lstlast(t_stack *stack);
void	ft_listadd_back(t_list *list, t_stack *new);
void	free_list(t_list *list);
void	setup_stack(t_list *list, char **av);

// Small sort
int		is_sorted(t_stack *stack_a);
void	sort_3_elements(t_list *list);
void	push_min_to_b(t_list *list, int pos, int len_stack);
void	sort_4_or_5(t_list *list);
void	sort_stack(t_list *list);

// Sort limit
int		find_max(t_stack *stack);
int		get_position(t_stack *stack, int target);
void	push_and_sorted(t_list *list);
void	sort_by_packet(t_list *list, int low_range, int high_range);

// Bonus
void	check_move(t_list *list, char *move);
void	ft_display(t_list *list);

char	*get_next_line(int fd);
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char *s, unsigned int start, size_t len);
void	execute_moves(t_list *list);

#endif

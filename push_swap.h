#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_moves
{
    int ra;
    int rb;
    int rr;
    int ra_rb_rr;
    int rra;
    int rrb;
    int rrr;
    int rra_rrb_rrr;
    int ra_rrb;
    int rb_rra;
} t_moves;


//utils functions
int     ft_fill_stack(int argc, char **argv, t_list **a);
void    ft_sort_3(t_list **list);
int     ft_sorting(t_list **a, t_list **b);
void    ft_push_b(t_list **a, t_list **b, int *min);
void    ft_push_a(t_list **a, t_list **b, t_moves *moves);
int     ft_count_move(t_list **a, t_list **b, t_list *elem, t_moves *moves);
t_list  *ft_select_el(t_list **a, t_list **b, t_moves *moves);

//commands functions
void    sa(t_list **a);
void    sb(t_list **b);
void    ss(t_list **a, t_list **b);
void    ra(t_list **a);
void    rb(t_list **b);
void    rr(t_list **a, t_list **b);
void    pa(t_list **a, t_list **b);
void    pb(t_list **b, t_list **a);
void    rra(t_list **a);
void    rrb(t_list **b);
void    rrr(t_list **a, t_list **b);







#endif


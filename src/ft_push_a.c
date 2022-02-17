#include "../push_swap.h"

static void     ft_processing_ra_rb_rr(t_list **a, t_list **b, t_moves *moves)
{
    while (moves->rr > 0)
    {
        rr(a, b);
        moves->ra--;
        moves->rb--;
        moves->rr--;
    }
    while (moves->ra > 0)
    {
        ra(a);
        moves->ra--;
    }
    while (moves->rb > 0)
    {
        rb(b);
        moves->rb--;
    }
}

static  void    ft_processing_rra_rrb_rrr(t_list **a, t_list **b, t_moves *moves)
{
    while (moves->rrr > 0)
    {
        moves->rra--;
        moves->rrb--;
        moves->rrr--;
        rrr(a, b);
    }
    while (moves->rra > 0)
    {
        rra(a);
        moves->rra--;
    }
    while (moves->rrb > 0)
    {
        rrb(b);
        moves->rrb--;
    }
}

static  void    ft_processing_ra_rrb(t_list **a, t_list **b, t_moves *moves)
{
    while (moves->ra > 0)
    {
        ra(a);
        moves->ra--;
    }
    while (moves->rrb > 0)
    {
        rrb(b);
        moves->rrb--;
    }
}

static  void    ft_processing_rb_rra(t_list **a, t_list **b, t_moves *moves)
{
    while (moves->rra > 0)
    {
        rra(a);
        moves->rra--;
    }
    while (moves->rb > 0)
    {
        rb(b);
        moves->rb--;
    }
}
void    ft_push_a(t_list **a, t_list **b, t_moves *moves)
{
    t_list *elem;
    int count;

    if (!*b)
        return ;
    elem = ft_select_el(a, b, moves);
    count = ft_count_move(a, b, elem, moves);
    if (moves->ra_rb_rr == count)
        ft_processing_ra_rb_rr(a, b, moves);
    else if (moves->rra_rrb_rrr == count)
        ft_processing_rra_rrb_rrr(a, b, moves);
    else if (moves->ra_rrb == count)
        ft_processing_ra_rrb(a, b, moves);
    else if (moves->rb_rra == count)
        ft_processing_rb_rra(a, b, moves);
    pa(a, b);
    ft_push_a(a, b, moves);
}
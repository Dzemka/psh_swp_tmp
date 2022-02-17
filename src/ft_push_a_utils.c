#include "../push_swap.h"

static int ft_count_rotate_a(t_list **a, int val)
{
    int     count_rotate;
    t_list  *elem;

    count_rotate = 1;
    elem = *a;
    while (elem->next)
    {
        if (val > *(int *)elem->content && val < *(int *)elem->next->content)
            break;
        count_rotate++;
        elem = elem->next;
    }
    return (count_rotate);
}

static  void    ft_init_moves(t_moves *moves)
{
    moves->ra = 0;
    moves->rb = 0;
    moves->rr = 0;
    moves->rra = 0;
    moves->rrb = 0;
    moves->rrr = 0;
    moves->ra_rrb = 0;
    moves->rb_rra = 0;
    moves->ra_rb_rr = 0;
    moves->rra_rrb_rrr = 0;
}

int ft_define_min_moves(t_moves *moves)
{
    int min;

    moves->ra_rrb = moves->ra + moves->rrb;
    moves->rb_rra = moves->rb + moves->rra;
    min = moves->ra;
    if (moves->rb < moves->ra)
        min = moves->rb;
    moves->rr = min;
    moves->ra_rb_rr = moves->ra + moves->rb - moves->rr;
    min = moves->rra;
    if (moves->rrb < min)
        min = moves->rrb;
    moves->rrr = min;
    moves->rra_rrb_rrr = moves->rra + moves->rrb - moves->rrr;
    min = moves->ra_rrb;
    if (moves->rb_rra < min)
        min = moves->rb_rra;
    if(moves->ra_rb_rr < min)
        min = moves->ra_rb_rr;
    if(moves->rra_rrb_rrr < min)
        min = moves->rra_rrb_rrr;
    return (min);
}

int ft_count_move(t_list **a, t_list **b, t_list *elem, t_moves *moves)
{
    int count;
    int size_b;
    int size_a;

    ft_init_moves(moves);
    size_b = ft_lstsize(*b);
    size_a = ft_lstsize(*a);
    moves->rb = size_b - ft_lstsize(elem);
    moves->rrb = size_b - moves->rb;
    if (size_b == 1)
        moves->rrb = 0;
    moves->ra = ft_count_rotate_a(a, *(int *)elem->content);
    moves->rra = size_a - moves->ra;
    count = ft_define_min_moves(moves);
    return (count);
}

t_list *ft_select_el(t_list **a, t_list **b, t_moves *moves)
{
    t_list *elem;
    t_list *min_elem;
    int count_move;
    int min_count;

    elem = *b;
    min_count = ft_count_move(a, b, elem, moves);
    min_elem = elem;
    elem = elem->next;
    while (elem)
    {
        count_move = ft_count_move(a, b, elem, moves);
        if (count_move < min_count)
        {
            min_count = count_move;
            min_elem = elem;
        }
        elem = elem->next;
    }
    return (min_elem);
}
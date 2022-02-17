#include "../push_swap.h"

void    ft_sort_3(t_list **list)
{
    int a;
    int b;
    int c;

    a = *(int *)(*list)->content;
    b = *(int *)(*list)->next->content;
    c = *(int *)(*list)->next->next->content;
    if ((a > b && b > c) || (b > c && c > a))
    {
        sa(list);
        ft_sort_3(list);
    }
    if (c > a && a > b)
            sa(list);
    if (a > c && c > b)
            ra(list);
    if (b > a && a > c)
            rra(list);
}

void    ft_final_sort(t_list **a, int min)
{
    t_list *elem;
    int size_a;
    int count_rotate;

    elem = *a;
    count_rotate = 0;
    size_a = ft_lstsize(*a);
    while (*(int *)elem->content != min)
    {
        count_rotate++;
        elem = elem->next;
    }
    if (size_a / 2 > count_rotate)
    {
        while (count_rotate--)
            ra(a);
    }
    else
    {
        count_rotate = size_a - count_rotate;
        while (count_rotate--)
            rra(a);
    }
}

int ft_sorting(t_list **a, t_list **b)
{
    t_moves *moves;
    int min;

    moves = (t_moves *)malloc(sizeof(t_moves));
    if(!moves)
        return (0);
    ft_push_b(a, b, &min);
    ft_sort_3(a);
    ft_push_a(a, b, moves);
    ft_final_sort(a, min);
    free(moves);
    return (1);
}


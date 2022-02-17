#include "../push_swap.h"

static int ft_check_sort(t_list *list)
{
    t_list  *elem;

    elem = list;
    while (elem->next)
    {
        if (*(int *)elem->content > *(int *)elem->next->content)
            return (0);
        elem = elem->next;
    }
    return (1);
}

static  void    ft_push_swap(t_list **a, t_list **b)
{
    int size;

    size = ft_lstsize(*a);
    if (size == 2)
        sa(a);
    else if (size == 3)
        ft_sort_3(a);
    else
        ft_sorting(a, b);
}

int main(int argc, char **argv)
{
    t_list  *a;
    t_list  *b;

    a = NULL;
    b = NULL;
    if(ft_fill_stack(argc, argv, &a))
    {
        if (ft_lstsize(a) > 1)
            if (!(ft_check_sort(a)))
               ft_push_swap(&a, &b);
    }
    else
        ft_putstr_fd("Error\n", 1);
    ft_lstclear(&a, free);
}
#include "../push_swap.h"

static  void    ft_define_border(t_list *a, int *min, int *med, int *max)
{
    int size;
    int temp_size;
    t_list *elem;
    t_list *temp;

    elem = a;
    size = ft_lstsize(a);
    while (elem)
    {
        temp_size = size;
        temp = a;
        while (temp)
        {
            if (*(int *)elem->content > *(int *)temp->content)
                temp_size--;
            temp = temp->next;
        }
        if (temp_size == size / 2 + 1)
            *med = *(int *)elem->content;
        if (temp_size == size)
            *min = *(int *)elem->content;
        if (temp_size == 1)
            *max = *(int *)elem->content;
        elem = elem->next;
    }
}

void    ft_push_b(t_list **a, t_list **b, int *min)
{
    int temp;
    int med;
    int max;
    int val;

    ft_define_border(*a, min, &med, &max);
    temp = ft_lstsize(*a);
    while (temp)
    {
        val = *(int *)(*a)->content;
        if(val == max || val == med || val == *min)
            ra(a);
        else
            pb(b, a);
        temp--;
    }
}
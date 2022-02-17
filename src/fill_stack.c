#include "../push_swap.h"

static int  ft_check_double(t_list *list, int n)
{
    t_list  *elem;

    elem = list;
    while (elem->next)
    {
        if (*(int *)elem->content == n)
            return (1);
        elem = elem->next;
    }
    return (0);
}

static int ft_check_errors(char *str)
{
    int i;
    int len_str;

    i = 0;
    len_str = ft_strlen(str);
    if (str[i] == '-')
        i++;
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (1);
        i++;
    }
    if (len_str >= 10)
    {
        if (len_str == 10)
            if(str[0] == '-' || ft_strncmp(str, "2147483647", 10) <= 0)
                return (0);
        if (len_str == 11)
            if (str[0] != '-' || ft_strncmp(str, "-2147483648", 11)  <= 0)
                return (0);
        return (1);
    }
    return (0);
}

static int  ft_get_val(char **values, t_list **list)
{
    t_list *el;
    int i;
    int *val;

    el = *list;
    i = 0;

    while(values[i])
    {
        val = (int *)malloc(sizeof (int *));
        if (!val)
            return (0);
        *val = ft_atoi(values[i]);
        el = ft_lstnew(val);
        ft_lstadd_back(list, el);
        if (!el || ft_check_double(*list, *val) || ft_check_errors(values[i]))
            return (0);
        i++;
    }
    return (1);
}
int ft_fill_stack(int argc, char **argv, t_list **a)
{
    int i;
    int s_index;
    char **values;
    int test;

    i = 1;
    test = 0;
    while(i < argc)
    {
        s_index = 0;
        values = ft_split(argv[i], ' ');
        if (!values)
            return (0);
        if(!ft_get_val(values, a))
            test = 1;
        while (values[s_index])
        {
            free(values[s_index]);
            s_index++;
        }
        free(values);
        if (test == 1)
            return (0);
        i++;
    }
    return (1);
}
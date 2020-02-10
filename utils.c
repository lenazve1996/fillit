/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 04:19:40 by ayajirob          #+#    #+#             */
/*   Updated: 2020/02/10 06:33:21 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void     del_arr(char **shape)
{
    int     i;

    i = 0;
    while(shape[i])
    {
        ft_strdel(&shape[i]);
        i++;
    }
    ft_strdel(shape);
    shape = NULL;
}

t_list          *list_del(t_list *list)
{
    
    t_tetra *tmp;
    t_list  *next;

    if(list == NULL)
        return (list);
    while(list)
    {
        next = list->next;
        tmp = list->content;
        del_arr(tmp->shape);
        ft_memdel((void*)&tmp);
        ft_memdel((void*)&list);
        list = next;
    }
    return(list);
}

void        set_letter(t_list *list)
{
    char    let;
    t_tetra *tmp;

    if(list == NULL)
        return;
    let = 'A';
    while(list)
    {
        tmp = list->content;
        tmp->letter = let;
        let++;
        list = list->next;
    }
}

void        del_dots(t_list *list)
{
    
}
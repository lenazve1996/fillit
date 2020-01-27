/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:09:24 by ayajirob          #+#    #+#             */
/*   Updated: 2020/01/27 16:39:14 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int main(int ac, char **av)
{
    int fd;
    if (ac != 2)
        {
            ft_putstr("usage: fillit [filename]");
        }
    else
    {
        if((fd = open(O_RDONLY, av[1])) > 0)
        {
            
        }
    }
    
    
    }
    int fd;
}

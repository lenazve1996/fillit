/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 01:48:11 by ayajirob          #+#    #+#             */
/*   Updated: 2020/02/10 06:36:51 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int     check_connection(char *buf)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while(buf[i])
    {
        if(buf[i] == '#')
        {
            if(i - 5 > 0 && buf[i - 5] == '#')
                n++;
            if(buf[i + 1] == '#')
                n++;
            if(i + 5 < 20 && buf[i + 5] == '#')
                n++;
            if(i - 1 > 0 && buf[i - 1] == '#')
                n++;
        }
        i++;
    }
    if(n == 6 || n == 8)
        return(1);
    else
        return(0);
}

int     check_buf(char  *buf)
{
    int i;
    int n;

    i = 0;
    n = 0;
    while(buf[i])
    {
        if(buf[i] == '#')
            n++;
        if(buf[i] != '#' && buf[i] != '.' && buf[i] != '\n' )
            return(0);
        if((i % 5 == 4 && buf[i] != '\n' && i != 0) || buf[20] != '\n')
            return(0);
        if(i % 5 != 4 && buf[i] == '\n' && i != 20)
            return(0);
        i++;
    }

    if(i != 21 & i != 20 & !check_connection(buf) || n != 4)
        return(0);
    return(1);
}
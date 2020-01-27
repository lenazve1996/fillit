/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:41:10 by ayajirob          #+#    #+#             */
/*   Updated: 2020/01/27 17:11:53 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tetr  *read_tetra(int fd)
{
    t_tetr  *head;
    t_tetr  *next;
    char    *buf;

    head = (t_tetr*)malloc(sizeof(t_tetr));
    
    if (!(buf = ft_strnew(BUFF_SIZE)))
            return(NULL);
    while (read(fd, buf, BUFF_SIZE))
        {
            head->tetra = ft_strsplit(buf, '\n');
        }

}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:10:05 by ayajirob          #+#    #+#             */
/*   Updated: 2020/02/10 06:36:53 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 21

typedef struct  s_tetra
{
    char        **shape;
    int         height;
    int         width;
    char        letter;
}               t_tetra;

t_list         *read_tetra(int fd);
int            check_buf(char  *buf);
t_list         *list_del(t_list *list);
void           set_letter(t_list *list);
#endif
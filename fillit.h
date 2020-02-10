/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:10:05 by ayajirob          #+#    #+#             */
/*   Updated: 2020/02/10 03:27:23 by ayajirob         ###   ########.fr       */
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
#endif
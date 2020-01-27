/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:10:05 by ayajirob          #+#    #+#             */
/*   Updated: 2020/01/27 17:11:57 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# define BUFF_SIZE 21
typedef struct s_tetr
{
    char            **tetra;
    int             wid;
    int             hei;
    char            val;
    struct  s_tetr  *next;
}              t_tetr;

t_tetr  *read_tetra(int fd);
#endif
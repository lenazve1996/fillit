/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayajirob <ayajirob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 16:41:10 by ayajirob          #+#    #+#             */
/*   Updated: 2020/02/10 06:36:54 by ayajirob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		print_contetn(t_tetra *shape)
{
	char	**line;
	int		i;

	i = 0;
	line = shape->shape;
	while (i < shape->height)
	{
		ft_putstr(line[i]);
		i++;
		ft_putchar('\n');
	}
	ft_putstr("Height: ");
	ft_putchar(shape->height + 48);
	ft_putstr(" weight: ");
	ft_putchar((char)shape->width + 48);
	ft_putstr(" value: ");
	ft_putchar(shape->letter);
	ft_putchar('\n');
	ft_putchar('\n');
}

void		str_up(t_tetra	*tetra)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = tetra->shape[i];
	while (tetra->shape[i])	
	{
		tetra->shape[i] = tetra->shape[i + 1];
		i++;
	}
	tetra->shape[i-1] = tmp;
}

int			check_col(t_tetra	*tetra)
{
	int		i;

	i = 0;
	while(tetra->shape[i])
	{
		if(tetra->shape[i][0] == '#')
			return(0);
		i++;
	}
	return(1);
}

void		move_col(t_tetra	*tetra)
{
	int		i;
	int		j;
	char	tmp;
	
	i = 0;
	while(tetra->shape[i])
	{
		j = 0;
		tmp = tetra->shape[i][j];
		while(tetra->shape[i][j])
		{
			tetra->shape[i][j] = tetra->shape[i][j + 1];
			j++;
		}
		i++;
	}
}	

void		move_shape(t_tetra	*tetra)
{
	while(!(ft_strrchr(tetra->shape[0], '#')))
		str_up(tetra);
	while(check_col(tetra))
		move_col(tetra);
}

void		get_size(t_tetra *tetra)
{
	int		i;
	int		j;

	i = 0;
	while(tetra->shape[i])
	{
		j = 0;
		while(tetra->shape[i][j])
		{
			if((tetra->shape[i][j] == '#') && (tetra->width < j + 1))
				tetra->width = j + 1;
			if((tetra->shape[i][j] == '#') && (tetra->height < i + 1))
				tetra->height = i + 1;
			j++;
		}
	i++;
	}
}

t_tetra		*create_tetra(char	*buf)
{
	t_tetra	*new_elem;
	
	if((new_elem = (t_tetra*)malloc(sizeof(t_tetra))))
	{
		new_elem->shape = ft_strsplit(buf, '\n');
		new_elem->height = 0;
		new_elem->width = 0;
		move_shape(new_elem);
		get_size(new_elem);
	}
	return(new_elem);
}

t_list		*read_tetra(int fd)
{
	t_list	*head;
	t_list	*next;
	char	*buf;
	
	head = NULL;
	if (!(buf = ft_strnew(BUFF_SIZE)))
			return(NULL);
	while (read(fd, buf, BUFF_SIZE))
	{
		if(!check_buf(buf))
		{
			head = list_del(head);
			ft_putstr("error");
			return(head);
		}
		if(head == NULL)
			head = ft_lstnew(create_tetra(buf), sizeof(t_tetra));
		else
			ft_lstpush_back(&head, ft_lstnew(create_tetra(buf), sizeof(t_tetra)));
	}
	set_letter(head);
	return(head);
}

int		main(int argc, char **argv)
{
	t_list	*list;

	if (argc != 2)
	{
		ft_putstr("usage: fillit input_file\n");
		return (1);
	}
	if ((list = read_tetra(open(argv[1], O_RDONLY))))
	{
		while(list)
		{
			print_contetn((t_tetra*)list->content);
			list = list->next;
		}
	}
	return (0);
}
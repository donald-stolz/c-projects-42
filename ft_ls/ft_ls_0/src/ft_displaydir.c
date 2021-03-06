/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_displaydir.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dstolz <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 09:47:58 by dstolz            #+#    #+#             */
/*   Updated: 2018/10/04 09:48:02 by dstolz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_ls.h"

char	*ft_parsetime(char *m_time)
{
	char	*new;
	int		i;

	i = 0;
	new = (char *)malloc(13);
	while (i < 12)
	{
		*(new + i) = *(m_time + (4 + i));
		i++;
	}
	*(new + i) = '\0';
	return (new);
}

void	ft_displayl(t_dir *dir)
{
	char *m_time;

	while (dir)
	{
		m_time = ft_parsetime(ctime(&dir->mtime.tv_sec));
		b_printf("%s %d %s %s %d %s %s\n", dir->permissions, dir->links,
				dir->owner, dir->group, dir->size, m_time, dir->name);
		free(m_time);
		dir = dir->next;
	}
}

void	ft_displayr(char *dirname)
{
	dirname[ft_strlen((const char *)dirname) - 1] = ':';
	b_printf("\n%s\n", dirname);
}

void	ft_displayfile(char *filepath, t_opt *options)
{
	t_dir	*file;
	char	*filename;
	char	*dirpath;
	size_t	i;

	i = ft_strlen(filepath);
	filename = ft_strrchr(filepath, '/');
	if (!options->l_op)
		return (b_printf("%s	", filepath));
	dirpath = ft_strnew(i);
	if (!filename)
	{
		filename = filepath;
		dirpath = ft_strcat(dirpath, "./");
	}
	else
		dirpath = ft_strncpy(dirpath, filepath, (i - ft_strlen(filename)));
	file = ft_getfile(dirpath, &i, filename, options);
	ft_displayl(file);
	free(dirpath);
}

void	ft_displaydir(t_dirlist *dir, t_opt *options, int i)
{
	t_dir	*nav;

	nav = dir->head;
	if (options->rec_op)
		if (i > 0 || options->m_arg)
			ft_displayr(dir->name);
	if (options->l_op)
	{
		b_printf("total %d\n", dir->total);
		return (ft_displayl(nav));
	}
	while (nav)
	{
		b_printf("%s    ", nav->name);
		nav = nav->next;
	}
	b_printf("\n");
}

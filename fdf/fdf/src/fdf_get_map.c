/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_get_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 17:00:28 by cbaldy            #+#    #+#             */
/*   Updated: 2016/01/27 17:56:27 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		fdf_nb_col(char *s, int *nb_col)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] < '0' && s[i] > '9' && s[i] != '-' && s[i] != ' ')
			return (-1);
		if (s[i] != ' ')
		{
			count++;
			while (s[i] != ' ' && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	if (*nb_col != 0 && count != *nb_col)
		return (-1);
	else if (*nb_col == 0)
		*nb_col = count;
	return (count);
}

static t_line	*fdf_read_map(int fd, int *line)
{
	int		ret;
	char	*buf;
	t_line	*tmp[3];

	tmp[1] = NULL;
	tmp[2] = NULL;
	*line = 0;
	while ((ret = get_next_line(fd, &buf)) > 0)
	{
		if ((tmp[0] = (t_line *)malloc(sizeof(t_line))) == NULL)
			return (NULL);
		if (tmp[2] == NULL)
			tmp[2] = tmp[0];
		tmp[0]->line = ft_strdup(buf);
		tmp[0]->next = NULL;
		if (tmp[1] != NULL)
			tmp[1]->next = tmp[0];
		tmp[1] = tmp[0];
		(*line)++;
	}
	return (tmp[2]);
}

static int		*fdf_build_line(char *s, int *first)
{
	int		col;
	int		*ligne;
	int		i;
	int		k;
	
	if ((col = fdf_nb_col(s, &(first[1]))) < 0)
		return (NULL);
	if ((ligne = (int *)malloc(sizeof(int) * col)) == NULL)
		return (NULL);
	i = 0;
	k = 0;
	while (s[i] != '\0' && k < col)
	{
		ligne[k] = ft_atoi(&(s[i]));
		if (ligne[k] < first[2])
			first[2] = ligne[k];
		if (ligne[k] > first[3])
			first[3] = ligne[k];
		while (s[i] != '\0' && s[i] != ' ')
			i++;
		while (s[i] == ' ')
			i++;
		k++;
	}
	return (ligne);
}

static int		**fdf_build_map(t_line *begin, int line)
{
	int		li;
	t_line	*tmp;
	int		**map;

	if ((map = (int **)malloc(sizeof(int *) * line + 1)) == NULL)
		return (NULL);
	if ((map[0] = (int *)malloc(sizeof(int) * 4)) == NULL)
		return (NULL);
	map[0][0] = line;
	map[0][1] = 0;
	map[0][2] = 0;
	map[0][3] = 0;
	li = 1;
	while (begin != NULL)
	{
		if ((map[li] = fdf_build_line(begin->line, map[0])) == NULL)
			return (NULL);
		li++;
		tmp = begin;
		begin = begin->next;
		free(tmp->line);
		free(tmp);
	}
	return (map);
}

int		**fdf_get_map(char *av)
{
	int		fd;
	int		line;
	t_line	*begin_line;

	if ((fd = open(av, O_RDONLY)) < 0)
	{
		perror("open file: ");
		return (NULL);
	}
	begin_line = fdf_read_map(fd, &line);
	if (close(fd) < 0)
	{
		perror("close file: ");
		return (NULL);
	}
	return (fdf_build_map(begin_line, line));
}

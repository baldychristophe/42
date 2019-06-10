/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 15:59:44 by cbaldy            #+#    #+#             */
/*   Updated: 2015/12/02 16:39:43 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*add_stock(char *stock, char *buf)
{
	int		i[2];

	i[0] = ft_strlen(stock);
	i[1] = 0;
	while (buf[i[1]] != '\0')
	{
		stock[i[0] + i[1]] = buf[i[1]];
		i[1]++;
	}
	stock[i[0] + i[1]] = '\0';
	return (stock);
}

char	*stock(char **input)
{
	int		fd;
	int		ret;
	char	buf[1001];
	char	*stock;

	fd = open(input[1], O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Open() error");
		return (NULL);
	}
	while ((ret = read(fd, buf, 1000)) != 0)
		buf[ret] = '\0';
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (NULL);
	}
	stock = malloc(1000);
	stock[0] = '\0';
	stock = add_stock(stock, buf);
	return (stock);
}

int		sqrt_fillit(int nb)
{
	int		i;

	i = 2;
	while ((i * i) < nb)
		i++;
	return (i);
}

int		**create_empty_sol(int size)
{
	int		i[2];
	int		**create;

	i[0] = 0;
	if ((create = (int **)malloc((size + 1) * sizeof(int *))) == NULL)
		return (NULL);
	while (i[0] <= size)
	{
		if ((create[i[0]] = malloc((size + 1) * sizeof(int))) == NULL)
			return (NULL);
		i[1] = 0;
		while (i[1] <= size)
		{
			if (i[0] == size || i[1] == size)
				create[i[0]][i[1]] = -1;
			else
				create[i[0]][i[1]] = 0;
			i[1]++;
		}
		i[0]++;
	}
	return (create);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:38:35 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/11 14:14:18 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*str;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	str = NULL;
	if (fd <= 2)
		return (0);
	while ((i = get_next_line(fd, &str)) > 0)
		printf("ret: %d, line: %s\n", i, str);
	printf("ret: %d, line: %s\n", i, str);
	return (0);

}

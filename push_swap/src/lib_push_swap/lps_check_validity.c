/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lps_check_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 10:03:54 by cbaldy            #+#    #+#             */
/*   Updated: 2016/11/13 18:41:28 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_push_swap.h"

static int	*lps_sort_pile(int *arr, int len)
{
	int i[3];

	if (arr == NULL)
		return (NULL);
	i[1] = 0;
	while (i[1] == 0)
	{
		i[1] = 1;
		i[0] = 0;
		while (i[0] < len - 1)
		{
			if (arr[i[0]] > arr[i[0] + 1])
			{
				i[1] = 0;
				i[2] = arr[i[0]];
				arr[i[0]] = arr[i[0] + 1];
				arr[i[0] + 1] = i[2];
			}
			i[0]++;
		}
	}
	return (arr);
}

static int	lps_is_doublon(char *str, int **dup, int index)
{
	int		i;
	int		nb;

	i = 0;
	nb = ft_atoi(str);
	while (i < index)
	{
		if ((*dup)[i] == nb)
			return (1);
		i++;
	}
	(*dup)[index] = nb;
	return (0);
}

static int	lps_is_valid_num(char *str)
{
	int		ret;
	char	*buf;
	char	*cleaned_str;

	buf = ft_itoa(ft_atoi(str));
	ret = 0;
	if (str[0] == '+')
		cleaned_str = &(str[1]);
	else
		cleaned_str = str;
	if (ft_strcmp(cleaned_str, buf) != 0)
		ret = 1;
	free(buf);
	return (ret);
}

int			*lps_check_validity(int argc, char **argv)
{
	int		i[2];
	int		*doub;

	i[0] = 0;
	i[1] = 0;
	if ((doub = (int *)malloc(sizeof(int) * (argc))) == NULL)
		return (NULL);
	while (i[0] < argc && i[1] == 0)
	{
		if (lps_is_valid_num(argv[i[0]]) == 1)
			i[1] = 1;
		if (lps_is_doublon(argv[i[0]], &doub, i[0]) == 1)
			i[1] = 1;
		i[0]++;
	}
	if (i[1] == 1)
	{
		free(doub);
		doub = NULL;
	}
	return (lps_sort_pile(doub, argc));
}

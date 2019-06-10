/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 12:55:25 by cbaldy            #+#    #+#             */
/*   Updated: 2016/02/16 18:51:37 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

t_builtin	g_list_builtin[] = {
	{"cd", &sh_builtin_cd},
	{"env", &sh_builtin_env},
	{"exit", &sh_builtin_exit},
	{"setenv", &sh_builtin_setenv},
	{"unsetenv", &sh_builtin_unsetenv},
};

static char	**sh_build_com(char *str)
{
	int		i;
	char	**com;
	char	*tmp;

	tmp = ft_strtrim(str);
	i = 0;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '\t')
			tmp[i] = ' ';
		i++;
	}
	if (tmp != NULL)
		free(tmp);
	com = ft_strsplit(tmp, ' ');
	return (com);
}

static int	sh_error_msg(char **com, int error)
{
	int		fd;

	fd = STDERR_FILENO;
	if (error == 2)
		ft_dprintf(STDIN_FILENO, "\n");
	if (error == 11)
		ft_dprintf(fd, "minishell: segmentation fault  %s\n", com[0]);
	return (0);
}

static int	sh_interpret(char *str)
{
	char	**com;
	int		i;

	com = sh_build_com(str);
	i = 0;
	while (i < 5 && com[0] != NULL)
	{
		if (ft_strncmp(com[0], g_list_builtin[i].name,
					ft_strlen(g_list_builtin[i].name)) == 0 &&
				com[0][ft_strlen(g_list_builtin[i].name)] == '\0')
			return (g_list_builtin[i].f(com));
		i++;
	}
	if (com[0] != NULL)
		i = sh_command(com);
	if (i != 0)
		sh_error_msg(com, i);
	ft_free_tab(com);
	return (0);
}

static int	sh_split_com(char *str)
{
	char	**split;
	int		i;

	split = ft_strsplit(str, ';');
	i = 0;
	while (split[i] != NULL)
	{
		if (sh_interpret(split[i]) < 0)
		{
			ft_free_tab(split);
			free(str);
			ft_free_tab(g_env);
			exit(0);
		}
		i++;
	}
	ft_free_tab(split);
	return (0);
}

void		sh_prompt(void)
{
	int		end;
	char	*str;

	ft_dprintf(STDIN_FILENO, "$>");
	signal(SIGINT, SIG_IGN);
	str = NULL;
	end = get_next_line(STDIN_FILENO, &str);
	if (str != NULL && ft_strlen(str) != 0)
		sh_split_com(str);
	else if (str == NULL)
		exit(1);
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	sh_prompt();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_taskmaster.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbaldy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 11:15:51 by dbaldy            #+#    #+#             */
/*   Updated: 2016/05/22 19:48:11 by cbaldy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	server_daemonize_client(void)
{
	int		pid;

	pid = fork();
	if (pid == 0)
	{
		//close(STDIN_FILENO);
		//close(STDOUT_FILENO);
		//close(STDERR_FILENO);
		//setsid();	NE PAS TOUCHER
		execve("./python_src/main.py", NULL, NULL);
		exit(1);
	}
	else if (pid > 0)
		return (0);
	ft_dprintf(STDERR_FILENO, "taskmaster: daemon failed\n");
	return (-1);
}

int 		server_init_socket(void) 
{
	struct sockaddr_un	addr;
	int 				tmp_fd;
	static int			fd;
	int					len;

	if (fd != 0)
		return (fd);
	unlink("./server");
	if ((tmp_fd = socket(AF_UNIX, SOCK_STREAM, 0)) == -1) 
		return (-1);
	addr.sun_family = AF_UNIX;
	strcpy(addr.sun_path, "./server");
	len = strlen(addr.sun_path) + sizeof(addr.sun_family) + 1;
	if (bind(tmp_fd, (struct sockaddr *)&addr, len) == -1) 
		return (-1);
	listen(tmp_fd, 5);
	if (server_daemonize_client() < 0)
		return (-1);
	fd = accept(tmp_fd, (struct sockaddr *)&addr, (socklen_t *)&len);
	return (fd);
}


static int	print_return(char *ret)
{
	char	**apps;
	int		i;

	apps = ft_strsplit(ret, ';');
	i = 2;
	if (ft_strcmp(apps[1], "exit") == 0)
		exit(4);
	else if (ft_strcmp(apps[1], "status") == 0)
		tm_status(apps + 2);
	else if (ft_strcmp(apps[1], "started") == 0 ||
			ft_strcmp(apps[1], "stopped") == 0)
		tm_start_stop(apps);
	return (0);
}

static int	server_manage_return(char *msg)
{
	char	*ret;
	char	*tmp;
	size_t	taille;
	int		size;
	int		fd;

	fd = server_init_socket();
	send(fd, msg, 1024, 0);
	taille = 0;
	while (taille == 0)// && ft_strstr(ret, "{eot}") == NULL)
	{
		tmp = ft_strnew(1024);
		taille = recv(fd, tmp, 1024, 0);
		size = ft_atoi(tmp);
		ret = ft_strsub(tmp, 0, size + ft_strchr(tmp, ';') + 1 - tmp);
		print_return(ret);
		if (ft_strstr(msg, "restart") != NULL)
		{
			taille = 0;
			msg = ft_strdup("");
		}
	}
	if (ft_strncmp(ft_strchr(ret, ';') + 1, "err", 3) == 0)
		ft_printf("error: %s\n", ft_strchr(ft_strchr(ret, ';') + 1, ';')
				+ 1);
	free(ret);
	return (0);
}

int			server_send_python(char *str)
{
	char	*size;
	char	*to_send;

	to_send = ft_strtrim(str);
	size = ft_itoa(ft_strlen(to_send));
	if (ft_strlen(to_send) > 1024)
	{
		ft_printf("taskmaster: command too long\n");
		return (1);
	}
	to_send = mod_strjoin(mod_strjoin(size, ";", 1), to_send, 3);
	server_manage_return(to_send);
	free(to_send);
	return (0);
}


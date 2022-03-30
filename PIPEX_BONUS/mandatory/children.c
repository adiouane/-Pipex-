/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   children.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:04:29 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/27 18:23:57 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	first_child(t_pipex pipex, char **argv, char **env)
{
	int	fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		error("no such file or directory", errno);
	if (dup2(fd, 0) == -1)
		error3("no such file or directory");
	if (dup2(pipex.fd_p[1], 1) == -1)
		error2(errno);
	pipex.cmd_arg = ft_split(argv[2], ' ');
	pipex.cmd = check_cmd(pipex.paths, pipex.cmd_arg[0]);
	if (pipex.cmd == NULL)
	{
		free_path_m(pipex.paths);
		error("pipex: command not found", 127);
	}
	close(pipex.fd_p[0]);
	close(pipex.fd_p[1]);
	close(fd);
	if (execve(pipex.cmd, pipex.cmd_arg, env) == -1)
		error2(errno);
}

void	second_child(t_pipex pipex, char **argv, char **env)
{
	int	fd;

	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		error("no such file or directory", errno);
	if (dup2(pipex.fd_p[0], 0) == -1)
		error2(errno);
	if (dup2(fd, 1) == -1)
		error3("no such file or directory");
	pipex.cmd_arg = ft_split(argv[3], ' ');
	pipex.cmd = check_cmd(pipex.paths, pipex.cmd_arg[0]);
	if (pipex.cmd == NULL)
	{
		free_path_m(pipex.paths);
		error("pipex: command not found", 127);
	}
	close(pipex.fd_p[0]);
	close(pipex.fd_p[1]);
	close(fd);
	if (execve(pipex.cmd, pipex.cmd_arg, env) == -1)
		error2(errno);
}

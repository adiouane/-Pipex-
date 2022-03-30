/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:04:34 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/26 22:37:36 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

char	**get_path(char **env)
{
	int	i;

	i = 0;
	while (env[i] && ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	if (!env[i])
		error("path does not exist", 1);
	else
		return (ft_split(env[i] + 5, ':'));
	return (NULL);
}

void	ft_pipex(t_pipex pipex, char **argv, char **env)
{
	pipex.paths = get_path(env);
	pipex.pid1 = fork();
	if (pipex.pid1 == -1)
		error("error in pid1\n", errno);
	if (pipex.pid1 == 0)
		first_child(pipex, argv, env);
	pipex.pid2 = fork();
	if (pipex.pid2 == -1)
		error("error in pid2\n", errno);
	if (pipex.pid2 == 0)
		second_child(pipex, argv, env);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	pipex;

	if (argc != 5)
		error("error arguments\n", errno);
	if (pipe(pipex.fd_p) < 0)
		error("error in pipe\n", errno);
	ft_pipex(pipex, argv, env);
	close(pipex.fd_p[0]);
	close(pipex.fd_p[1]);
	waitpid(pipex.pid1, NULL, 0);
	waitpid(pipex.pid2, NULL, 0);
	return (0);
}

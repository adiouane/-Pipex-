/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis_pipex_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 19:04:43 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/27 18:16:27 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	*check_cmd_b(char **path, char *cmd)
{
	char	*buff;
	char	*com2;

	if (ft_strchr(cmd, '/'))
		return (cmd);
	while (*path)
	{
		buff = ft_strjoin(*path, "/");
		com2 = ft_strjoin(buff, cmd);
		free(buff);
		if (access(com2, X_OK) == 0)
			return (com2);
		free(com2);
		path++;
	}
	return (NULL);
}

char	**get_path_b(char **env)
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

void	run_commmed(char *argv, char **env, t_bonus *bonus)
{
	bonus->paths = get_path_b(env);
	bonus->cmd_arg = ft_split(argv, ' ');
	bonus->cmd = check_cmd_b(bonus->paths, bonus->cmd_arg[0]);
	if (!bonus->cmd)
	{
		free_path(bonus->paths);
		error("pipex: command not found", 127);
	}
	if (execve(bonus->cmd, bonus->cmd_arg, env) == -1)
		error2(errno);
}

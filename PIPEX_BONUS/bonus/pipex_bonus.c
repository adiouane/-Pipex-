/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 13:01:58 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/26 15:35:06 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	pipex_b(t_bonus *bonus)
{
	if (dup2(bonus->infile, STDIN_FILENO) == -1)
		error3("no such file or directory");
	close(bonus->infile);
	while (bonus->cmd_n <= bonus->last_cmd)
	{
		child_process(bonus);
		bonus->cmd_n++;
	}
	while (wait(NULL) != -1)
		;
}

void	ft_here_doc(int argc, char **argv, char **env, t_bonus *bonus)
{
	bonus->cmd_n = 3;
	init_here_doc(argc, argv, env, bonus);
	here_doc(ft_strjoin(argv[2], "\n"), bonus);
	do_here_doc(bonus);
}

int	main(int argc, char **argv, char **env)
{
	t_bonus	bonus;

	if (argc >= 5)
	{
		if (argc >= 6 && ft_strncmp(argv[1], "here_doc", 9) == 0)
			ft_here_doc(argc, argv, env, &bonus);
		else
		{
			init_pipex(argc, argv, env, &bonus);
			pipex_b(&bonus);
		}
	}
	else
		error("Error\nToo few arguments!\n", errno);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 19:04:58 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/27 17:33:53 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	ft_process2(t_bonus *bonus)
{
	if (bonus->outfile == -1)
		error2(errno);
	if (dup2(bonus->outfile, STDOUT_FILENO) == -1)
		error2(errno);
	close(bonus->outfile);
	close(bonus->fd_p[0]);
	close(bonus->fd_p[1]);
	run_commmed(bonus->argv[bonus->cmd_n], bonus->env, bonus);
}

void	ft_process1(t_bonus *bonus)
{
	if (bonus->infile == -1)
		error("pipex: commend not found", 127);
	if (dup2(bonus->fd_p[1], STDOUT_FILENO) == -1)
		error2(errno);
	close(bonus->fd_p[0]);
	close(bonus->fd_p[1]);
	close(bonus->infile);
	run_commmed(bonus->argv[bonus->cmd_n], bonus->env, bonus);
}

void	child_process(t_bonus *bonus)
{
	if (pipe(bonus->fd_p) == -1)
		error("error pipe failed\n", 1);
	bonus->pid = fork();
	if (bonus->pid == -1 && bonus->cmd_n < bonus->last_cmd)
		error("error pid failed\n", 1);
	if (bonus->pid == 0 && bonus->cmd_n != bonus->last_cmd)
		ft_process1(bonus);
	else if (bonus->pid == 0 && bonus->cmd_n == bonus->last_cmd)
		ft_process2(bonus);
	else
	{
		if (dup2(bonus->fd_p[0], STDIN_FILENO) == -1)
			error2(errno);
		close(bonus->fd_p[1]);
		close(bonus->fd_p[0]);
	}
}

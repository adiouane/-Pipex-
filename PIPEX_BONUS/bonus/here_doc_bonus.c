/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 20:42:36 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/27 17:40:04 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "../inc/pipex.h"

void	ft_process_2(t_bonus *bonus)
{
	if (bonus->outfile == -1)
		error2(errno);
	if (dup2(bonus->outfile, STDOUT_FILENO) == -1)
		error2(errno);
	close(bonus->outfile);
	close(bonus->fd[0]);
	close(bonus->fd[1]);
	run_commmed(bonus->argv[bonus->cmd_n_h], bonus->env, bonus);
}

void	ft_process_1(t_bonus *bonus)
{
	if (dup2(bonus->fd[1], STDOUT_FILENO) == -1)
		error2(errno);
	close(bonus->fd[0]);
	close(bonus->fd[1]);
	run_commmed(bonus->argv[bonus->cmd_n_h], bonus->env, bonus);
}

void	child_process_heredoc(t_bonus *bonus)
{
	if (pipe(bonus->fd) == -1)
		error("error pipe failed\n", 1);
	bonus->pid = fork();
	if (bonus->pid == -1 && bonus->cmd_n_h < bonus->last_cmd_h)
		error("error pid failed\n", 1);
	if (bonus->pid == 0 && bonus->cmd_n_h != bonus->last_cmd_h)
		ft_process_1(bonus);
	else if (bonus->pid == 0 && bonus->cmd_n_h == bonus->last_cmd_h)
		ft_process_2(bonus);
	else
	{
		if (dup2(bonus->fd[0], STDIN_FILENO) == -1)
			error2(errno);
		close(bonus->fd[1]);
		close(bonus->fd[0]);
	}
}

void	do_here_doc(t_bonus *bonus)
{
	while (bonus->cmd_n_h <= bonus->last_cmd_h)
	{
		child_process_heredoc(bonus);
		bonus->cmd_n_h++;
	}
	while (wait(NULL) != -1)
		;
}

void	here_doc(char *limiter, t_bonus *bonus)
{
	char	*line;

	if (pipe(bonus->fd) == -1)
		error("pipe failed\n", errno);
	while (write(1, "heredoc>", 8), get_next_line(&line))
	{
		if (ft_strncmp(line, limiter, ft_strlen(limiter) + 1) == 0)
			break ;
		write(bonus->fd[1], line, ft_strlen(line));
	}
	free(limiter);
	if (dup2(bonus->fd[0], STDIN_FILENO) == -1)
		error2(errno);
	close(bonus->fd[1]);
	close(bonus->fd[0]);
	return ;
}

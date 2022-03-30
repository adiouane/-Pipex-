/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pipex_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 21:32:28 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/25 19:12:50 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

void	init_pipex(int argc, char **argv, char **envp, t_bonus *bonus)
{
	bonus->infile = open(argv[1], O_RDONLY);
	bonus->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	bonus->cmd_n = 2;
	bonus->argc = argc;
	bonus->argv = argv;
	bonus->env = envp;
	bonus->last_cmd = bonus->argc - 2;
}

void	init_here_doc(int argc, char **argv, char **envp, t_bonus *bonus)
{
	bonus->outfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
	bonus->cmd_n_h = 3;
	bonus->argc = argc;
	bonus->argv = argv;
	bonus->env = envp;
	bonus->last_cmd_h = bonus->argc - 2;
}

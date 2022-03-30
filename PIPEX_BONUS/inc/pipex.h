/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adiouane <adiouane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:31:50 by adiouane          #+#    #+#             */
/*   Updated: 2022/03/27 18:25:21 by adiouane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <sys/errno.h>

typedef struct s_pipex
{
	int		fd_p[2];
	char	**paths;
	char	*cmd;
	char	**cmd_arg;
	pid_t	pid1;
	pid_t	pid2;
}t_pipex;

typedef struct s_bonus
{
	int		argc;
	char	**argv;
	char	**env;
	pid_t	pid;
	int		infile;
	int		outfile;
	int		cmd_n;
	int		last_cmd;
	int		fd_p[2];
	int		fd[2];
	int		cmd_n_h;
	int		last_cmd_h;
	int		temp;
	char	**paths;
	char	*cmd;
	char	**cmd_arg;
}t_bonus;

char	*find_path_with_check(char *cmd, char **env);
void	ft_open_outfile(int argc, char **argv, t_bonus *bonus);
void	child_process_heredoc(t_bonus *bonus);
void	child_process(t_bonus *bonus);
int		get_next_line(char **line);
void	init_here_doc(int argc, char **argv, char **envp, t_bonus *bonus);
void	run_commmed(char *argv, char **env, t_bonus *bonus);
void	do_here_doc(t_bonus *bonus);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	init_pipex(int argc, char **argv, char **envp, t_bonus *bonus);
void	here_doc(char *limiter, t_bonus *bonus);
void	error(char *s, int status_code);
void	error2(int status_code);
char	**ft_split(char const *s, char c);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
void	*check_cmd(char **path, char *cmd);
void	first_child(t_pipex pipex, char **argv, char **env);
void	second_child(t_pipex pipex, char **argv, char **env);
size_t	ft_strlen(const char *s);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		get_next_line(char **line);
void	error3(char *s);
void	free_path(char **paths);
void	free_path_m(char **paths);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 13:01:30 by tiade-al          #+#    #+#             */
/*   Updated: 2024/11/29 19:54:54 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "Libft/libft.h"
# include <signal.h>
# include <fcntl.h>
# include <sys/wait.h>


typedef struct s_cmd
{
	char	*path; //stores the path to the command
	char	**arg; //used to store the command so if there is "ls -l" it stores as "ls" "-l" "NULL".
	int		fd[2]; // fd[0] is input / fd[1] the output of the pipe
	int		process_id; //stores de pid;
	int		process_nb; // stores the process nb
}	t_cmd;

//cleaners

void	free_cmd(t_cmd *cmd);
void	free_and_exit(t_cmd *cmd);
void	free_paths(char **paths);

//helpers

void	is_file_valid(char **argv);
int		here_doc_checker(char **argv);
char	**path_divider(char **envp);
int		safe_open(const char *file, int flags, int perms, t_cmd *cmd);
void	close_pipes(t_cmd *cmd, int total_pipes_amount);

//helpers2

void	file_assigner(t_cmd *cmd, char **argv, int argc, int here_doc);
void	path_joiner(t_cmd *cmd, char **paths, int i, int x);
void	pipes_closer(t_cmd *cmd, int limit);
void	error_msg(char *str, t_cmd *cmd);
void	proccess_cmd(t_cmd *cmd, char **envp, int i);

//doers

t_cmd	*command_alloc(int argc, char **argv);
t_cmd	*command_checker(int argc, char **argv, char **paths, int here_doc);
void	set_pipes(t_cmd *cmd);
void	child_creation(t_cmd *cmd, char **envp);
int		here_docker(t_cmd *cmd);


#endif
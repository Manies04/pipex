/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:06:26 by tiade-al          #+#    #+#             */
/*   Updated: 2024/12/02 00:09:52 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**@brief This function allocates and sets up (in the metadata) each name of the input/output files with an extra slot for the NULL.
 * Opens the necessary files (fd[0] for reading, fd[1] for writing).
 * Differentiates between normal and here-doc mode for file handling.
 * @param cmd The commands
 * @param **argv
 * @param argc
 * @param here_doc
 * @return void
 */
void	file_assigner(t_cmd *cmd, char **argv, int argc, int here_doc)
{
	cmd[0].arg = (char **)malloc(sizeof(char *) * 3);//allocating for 2 file names and the NULL
	if (!cmd[0].arg)
		free_and_exit(cmd);
	cmd[0].arg[0] = ft_strdup(argv[1]);//1st file to cmd[0].arg[0]
	if (!cmd[0].arg[0])
		free_and_exit(cmd);
	cmd[0].arg[1] = ft_strdup((argv[argc - 1]));//2nd file to cmd[0].arg[1]
	if (!cmd[0].arg[1])
		free_and_exit(cmd);
	cmd[0].arg[2] = NULL;////sets the last one to NULL cmd[0].arg[2]
	if (!here_doc)
	{
		cmd[0].fd[0] = safe_open(cmd[0].arg[0], O_RDONLY, 0, cmd);
		cmd[0].fd[1] = safe_open(cmd[0].arg[1], O_CREAT | O_WRONLY | O_TRUNC, 0644, cmd); /*	O_RDONLY: Open the file in read-only mode.
																								O_CREAT: Create the file if it doesn't exist.
																								O_WRONLY: Open the file in write-only mode.
																								O_TRUNC: Truncate the file to 0 bytes if it already exists (start fresh).*/
	}
	else
	{
		cmd[0].fd[0] = here_docker(cmd);
		cmd[0].fd[1] = safe_open(cmd[0].arg[1], O_CREAT | O_WRONLY | O_APPEND, 0644, cmd);
	}
}

/**@brief This function joins the paths with the command names.
 * If the command is an absolute path, it will be stored as is.
 * @param cmd The commands
 * @param **paths The list of paths to be used to execute the command.
 * @param i The index of the path.
 * @param x The index of the command.
 * @return void.
 */
void	path_joiner(t_cmd *cmd, char **paths, int i, int x)
{
	char	*temp;
    //    is NULL?         any argument?       is the first letter a '/'?
	if (cmd[x - 1].arg && cmd[x - 1].arg[0] && cmd[x - 1].arg[0][0] == '/')//if the command is an absolute path
	{
		cmd[x - 1].path = ft_strdup(cmd[x - 1].arg[0]);
		if (!cmd[x - 1].path)
			free_and_exit(cmd);
		return ;
	}

	temp = ft_strjoin(paths[i], "/");
	if (!temp)
		free_and_exit(cmd);
	cmd[x - 1].path = ft_strjoin(temp, cmd[x - 1].arg[0]);
	free(temp);

	if (!cmd[x - 1].path || access(cmd[x - 1].path, X_OK) != 0)// if the path is not found or not executable
	{
		if (cmd[x - 1].path)
			free(cmd[x - 1].path);
		cmd[x - 1].path = NULL;
	}
}

/**@brief This function closes the pipes.
 * @param cmd The commands
 * @param limit The limit of the pipes.
 * @return void.
 */
void	pipes_closer(t_cmd *cmd, int limit)
{
	int	i;

	i = -1;
	while (++i < limit)
	{
		close(cmd[i].fd[0]);
		close(cmd[i].fd[1]);
	}
}

/**@brief This function prints an error message if the command is not found.
 * @param *str The command that wasn't found.
 * @param cmd The commands
 * @return void.
 */
void	error_msg(char *str, t_cmd *cmd)
{
	char	*msg;

	msg = ft_strjoin(str, ": command not found\n");
	if (!msg)
	{
		pipes_closer(cmd, cmd[0].process_nb);
		free_and_exit(cmd);
	}
	write(2, msg, ft_strlen(msg));
	free(msg);
}

/**@brief This function executes the command given by the user.
 * @param cmd The commands
 * @param **envp The environment variables.
 * @param i The index of the command.
 * @return void.
 */
void	proccess_cmd(t_cmd *cmd, char **envp, int i)
{
	dup2(cmd[i - 1].fd[0], STDIN_FILENO);//read end of the pipe
	if (i == cmd[0].process_nb)// if it's the last command it will write to the write end of the pipe
		dup2(cmd[0].fd[1], STDOUT_FILENO);//write end of the pipe to the final file stored in cmd[0].arg[1]
	else
		dup2(cmd[i].fd[1], STDOUT_FILENO);//write end of the pipe to the next command
	pipes_closer(cmd, cmd[0].process_nb);
	execve(cmd[i].path, cmd[i].arg, envp);//executes the program for the command
}

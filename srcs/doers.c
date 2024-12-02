/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doers.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiade-al <tiade-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:08:10 by tiade-al          #+#    #+#             */
/*   Updated: 2024/12/02 00:18:41 by tiade-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pipex.h"

/**@brief This function creates as many t_cmd as needed to acomodate every 
 * comand + the metadata in t_cmd[0]
 * and also sets every command name into it's t_cmd.
 * @param argc: The number of arguments given to the main function.
 * @param **argv: The param given to the main function.
 * @param **path: The list of paths to be used to execute the command.
 * @param here_doc: The flag to check if here_doc is present.
 * @return t_cmd:
*/
t_cmd	*command_alloc(int argc, char **argv)
{
	t_cmd	*cmd;
	int		i;
	cmd = (t_cmd *)malloc(sizeof(t_cmd) * (argc - 2));// -2 so it takes out the 2 files. So we are left with the program name and with all the cmd. the prog name gives space for the metadata in t_cmd[0].
	if (!cmd)
	{
		perror("Error allocating memory for commands!");
		exit(0);
	}
	i = 0;
	while (++i < argc - 2)//i starts at 1 so it skips the first t_cmd(metadata), argc - 2 to skip arguments(file name) so it only gets the commands names on the cmd.arg.
	{
		cmd[i].arg = ft_split(argv[i + 1], ' ');//gives the names to each cmd[i]. argv[i + 1] so it skips the fist argv which is the file name.
		if (!cmd[i].arg)
			free_and_exit(cmd);
	}
	cmd[0].process_nb = argc - 3;//The amount of commands minus the 2 files and the program name.
	i = -1;
	while(++i <= cmd[0].process_nb)
		cmd[i].path = NULL;//initialize paths to NULL
	return(cmd);
}

/**@brief This function simulates a here-document input behavior.
 * @param cmd The commands
 * @return The read end of the pipe (fd[0])
 */
int	here_docker(t_cmd *cmd)
{
	char	*str;
	int		fd[2];

	if (pipe(fd) == -1)
		free_and_exit(cmd);
	while (1)//while limiter or EOF isn't reached
	{
		str = get_next_line(0);
		if (!str) // if it failed or reached EOF
			free_and_exit(cmd);
		if (ft_strncmp(cmd[0].arg[0], str, ft_strlen(cmd[0].arg[0])) == 0 \
		&& ft_strlen(cmd[0].arg[0]) == (ft_strlen(str) - 1))//cmd[0].arg[0] is the delimiter. str - 1 to ignore the '\n' at the end of the string.
			break ;
		ft_putstr_fd(str, fd[1]);//writes the string to the writing end of the pipe
		free(str);
	}
	free(str);
	close(fd[1]);//close writing end of pipe
	return(fd[0]);//send back read end of pipe
}

/**@brief This function assigns the files to the commands.
 * @param argc: The number of arguments given to the main function.
 * @param **argv: The param given to the main function.
 * @param **paths: The list of paths to be used to execute the command.
 * @param here_doc: The flag to check if here_doc is present.
 * @return cmd: The commands.
 */
t_cmd	*command_checker(int argc, char **argv, char **paths, int here_doc)
{
	t_cmd	*cmd;
	int		x;
	int		i;

	x = 1;
	cmd = command_alloc(argc, argv);
	file_assigner(cmd, argv, argc, here_doc);
	while (++x < argc - 1)
	{
		i = 0;
		while (paths && paths[i])
		{
			path_joiner(cmd, paths, i, x);
			if (access(cmd[x - 1].path, X_OK) == 0)
				break; //Path is valid, stop checking further paths
			else
				free(cmd[x - 1].path);
			i++;//Move to the next path in the PATH array
			if (paths[i] == NULL)
				cmd[x - 1].path = ft_strdup(cmd[x - 1].arg[0] + 1);//copies the arg name to the path indicating that it cannot be resolved into a path.
		}
	}
	free_paths(paths);
	return(cmd);
}

/**@brief This function opens cmd[0].process_nb - 1 pipes.
 * @param cmd: The commands.
 * @return void
 */
void	set_pipes(t_cmd *cmd)
{
	int	i;

	i = 0;
	while (++i < cmd[0].process_nb)//opens -1 pipes than the total amount of processes.
	{
		if (pipe(cmd[i].fd) == -1)//creates the pipes while it checks if the operation was succesful or not.
		{
			close_pipes(cmd, i);//closes the pipes until i - 1 because the current i pipe failed to be created.
			perror("Error");
			free_cmd(cmd);
			exit(0);
		}
	}
}

/**@brief This function creates the child processes by using fork.
 * @param cmd: The commands.
 * @param **envp: The environment variables.
 * @return void
 */
void	child_creation(t_cmd *cmd, char **envp)
{
	int	i;

	i = 0;
	while (++i <= cmd[0].process_nb)
	{
		cmd[i].process_id = fork();//creation of the child process
		if (cmd[i].process_id == -1)
			free_and_exit(cmd);
		if (cmd[i].process_id == 0)//if it's the child process
		{
			if (!cmd[i].path || access(cmd[i].path, X_OK) != 0)// if the path is not found or not executable
				error_msg(cmd[i].arg[0], cmd);
			else
				proccess_cmd(cmd, envp, i);//executes the command
			break ;//Stops the child from continuing the loop
		}
	}
	pipes_closer(cmd, cmd[0].process_nb);
	while (waitpid(-1, NULL, WUNTRACED) != -1)// waits for all the children to finish
		;
}
